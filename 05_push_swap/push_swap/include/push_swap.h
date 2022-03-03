/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:44:25 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/12 11:36:40 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "ft_printf.h"
# include <errno.h>

typedef struct s_value
{
	int		num;
	int		pos;
}				t_value;

typedef struct s_optim
{
	int		ra;
	int		rra;
	int		rb;
	int		rrb;
	int		best;
	char	op;
	int		nb;
}				t_optim;

typedef struct s_element
{
	int					num;
	int					index;
	struct s_element	*next;
	struct s_element	*prev;
}				t_element;

typedef struct s_stack
{
	t_element	*start;
	int			count;
	t_value		max[3];
	t_value		min;
}				t_stack;

typedef struct s_ps_block
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		argc;
	char	**argv;
	int		is_string;
	int		moves;
	int		*arr;
}				t_ps_block;

# define TRUE		1
# define FALSE		0
# define SUCCESS	1
# define ERROR		0
# define S_INTMAX	"2147483647"
# define S_INTMIN	"2147483648"

enum	e_exit_state
{
	E_NONE,
	E_NOARGS,
	E_FREE_A,
	E_FREE_BOTH,
	E_SUCCESS
};

enum	e_signs
{
	S_NONE,
	S_POS,
	S_NEG
};

enum	e_names
{
	N_NONE,
	N_STACK_A,
	N_STACK_B,
	N_BOTH
};

enum	e_operations
{
	OP_NONE,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR,
	OP_BOTH
};

int			add_element_to_stack(t_stack *stack, int num, int index);
int			calculate_chunk(t_ps_block *b);
void		calculate_ra(t_optim *optim, t_element **cur, t_ps_block *b);
void		calculate_rb(t_optim *optim, t_element *cur, t_ps_block *b);
void		check_arguments(t_ps_block *b);
int			check_elem_error(t_ps_block *b, t_stack *stack);
void		check_if_string(t_ps_block *b);
void		do_loop(int op, int num, t_ps_block *b);
void		exit_program(t_ps_block *b, int status, char *format, ...);
void		find_big_three(t_stack *stack);
t_value		find_max(t_stack *stack);
t_value		find_min(t_stack *stack);
t_optim		find_optimization(t_ps_block *b);
int			first_not_max(t_stack *stack);
void		free_block(char **argv);
void		free_program(t_ps_block *b, int status);
void		free_stack(t_stack *stack);
int			init_empty_stack(t_stack **stack);
void		bubble_sort(t_ps_block *b);
void		move_to_top(t_ps_block *b, int pos, int name);
void		operation_px(t_ps_block *b, int name);
void		operation_rrx(t_ps_block *b, int name);
void		operation_rx(t_ps_block *b, int name);
void		operation_sx(t_ps_block *b, int name);
void		optimize_operations(t_optim *optim);
t_ps_block	*prepare_block(int argc, char **argv);
void		prepare_stacks(t_ps_block *b);
void		print_block(t_ps_block *b);
void		print_stack(t_stack *stack);
void		ps_operations(t_ps_block *b, t_optim *optim);
void		push(t_stack *stack_a, t_stack *stack_b);
void		rb_max(t_optim *optim, t_ps_block *b);
void		relocate_args(t_ps_block *b);
void		remove_element_from_stack(t_stack *stack);
void		reverse_rotate(t_stack *stack);
void		rotate(t_stack *stack);
void		sort_few_elem(t_ps_block *b);
void		swap(t_stack *stack);

int			swap_instructions(char *line, t_ps_block *b);
int			push_instructions(char *line, t_ps_block *b);
int			rotate_instructions(char *line, t_ps_block *b);
int			reverse_rotate_instructions(char *line, t_ps_block *b);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:36:25 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/12 12:25:04 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	evaluate_five_hundred(t_ps_block *b)
{
	if (b->moves < 5500)
		ft_printf("<= 500 Args: Excelent. 5 Points");
	else if (b->moves < 7000)
		ft_printf("<= 500 Args: Very Good. 4 Points");
	else if (b->moves < 8500)
		ft_printf("<= 500 Args: Good. 3 Points");
	else if (b->moves < 10000)
		ft_printf("<= 500 Args: Acceptable. 2 Points");
	else if (b->moves < 11500)
		ft_printf("<= 500 Args: Weak. 1 Point");
	else
		ft_printf("ERROR\n. Too much moves needed. FAILED\n");
}

static void	print_moves_success(t_ps_block *b)
{
	if (b->argc > 50 && b->argc <= 100)
	{
		if (b->moves < 700)
			ft_printf("<= 100 Args: Excelent. 5 Points");
		else if (b->moves < 900)
			ft_printf("<= 100 Args: Very Good. 4 Points");
		else if (b->moves < 1100)
			ft_printf("<= 100 Args: Good. 3 Points");
		else if (b->moves < 1300)
			ft_printf("<= 100 Args: Acceptable. 2 Points");
		else if (b->moves < 1500)
			ft_printf("<= 100 Args: Weak. 1 Point");
		else
			ft_printf("ERROR\n. Too much moves needed. FAILED\n");
	}
	else if (b->argc > 101 && b->argc <= 500)
		evaluate_five_hundred(b);
}

static int	read_instructions(char *line, t_ps_block *b)
{
	if (swap_instructions(line, b) == TRUE)
		return (TRUE);
	else if (push_instructions(line, b) == TRUE)
		return (TRUE);
	else if (rotate_instructions(line, b) == TRUE)
		return (TRUE);
	else if (reverse_rotate_instructions(line, b) == TRUE)
		return (TRUE);
	else
		return (FALSE);
}

static void	checker(t_ps_block *b)
{
	char	*line;

	line = NULL;
	while (ft_get_next_line(0, &line) > 0)
	{
		if (read_instructions(line, b) == ERROR)
		{
			line = ft_memfree(line, NULL);
			exit_program(b, E_FREE_BOTH, "Found invalid instruction");
		}
		b->moves++;
		line = ft_memfree(line, NULL);
	}
	line = ft_memfree(line, NULL);
	if (check_elem_error(b, b->stack_a) == ERROR)
	{
		ft_printf("OK\n");
		print_moves_success(b);
	}
	else
		ft_printf("KO\n");
}

int	main(int argc, char **argv)
{
	t_ps_block	*b;

	b = prepare_block(argc, argv);
	if (argc == 0)
		exit_program(b, E_NOARGS, "");
	else if (argc == 2)
		check_if_string(b);
	else
		relocate_args(b);
	check_arguments(b);
	prepare_stacks(b);
	checker(b);
	exit_program(b, E_SUCCESS, "");
}

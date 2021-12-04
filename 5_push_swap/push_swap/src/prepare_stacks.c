/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 21:54:57 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/04 21:33:03 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_elem_error(t_ps_block *b, t_stack *stack)
{
	t_element	*node_a;
	t_element	*node_b;
	int			flag;

	flag = ERROR;
	if (!stack->start)
		exit_program(b, E_FREE_BOTH, "Stack is empty\n");
	node_a = stack->start;
	while (node_a)
	{
		node_b = node_a->next;
		while (node_b)
		{
			if (node_a->num == node_b->num)
				exit_program(b, E_FREE_BOTH, \
					"Please, avoid duplicated numbers: %i\n", node_a->num);
			if (node_a->num > node_b->num)
				flag = SUCCESS;
			node_b = node_b->next;
		}
		node_a = node_a->next;
	}
	return (flag);
}

void	prepare_stacks(t_ps_block *b)
{
	int	i;
	int	num;

	if (init_empty_stack(&(b->stack_a)) == ERROR)
		exit_program(b, E_NONE, \
			"Unable to allocate memory stack_a: %s\n", strerror(errno));
	i = b->argc - 1;
	while (i >= 0)
	{
		num = ft_atoi(b->argv[i]);
		if (add_element_to_stack(b->stack_a, num, 0) == ERROR)
			exit_program(b, E_FREE_A, \
				"Unable to allocate memory of element: %i\n", num);
		i--;
	}
	if (init_empty_stack(&(b->stack_b)) == ERROR)
		exit_program(b, E_NONE, \
			"Unable to allocate memory stack_b: %s\n", strerror(errno));
	if (check_elem_error(b, b->stack_a) == ERROR)
		exit_program(b, E_SUCCESS, "");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 00:54:31 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/05 20:25:55 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_to_top(t_ps_block *b, int pos, int name)
{
	int		i;
	t_stack	*stack;

	stack = b->stack_a;
	if (name == N_STACK_B)
		stack = b->stack_b;
	i = 1;
	if (pos > ((stack->count + 1) / 2))
	{
		while (i++ <= ((stack->count + 1) - pos))
			operation_rrx(b, name);
	}
	else
	{
		while (i++ < pos)
			operation_rx(b, name);
	}
}

t_value	find_min(t_stack *stack)
{
	t_element	*elem;
	t_value		min;
	t_value		num;

	elem = stack->start;
	min.num = INT_MAX;
	num.pos = 0;
	while (elem)
	{
		num.num = elem->num;
		num.pos++;
		if (num.num < min.num)
		{
			min.num = num.num;
			min.pos = num.pos;
		}
		elem = elem->next;
	}
	return (min);
}

t_value	find_max(t_stack *stack)
{
	t_element	*elem;
	t_value		max;
	t_value		num;

	elem = stack->start;
	max.num = 0;
	num.pos = 0;
	while (elem)
	{
		num.num = elem->index;
		num.pos++;
		if (num.num > max.num)
		{
			max.num = num.num;
			max.pos = num.pos;
		}
		elem = elem->next;
	}
	return (max);
}

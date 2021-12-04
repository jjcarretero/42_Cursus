/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 22:47:38 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/03 23:23:52 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_empty_stack(t_stack **stack)
{
	*stack = (t_stack *)malloc(sizeof(t_stack));
	if (*stack == NULL)
		return (ERROR);
	(*stack)->start = NULL;
	(*stack)->count = 0;
	(*stack)->min.num = INT_MAX;
	(*stack)->max[0].num = INT_MIN;
	(*stack)->max[1].num = INT_MIN;
	(*stack)->max[2].num = INT_MIN;
	return (SUCCESS);
}

void	remove_element_from_stack(t_stack *stack)
{
	t_element	*elem;

	elem = stack->start;
	stack->start = elem->next;
	free(elem);
	stack->count--;
}

static void	check_max_min(t_stack *stack, t_element *elem)
{
	if (stack->max[0].num < elem->num)
	{
		stack->max[2].num = stack->max[1].num;
		stack->max[1].num = stack->max[0].num;
		stack->max[0].num = elem->num;
	}
	else if (stack->max[1].num < elem->num)
	{
		stack->max[2].num = stack->max[1].num;
		stack->max[1].num = elem->num;
	}
	else if (stack->max[2].num < elem->num)
		stack->max[2].num = elem->num;
	if (stack->min.num > elem->num)
		stack->min.num = elem->num;
}

int	add_element_to_stack(t_stack *stack, int num, int index)
{
	t_element	*elem;

	elem = (t_element *)malloc(sizeof(t_element));
	if (elem == NULL)
		return (ERROR);
	elem->num = num;
	elem->index = index;
	elem->next = stack->start;
	stack->start = elem;
	stack->count += 1;
	check_max_min(stack, elem);
	return (SUCCESS);
}

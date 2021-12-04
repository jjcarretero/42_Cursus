/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 23:56:59 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/03 23:24:25 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *stack)
{
	t_element	*first;
	t_element	*second;

	if (stack->count < 2)
		return ;
	first = stack->start;
	second = stack->start->next;
	ft_swap_int(&(first->num), &(second->num));
}

void	push(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->count == 0)
		return ;
	add_element_to_stack(stack_a, stack_b->start->num, stack_b->start->index);
	remove_element_from_stack(stack_b);
}

void	rotate(t_stack *stack)
{
	t_element	*first;
	t_element	*last;

	if (stack->count < 2)
		return ;
	last = stack->start;
	while (last->next)
		last = last->next;
	first = stack->start;
	stack->start = stack->start->next;
	first->next = NULL;
	last->next = first;
}

void	reverse_rotate(t_stack *stack)
{
	t_element	*last;
	t_element	*end;

	if (stack->count < 2)
		return ;
	last = stack->start;
	while (last->next)
	{
		if (last->next->next == NULL)
			end = last;
		last = last->next;
	}
	end->next = NULL;
	last->next = stack->start;
	stack->start = last;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 22:11:56 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/03 22:40:55 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calculate_chunk(t_ps_block *b)
{
	int	chunk;

	chunk = 15;
	if (b->argc > 250)
		chunk *= 2;
	return (chunk);
}

int	first_not_max(t_stack *stack)
{
	t_element	*cur;
	int			ret;

	cur = stack->start;
	ret = 0;
	while (cur->num != stack->max[0].num)
	{
		cur = cur->next;
		ret++;
	}
	return (ret);
}

void	find_big_three(t_stack *stack)
{
	t_element	*elem;

	elem = stack->start;
	while (elem)
	{
		if (stack->max[0].num < elem->num)
			stack->max[0].num = elem->num;
		else if (stack->max[1].num < elem->num)
			stack->max[1].num = elem->num;
		else if (stack->max[2].num < elem->num)
			stack->max[2].num = elem->num;
		else if (stack->min.num > elem->num)
			stack->min.num = elem->num;
		elem = elem->next;
	}
}

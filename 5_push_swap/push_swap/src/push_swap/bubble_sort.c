/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 19:40:05 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/05 20:25:55 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reorder_stack_a(t_ps_block *b, int chunk)
{
	t_element	*elem;
	int			i;
	int			index;

	i = 0;
	elem = b->stack_a->start;
	while (elem)
	{
		index = elem->index;
		elem = elem->next;
		if (index <= i && i > 1)
		{
			operation_px(b, N_STACK_B);
			operation_rx(b, N_STACK_B);
			i++;
		}
		else if (index <= (i + chunk))
		{
			operation_px(b, N_STACK_B);
			i++;
		}
		else if (index >= i)
			operation_rx(b, N_STACK_A);
	}
}

static void	reorder_stack_b(t_ps_block *b)
{
	t_element	*elem;
	t_value		val;
	int			start;
	int			index;

	elem = b->stack_b->start;
	while (elem)
	{
		val = find_max(b->stack_b);
		start = FALSE;
		if (val.pos > b->stack_b->count / 2)
			start = TRUE;
		index = elem->index;
		elem = elem->next;
		if (index != val.num && start == FALSE)
			operation_rx(b, N_STACK_B);
		else if (index != val.num && start == TRUE)
		{
			operation_rrx(b, N_STACK_B);
			elem = b->stack_b->start;
		}
		else if (index == val.num)
			operation_px(b, N_STACK_A);
	}
}

static void	set_index(t_ps_block *b)
{
	t_element	*elem;
	int			pos;

	elem = b->stack_a->start;
	pos = 0;
	while (elem)
	{
		while (pos < b->argc)
		{
			if (b->arr[pos] == elem->num)
				elem->index = pos;
			pos++;
		}
		pos = 0;
		elem = elem->next;
	}
	b->arr = ft_memfree(b->arr, NULL);
}

void	bubble_sort(t_ps_block *b)
{
	int			chunk;

	chunk = calculate_chunk(b);
	set_index(b);
	reorder_stack_a(b, chunk);
	reorder_stack_b(b);
	return ;
}

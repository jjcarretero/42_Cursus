/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_few_elem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:50:15 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/12 17:35:24 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** IF (A > B > C)
**	SA & RRA;
** IF (A > C > B)
**	RA;
** IF (B > A > C)
**	RRA;
** IF (B > C > A)
**	RRA & SA;
** IF (C > A > B)
**	SA;
** IF (C > B > A)
**	Correct!
*/

static void	sort_three_elem_2(t_ps_block *b, int second, int third)
{
	if (second > third)
	{
		operation_sx(b, N_STACK_A);
		operation_rrx(b, N_STACK_A);
	}
	else
		operation_rx(b, N_STACK_A);
}

static void	sort_three_elem(t_ps_block *b)
{
	int	first;
	int	second;
	int	third;

	first = b->stack_a->start->num;
	second = b->stack_a->start->next->num;
	third = b->stack_a->start->next->next->num;
	if (third > second && second > first)
		return ;
	else if (third > second && third > first)
		operation_sx(b, N_STACK_A);
	else if (second > third && second > first)
	{
		operation_rrx(b, N_STACK_A);
		if (third > first)
			operation_sx(b, N_STACK_A);
	}
	else
		sort_three_elem_2(b, second, third);
}

/*
** IF (A > B)
**	SA;
*/

static void	sort_two_elem(t_ps_block *b)
{
	int	first;
	int	second;

	first = b->stack_a->start->num;
	second = b->stack_a->start->next->num;
	if (first > second)
		operation_sx(b, N_STACK_A);
}

static void	sort_little_elem(t_ps_block *b)
{
	int		i;
	t_value	min;

	i = 0;
	while (i < (b->argc - 2) - 1)
	{
		min = find_min(b->stack_a);
		move_to_top(b, min.pos, N_STACK_A);
		operation_px(b, N_STACK_B);
		i++;
	}
	sort_three_elem(b);
	while (i > 0)
	{
		operation_px(b, N_STACK_A);
		i--;
	}
}

void	sort_few_elem(t_ps_block *b)
{
	if (b->stack_a->count == 1)
		return ;
	if (b->stack_a->count == 2)
		sort_two_elem(b);
	else if (b->stack_a->count == 3)
		sort_three_elem(b);
	else
		sort_little_elem(b);
}

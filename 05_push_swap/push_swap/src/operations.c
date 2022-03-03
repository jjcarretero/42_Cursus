/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 23:39:31 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/05 20:25:59 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operation_sx(t_ps_block *b, int name)
{
	if (name == N_STACK_A)
	{
		swap(b->stack_a);
		ft_putstr_fd("sa\n", 1);
		b->moves++;
	}
	else if (name == N_STACK_B)
	{
		swap(b->stack_b);
		ft_putstr_fd("sb\n", 1);
		b->moves++;
	}
	else if (name == N_BOTH)
	{
		swap(b->stack_a);
		swap(b->stack_b);
		ft_putstr_fd("ss\n", 1);
		b->moves++;
	}
}

void	operation_px(t_ps_block *b, int name)
{
	if (name == N_STACK_A)
	{
		push(b->stack_a, b->stack_b);
		ft_putstr_fd("pa\n", 1);
		b->moves++;
	}
	else if (name == N_STACK_B)
	{
		push(b->stack_b, b->stack_a);
		ft_putstr_fd("pb\n", 1);
		b->moves++;
	}
}

void	operation_rx(t_ps_block *b, int name)
{
	if (name == N_STACK_A)
	{
		rotate(b->stack_a);
		ft_putstr_fd("ra\n", 1);
		b->moves++;
	}
	else if (name == N_STACK_B)
	{
		rotate(b->stack_b);
		ft_putstr_fd("rb\n", 1);
		b->moves++;
	}
	else if (name == N_BOTH)
	{
		rotate(b->stack_a);
		rotate(b->stack_b);
		ft_putstr_fd("rr\n", 1);
		b->moves++;
	}
}

void	operation_rrx(t_ps_block *b, int name)
{
	if (name == N_STACK_A)
	{
		reverse_rotate(b->stack_a);
		ft_putstr_fd("rra\n", 1);
		b->moves++;
	}
	else if (name == N_STACK_B)
	{
		reverse_rotate(b->stack_b);
		ft_putstr_fd("rrb\n", 1);
		b->moves++;
	}
	else if (name == N_BOTH)
	{
		reverse_rotate(b->stack_a);
		reverse_rotate(b->stack_b);
		ft_putstr_fd("rrr\n", 1);
		b->moves++;
	}
}

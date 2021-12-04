/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:42:25 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/04 22:32:30 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap_instructions(char *line, t_ps_block *b)
{
	if (line == NULL)
		return (ERROR);
	if (ft_strcmp(line, "sa\0") == 0)
	{
		swap(b->stack_a);
		return (SUCCESS);
	}
	else if (ft_strcmp(line, "sb\0") == 0)
	{
		swap(b->stack_b);
		return (SUCCESS);
	}
	else if (ft_strcmp(line, "ss\0") == 0)
	{
		swap(b->stack_a);
		swap(b->stack_b);
		return (SUCCESS);
	}
	return (ERROR);
}

int	push_instructions(char *line, t_ps_block *b)
{
	if (line == NULL)
		return (ERROR);
	if (ft_strcmp(line, "pa\0") == 0)
	{
		push(b->stack_a, b->stack_b);
		return (SUCCESS);
	}
	else if (ft_strcmp(line, "pb\0") == 0)
	{
		push(b->stack_b, b->stack_a);
		return (SUCCESS);
	}
	return (ERROR);
}

int	rotate_instructions(char *line, t_ps_block *b)
{
	if (line == NULL)
		return (ERROR);
	if (ft_strcmp(line, "ra\0") == 0)
	{
		rotate(b->stack_a);
		return (SUCCESS);
	}
	else if (ft_strcmp(line, "rb\0") == 0)
	{
		rotate(b->stack_b);
		return (SUCCESS);
	}
	else if (ft_strcmp(line, "rr\0") == 0)
	{
		rotate(b->stack_a);
		rotate(b->stack_b);
		return (SUCCESS);
	}
	return (ERROR);
}

int	reverse_rotate_instructions(char *line, t_ps_block *b)
{
	if (line == NULL)
		return (ERROR);
	if (ft_strcmp(line, "rra\0") == 0)
	{
		reverse_rotate(b->stack_a);
		return (SUCCESS);
	}
	else if (ft_strcmp(line, "rrb\0") == 0)
	{
		reverse_rotate(b->stack_b);
		return (SUCCESS);
	}
	else if (ft_strcmp(line, "rrr\0") == 0)
	{
		reverse_rotate(b->stack_a);
		reverse_rotate(b->stack_b);
		return (SUCCESS);
	}
	return (ERROR);
}

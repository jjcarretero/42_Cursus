/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 21:48:32 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/02 22:34:18 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_element	*element;

	if (stack == NULL)
		return ;
	element = stack->start;
	while (element)
	{
		ft_printf("%i\n", element->num);
		element = element->next;
	}
	ft_putchar_fd('\n', 1);
}

static void	print_values(t_ps_block *b)
{
	t_element	*element_a;
	t_element	*element_b;
	int			i;

	element_a = b->stack_a->start;
	element_b = b->stack_b->start;
	i = ft_max(b->stack_a->count, b->stack_b->count);
	while (i > 0)
	{
		if (element_a == NULL)
			printf("%-11s ", " ");
		else
		{
			printf("%-11i ", element_a->num);
			element_a = element_a->next;
		}
		if (element_b == NULL)
			printf("%-11s\n", " ");
		else
		{
			printf("%-11i\n", element_b->num);
			element_b = element_b->next;
		}
		i--;
	}
}

void	print_block(t_ps_block *b)
{
	if (b->stack_a == NULL || b->stack_b == NULL)
		return ;
	ft_printf("--------------------------------------------------\n");
	print_values(b);
	ft_printf("----------- -----------\na           b\n");
	ft_printf("--------------------------------------------------\n");
	ft_printf("Number of moves: %i\n", b->moves);
	ft_printf("--------------------------------------------------\n");
}

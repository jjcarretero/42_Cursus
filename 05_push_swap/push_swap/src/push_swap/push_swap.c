/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 22:23:40 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/12 13:17:51 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*create_array(t_ps_block *b)
{
	int	*arr;
	int	i;
	int	j;

	i = 0;
	arr = ft_calloc(b->argc, sizeof(int));
	while (i < b->argc)
	{
		arr[i] = ft_atoi(b->argv[i]);
		i++;
	}
	i = 0;
	while (i < b->argc - 1)
	{
		j = 0;
		while (j < b->argc - i - 1)
		{
			if (arr[j] > arr[j + 1])
				ft_swap(&arr[j], &arr[j + 1], sizeof(int));
			j++;
		}
		i++;
	}
	return (arr);
}

static void	push_swap(t_ps_block *b)
{
	if (b->stack_a->count <= 50)
		sort_few_elem(b);
	else
	{
		b->arr = create_array(b);
		bubble_sort(b);
	}
	return ;
}

int	main(int argc, char **argv)
{
	t_ps_block	*b;

	b = prepare_block(argc, argv);
	if (argc < 2)
		exit_program(b, E_NOARGS, "");
	else if (argc == 2)
		check_if_string(b);
	else
		relocate_args(b);
	check_arguments(b);
	prepare_stacks(b);
	push_swap(b);
	exit_program(b, E_SUCCESS, "");
}

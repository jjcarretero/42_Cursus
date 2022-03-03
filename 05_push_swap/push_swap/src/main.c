/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 23:00:14 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/02 23:32:28 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_ps_block	*prepare_block(int argc, char **argv)
{
	t_ps_block	*ret;

	ret = (t_ps_block *)malloc(sizeof(t_ps_block));
	if (ret == NULL)
		exit_program(ret, E_NONE, \
			"Unable to allocate memory: %s\n", strerror(errno));
	ret->argc = argc;
	ret->argv = argv;
	ret->is_string = FALSE;
	ret->moves = 0;
	return (ret);
}

void	check_if_string(t_ps_block *b)
{
	b->argv = ft_split(b->argv[1], ' ');
	if (b->argv == NULL)
		exit_program(b, E_NONE, "Arg Split Error");
	b->argc = ft_strcount(b->argv);
	b->is_string = TRUE;
}

void	relocate_args(t_ps_block *b)
{
	int	i;

	i = 0;
	while (i < (b->argc - 1))
	{
		(b->argv)[i] = b->argv[i + 1];
		i++;
	}
	b->argv[i] = 0;
	b->argc--;
}

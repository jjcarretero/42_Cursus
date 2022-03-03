/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:18:27 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/05 12:13:36 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_char_array(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		arr[i] = ft_memfree(arr[i], NULL);
		i++;
	}
	arr = ft_memfree(arr, NULL);
}

void	*free_bst(t_bst *bst)
{
	if (bst->tree != NULL)
	{
		ast_delete(&(bst->tree));
		bst->tree = NULL;
	}
	if (bst->child)
		free_bst(bst->child);
	if (bst->next)
		free_bst(bst->next);
	return (ft_memfree(bst, NULL));
}

void	free_program(t_minishell *shell, int status)
{
	if (status >= F_SHELL)
	{
		if (shell->line != NULL)
			shell->line = ft_memfree(shell->line, NULL);
		if (shell->path != NULL)
			shell->path = ft_memfree(shell->path, NULL);
		if (shell->envp_dup != NULL)
			free_char_array(shell->envp_dup, ft_str_arr_count(shell->envp_dup));
		if (shell->bst != NULL)
			free_bst(shell->bst);
		tok_delete(&((shell->lexer).list_token));
		close(shell->std.in);
		close(shell->std.out);
		shell = ft_memfree(shell, NULL);
	}
}

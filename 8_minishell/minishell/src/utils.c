/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:19:07 by jcarrete          #+#    #+#             */
/*   Updated: 2021/12/06 20:38:21 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_minishell	*get_minishell(t_minishell *minishell)
{
	static t_minishell	*shell = NULL;

	if (!shell && minishell)
		shell = minishell;
	return (shell);
}

void	do_nothing(void *vd)
{
	(void)vd;
	return ;
}

void	*return_null(char *ptr)
{
	ptr = ft_memfree(ptr, NULL);
	return (NULL);
}

char	*find_value(char **envp, char *key)
{
	char	*find;
	int		len;

	while (*envp)
	{
		find = read_key(*envp);
		len = ft_strlen(find);
		if (!ft_strcmp(find, key))
		{
			find = ft_memfree(find, NULL);
			return (ft_substr(*envp, len + 1, ft_strlen(*envp)));
		}
		find = ft_memfree(find, NULL);
		envp++;
	}
	return (NULL);
}

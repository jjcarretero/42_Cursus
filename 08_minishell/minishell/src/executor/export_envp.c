/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_envp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:10:20 by jcarrete          #+#    #+#             */
/*   Updated: 2022/01/16 13:01:25 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*read_key(char *var)
{
	int	len;

	len = 0;
	while (var[len] && var[len] != '=')
		len++;
	if (len > 0)
		return (ft_substr(var, 0, len));
	return (NULL);
}

static int	check_ignore(char *envp, char *ignore)
{
	char	*key;

	key = read_key(envp);
	if (ignore)
	{
		if (!ft_strcmp(key, ignore))
		{
			key = ft_memfree(key, NULL);
			return (TRUE);
		}
	}
	key = ft_memfree(key, NULL);
	return (FALSE);
}

char	*find_variable(char **envp, char *arg, int *no_del)
{
	int		len;
	char	*find;
	char	*key;

	len = 0;
	while (arg[len] && arg[len] != '=')
		len++;
	find = ft_substr(arg, 0, len);
	while (*envp)
	{
		key = read_key(*envp);
		if (!ft_strcmp(key, find))
		{
			if (!((*envp)[len] == '=' && !arg[len] && no_del))
				return (ft_memfree(find, key));
			if (no_del)
				*no_del = 1;
		}
		key = ft_memfree(key, NULL);
		envp++;
	}
	find = ft_memfree(find, NULL);
	return (ft_memfree(key, NULL));
}

char	**ft_envdup(char **envp, int len, int add, char *ignore)
{
	char	**res;
	int		i;
	int		j;

	res = ft_memalloc(sizeof(char *) * (len + add));
	if (res == NULL)
		exit_program(NULL, 0, E_MEM, strerror(errno));
	i = 0;
	j = 0;
	while (i < len)
	{
		if (envp[i] && ft_strcmp(envp[i], "") && !check_ignore(envp[i], ignore))
		{
			res[j] = ft_strdup(envp[i]);
			j++;
		}
		i++;
	}
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:54:34 by rpunet            #+#    #+#             */
/*   Updated: 2022/02/04 21:14:45 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	double_len(char **arr)
{
	int	i;

	i = 0;
	if (!*arr || !arr)
		return (0);
	while (arr[i])
		i++;
	return (i);
}

int	check_builtins(char **args, char **envp)
{
	t_minishell	*shell;

	shell = get_minishell(NULL);
	if (!ft_strcmp(args[0], "env"))
	{
		while (*envp)
		{
			ft_putstr_fd(*envp, shell->std.out);
			ft_putchar_fd('\n', shell->std.out);
			envp++;
		}
		return (TRUE);
	}
	else if (!ft_strcmp(args[0], "echo"))
		ft_echo(args, &envp);
	else if (!ft_strcmp(args[0], "pwd"))
		ft_pwd(args, &envp);
	return (FALSE);
}

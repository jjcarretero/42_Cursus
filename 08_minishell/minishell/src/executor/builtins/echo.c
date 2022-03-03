/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:47:08 by jcarrete          #+#    #+#             */
/*   Updated: 2022/01/16 12:09:57 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **args, char ***envp)
{
	int			i;
	t_minishell	*shell;

	shell = get_minishell(NULL);
	shell->exit_code = EXIT_SUCCESS;
	do_nothing(envp);
	if (!args[1])
		write(STDOUT_FILENO, "\n", 1);
	else
	{
		i = 1;
		while (args[i] && !ft_strncmp(args[i], "-n", 2))
			i++;
		while (args[i])
		{
			ft_putstr_fd(args[i], STDOUT_FILENO);
			if (args[i + 1])
				write(STDOUT_FILENO, " ", 1);
			i++;
		}
		if (ft_strncmp(args[1], "-n", 2))
			write(STDOUT_FILENO, "\n", 1);
	}
	return (shell->exit_code);
}

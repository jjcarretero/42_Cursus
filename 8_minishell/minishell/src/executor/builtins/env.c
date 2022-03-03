/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 12:35:13 by jcarrete          #+#    #+#             */
/*   Updated: 2022/01/16 12:53:43 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_env(char **envp)
{
	int	i;

	if (!envp)
		return ;
	i = 0;
	while (envp[i])
	{
		ft_putstr_fd(envp[i], STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

int	ft_env(char **args, char ***envp)
{
	t_minishell	*shell;

	shell = get_minishell(NULL);
	if (ft_str_arr_count(args) > 1)
	{
		ft_putstr_fd("env: please use env without arguments\n", STDERR_FILENO);
		shell->exit_code = EB_MISUSE_BUILTINS;
		return (shell->exit_code);
	}
	print_env(*envp);
	return (EXIT_SUCCESS);
}

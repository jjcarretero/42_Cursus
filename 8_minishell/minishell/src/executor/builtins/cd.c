/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:48:44 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/05 00:35:24 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_pwd(char ***envp)
{
	char	*find;
	char	*save;
	char	*dir;

	find = find_variable(*envp, "OLDPWD", NULL);
	delete_var(envp, find);
	save = find_value(*envp, "PWD");
	dir = ft_strjoin("OLDPWD=", save);
	add_single_exp(envp, dir);
	find = ft_memfree(find, find_variable(*envp, "PWD", NULL));
	delete_var(envp, find);
	save = ft_memfree(save, getcwd(NULL, 0));
	dir = ft_memfree(dir, ft_strjoin("PWD=", save));
	add_single_exp(envp, dir);
	find = ft_memfree(find, NULL);
	save = ft_memfree(save, NULL);
	dir = ft_memfree(dir, NULL);
}

void	change_dir(t_minishell *shell, char **args, char ***envp)
{
	char	*home;

	if (args[1] == NULL)
	{
		home = find_value(*envp, "HOME");
		if (chdir(home) == -1)
		{
			shell->exit_code = EXIT_FAILURE;
			ft_putstr_fd("MINIshell: cd: HOME not set\n", \
				STDOUT_FILENO);
		}
		else
			change_pwd(envp);
		home = ft_memfree(home, NULL);
	}
	else if (chdir(args[1]) == -1)
	{
		shell->exit_code = EXIT_FAILURE;
		ft_putstr_fd("MINIshell: cd: No such file or directory\n", \
			STDOUT_FILENO);
	}
	else
		change_pwd(envp);
}

int	ft_cd(char **args, char ***envp)
{
	t_minishell	*shell;

	shell = get_minishell(NULL);
	shell->exit_code = EXIT_SUCCESS;
	if (double_len(args) <= 2)
		change_dir(shell, args, envp);
	else
	{
		shell->exit_code = EXIT_FAILURE;
		ft_putstr_fd("MINIshell: cd: too many arguments\n", \
			STDOUT_FILENO);
	}
	return (shell->exit_code);
}

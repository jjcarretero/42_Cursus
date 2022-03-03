/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 22:19:53 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/04 21:25:09 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*set_command_path(t_exec *exec)
{
	char	*ret;
	DIR		*dir;

	if (ft_strchr(exec->args[0], '/') == NULL)
		ret = find_directory(&dir, exec->args);
	else
	{
		ret = ft_strdup(exec->args[0]);
		if (access(ret, X_OK) != 0)
			ret = ft_memfree(ret, NULL);
	}
	return (ret);
}

int	exec_process(char **args, char **envp, int i)
{
	t_minishell	*shell;

	shell = get_minishell(NULL);
	if (shell->path == NULL)
	{
		if (ft_iteris(args[0], &ft_isspace))
		{
			shell->exit_code = EXIT_SUCCESS;
			return (EXIT_SUCCESS);
		}
		if (!ft_strcmp(args[0], "$?"))
			ft_putnbr_fd(shell->exit_code, STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd(": Command not found\n", STDERR_FILENO);
		shell->exit_code = EB_COMMAND_NOT_FOUND;
		free_char_array(args, i);
		exit_program(NULL, 0, 0, "");
	}
	return (execve(shell->path, args, envp));
}

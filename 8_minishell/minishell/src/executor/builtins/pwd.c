/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:47:59 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/04 21:00:49 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char **args, char ***envp)
{
	char		*ret;
	t_minishell	*shell;

	shell = get_minishell(NULL);
	shell->exit_code = EXIT_SUCCESS;
	do_nothing(envp);
	ret = getcwd(NULL, 0);
	if (ret)
	{
		ft_putstr_fd(ret, STDOUT_FILENO);
		write(STDOUT_FILENO, "\n", 1);
		ret = ft_memfree(ret, NULL);
	}
	else
	{
		shell->exit_code = EXIT_FAILURE;
		ft_putstr_fd("MINIshell: ", STDERR_FILENO);
		ft_putstr_fd(args[0], STDERR_FILENO);
		ft_putstr_fd(" failed: ", STDERR_FILENO);
		ft_putstr_fd(strerror(errno), STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	return (shell->exit_code);
}

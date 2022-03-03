/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:09:26 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/05 00:27:38 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_exit(char **argv)
{
	t_minishell	*shell;

	shell = get_minishell(NULL);
	ft_putstr_fd("exit\n", STDOUT_FILENO);
	if (ft_str_arr_count(argv) == 2)
	{
		if (ft_is_number(argv[1]) == FALSE)
		{
			ft_putstr_fd("MINIshell: exit: ", STDOUT_FILENO);
			ft_putstr_fd(argv[1], STDOUT_FILENO);
			ft_putstr_fd(": numeric argument required\n", STDOUT_FILENO);
			shell->exit_code = EB_MISUSE_BUILTINS;
		}
		else
			shell->exit_code = ft_atoi(argv[1]) % 256;
	}
	else if (ft_str_arr_count(argv) > 2)
	{
		shell->exit_code = EB_COMMAND_NOT_FOUND;
		ft_putstr_fd("MINIshell: exit: too many arguments\n", \
			STDOUT_FILENO);
		return (EXIT_FAILURE);
	}
	exit_program(shell, F_SHELL, E_NONE, NULL);
	return (EXIT_SUCCESS);
}

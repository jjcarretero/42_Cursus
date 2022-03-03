/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 21:54:49 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/05 14:12:27 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_str(int status)
{
	if (status == E_MEM)
		ft_putstr_fd("Unable to allocate memory: ", STDERR_FILENO);
	if (status == E_SYNTAX)
		ft_putstr_fd("MINIShell: syntax error near unexpected token: ", \
			STDERR_FILENO);
	if (status == E_LEXER)
		ft_putstr_fd("MINIShell: lexer: ", STDERR_FILENO);
}

void	print_error(t_minishell *shell, int err, char *extra)
{
	t_minishell	*tshell;

	tshell = get_minishell(shell);
	tshell->state = ST_ERROR;
	if (err != E_NONE)
	{
		ft_putstr_fd("ERROR:\n", STDERR_FILENO);
		error_str(err);
	}
	if (extra != NULL)
	{
		ft_putstr_fd(extra, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
}

void	exit_program(t_minishell *shell, int status, int err, char *extra)
{
	int			ex;
	t_minishell	*tshell;

	tshell = get_minishell(shell);
	ex = tshell->exit_code;
	if (err != E_NONE)
	{
		ft_putstr_fd("ERROR:\n", STDERR_FILENO);
		error_str(err);
	}
	if (extra != NULL)
	{
		ft_putstr_fd(extra, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	free_program(tshell, status);
	exit(ex);
}

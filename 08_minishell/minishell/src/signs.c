/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 20:36:58 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/05 19:15:06 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	sign_handler_nel(int signal)
{
	t_minishell	*shell;
	int			last_state;

	shell = get_minishell(NULL);
	shell->exit_code = SIGINT + EXIT_STATUS;
	last_state = shell->state;
	shell->state = ST_SIGINT;
	ft_putchar_fd('\n', STDIN_FILENO);
	if (signal == SIGINT && last_state == ST_PREPARED)
	{
		shell->std.in = dup(STDIN_FILENO);
		if (shell->std.in == -1)
			exit_program(shell, F_SHELL, E_SIG, "");
		close(STDIN_FILENO);
	}
}

static void	sign_quit(int signal)
{
	t_minishell	*shell;
	int			last_state;

	shell = get_minishell(NULL);
	shell->exit_code = SIGQUIT + EXIT_STATUS;
	last_state = shell->state;
	if (signal == SIGQUIT && last_state == ST_OK)
	{
		ft_putstr_fd("Quit: 3\n", STDIN_FILENO);
		kill(0, SIGCHLD);
	}
}

void	null_line(void)
{
	t_minishell	*shell;

	shell = get_minishell(NULL);
	if (shell->state == ST_SIGINT)
	{
		if (dup2(shell->std.in, STDIN_FILENO) == -1)
			exit_program(shell, F_SHELL, E_SIG, strerror(errno));
		close(shell->std.in);
	}
	else
		ft_exit(NULL);
}

void	set_shell_signals(t_minishell *shell)
{
	if (signal(SIGQUIT, (void (*)(int))sign_quit) == SIG_ERR)
		exit_program(shell, F_SHELL, E_SIG, "");
	if (signal(SIGINT, (void (*)(int))sign_handler_nel) == SIG_ERR)
		exit_program(shell, F_SHELL, E_SIG, "");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 13:45:53 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/05 19:03:20 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	reset_shell(t_minishell *shell, int argc)
{
	if (shell->bst)
		shell->bst = free_bst(shell->bst);
	tok_delete(&((shell->lexer).list_token));
	shell->std.in = shell->save_std.in;
	shell->std.out = shell->save_std.out;
	shell->line = ft_memfree(shell->line, NULL);
	shell->path = ft_memfree(shell->path, NULL);
	shell->state = ST_PREPARED;
	if (argc > 1)
		return (FALSE);
	return (TRUE);
}

static int	ft_get_input(char **line)
{
	t_minishell	*shell;
	int			last_state;

	shell = get_minishell(NULL);
	last_state = shell->state;
	shell->prompt = set_prompt("$ ");
	*line = readline(shell->prompt);
	shell->prompt = ft_memfree(shell->prompt, NULL);
	if (shell->state == ST_PREPARED)
		shell->state = ST_OK;
	if (*line == NULL)
	{
		null_line();
		return (FALSE);
	}
	add_history(*line);
	return (TRUE);
}

static void	process_input(t_minishell *shell)
{
	if (ft_lexer(shell))
	{
		ft_putstr_fd("MINIshell: Lexer: ", STDOUT_FILENO);
		ft_putstr_fd(strerror(errno), STDOUT_FILENO);
		ft_putchar_fd('\n', STDOUT_FILENO);
	}
	if (shell->state == ST_OK)
	{
		if (!ft_parser(shell) && shell->state == ST_OK)
			ft_execute(shell);
		else
		{
			shell->state = ST_ERROR;
			shell->exit_code = E_PARSER;
		}
	}
}

void	initialize_minishell(t_minishell *shell, int argc)
{
	int	condition;

	condition = TRUE;
	shell->state = ST_PREPARED;
	while (condition)
	{
		if (argc == 1)
			condition = ft_get_input(&(shell->line));
		if (condition)
			process_input(shell);
		condition = reset_shell(shell, argc);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/01 16:54:18 by rpunet            #+#    #+#             */
/*   Updated: 2022/02/03 18:29:58 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_job(t_minishell *shell, t_ast_node *job, char ***envp)
{
	t_exec		exec;

	if (job == NULL)
		return ;
	shell->std.in = STDIN_FILENO;
	shell->std.out = STDOUT_FILENO;
	exec.cmd_node = job;
	if (job->type == PIPE_NODE)
	{
		execute_instr_pipe(shell, &exec, envp);
	}
	else
		execute_instr(shell, &exec, envp);
	while (waitpid(-1, NULL, 0) > 0)
	{
		do_nothing(NULL);
	}
}

static void	execute_logical_seq(t_minishell *shell, \
						t_ast_node *seq, char ***envp)
{
	int	type;
	int	other;

	type = seq->type;
	other = AND_NODE;
	if (type == AND_NODE)
		other = OR_NODE;
	execute_job(shell, seq->left, envp);
	if ((shell->exit_code == 0 && type == AND_NODE) || \
		(shell->exit_code != 0 && type == OR_NODE))
		execute_seq(shell, seq->right, envp);
	else
	{
		while (seq->type == type)
			seq = seq->right;
		if (seq->type == other || seq->type == SEQ_NODE)
			execute_seq(shell, seq->right, envp);
	}
}

void	execute_seq(t_minishell *shell, t_ast_node *seq, char ***envp)
{
	if (seq == NULL)
		return ;
	if (seq->type == SEQ_NODE)
	{
		execute_job(shell, seq->left, envp);
		execute_seq(shell, seq->right, envp);
	}
	if (seq->type == AND_NODE || seq->type == OR_NODE)
		execute_logical_seq(shell, seq, envp);
	else
		execute_job(shell, seq, envp);
}

void	ft_execute(t_minishell *shell)
{
	if (shell->lexer.brackets)
		execute_bst(shell, shell->bst, &(shell->envp_dup));
	else
		execute_seq(shell, shell->bst->tree, &(shell->envp_dup));
}

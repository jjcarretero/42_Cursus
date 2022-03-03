/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_instr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 22:32:49 by jcarrete          #+#    #+#             */
/*   Updated: 2022/01/28 22:33:07 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	execute_instr_pipe(t_minishell *shell, t_exec *exec, char ***envp)
{
	t_ast_node	*curr;

	pipe(exec->fds);
	shell->std.out = exec->fds[WRITE];
	curr = exec->cmd_node->right;
	exec->cmd_node = exec->cmd_node->left;
	execute_instr(shell, exec, envp);
	shell->std.in = exec->fds[READ];
	while (curr != NULL && curr->type == PIPE_NODE)
	{
		close(exec->fds[WRITE]);
		pipe(exec->fds);
		shell->std.out = exec->fds[WRITE];
		exec->cmd_node = curr->left;
		execute_instr(shell, exec, envp);
		close(shell->std.in);
		shell->std.in = exec->fds[READ];
		curr = curr->right;
	}
	close(exec->fds[WRITE]);
	shell->std.out = STDOUT_FILENO;
	exec->cmd_node = curr;
	execute_instr(shell, exec, envp);
	close(exec->fds[READ]);
}

void	execute_instr(t_minishell *shell, t_exec *exec, char ***envp)
{
	if (check_if_redir(exec->cmd_node->type))
		execute_redirection(shell, exec, envp);
	else
		execute_cmd(shell, exec, envp);
}

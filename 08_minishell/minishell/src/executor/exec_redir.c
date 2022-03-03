/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:59:24 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/04 20:43:20 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	exec_indir(t_minishell *shell, t_exec *exec, int indir)
{
	t_ast_node	*dir;

	dir = exec->cmd_node->right;
	if (dir->type == FILENAME_NODE)
		exec->cmd_node->data = dir->data;
	else if (check_if_redir(dir->type))
		exec->cmd_node->data = dir->left->data;
	if (exec->cmd_node->left != NULL && indir)
		close(shell->std.in);
	exec->cmd_node->data = ft_memfree(exec->cmd_node->data, \
							check_expansion(exec->cmd_node->data));
	if (dir->type == FILENAME_NODE)
		dir->data = NULL;
	else if (check_if_redir(dir->type))
		dir->left->data = NULL;
	if (exec->cmd_node->type == INDIR_NODE)
		shell->std.in = open(exec->cmd_node->data, O_RDONLY);
	else if (exec->cmd_node->type == LIMIT_NODE)
		shell->std.in = here_doc(shell, exec);
	return (TRUE);
}

static int	exec_redir(t_minishell *shell, t_exec *exec, int redir)
{
	t_ast_node	*dir;

	dir = exec->cmd_node->right;
	if (dir->type == FILENAME_NODE)
		exec->cmd_node->data = dir->data;
	else if (check_if_redir(dir->type))
		exec->cmd_node->data = dir->left->data;
	if (exec->cmd_node->left != NULL && redir)
		close(shell->std.out);
	exec->cmd_node->data = ft_memfree(exec->cmd_node->data, \
							check_expansion(exec->cmd_node->data));
	if (dir->type == FILENAME_NODE)
		dir->data = NULL;
	else if (check_if_redir(dir->type))
		dir->left->data = NULL;
	if (exec->cmd_node->type == REDIR_NODE)
		shell->std.out = open(exec->cmd_node->data, \
							O_CREAT | O_WRONLY | O_TRUNC, S_IRWUGO);
	else if (exec->cmd_node->type == APPEND_NODE)
		shell->std.out = open(exec->cmd_node->data, \
						O_CREAT | O_WRONLY | O_APPEND, S_IRWUGO);
	return (TRUE);
}

void	execute_redirection(t_minishell *shell, t_exec *exec, char ***envp)
{
	t_ast_node	*cmd;
	int			redir;
	int			indir;

	redir = FALSE;
	indir = FALSE;
	cmd = exec->cmd_node->left;
	while (check_if_redir(exec->cmd_node->type))
	{
		if (exec->cmd_node->type == REDIR_NODE || \
			exec->cmd_node->type == APPEND_NODE)
			redir = exec_redir(shell, exec, redir);
		else if (exec->cmd_node->type == INDIR_NODE || \
				exec->cmd_node->type == LIMIT_NODE)
			indir = exec_indir(shell, exec, indir);
		if (exec->cmd_node->right != NULL)
			exec->cmd_node = exec->cmd_node->right;
	}
	exec->cmd_node = cmd;
	execute_cmd(shell, exec, envp);
}

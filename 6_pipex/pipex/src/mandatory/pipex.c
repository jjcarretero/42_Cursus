/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 23:32:52 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/23 23:15:10 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	child_process(t_pipex_block *b, t_pipe *fd_pipe, t_list *first)
{
	t_tok	*token;

	token = first->content;
	close(fd_pipe->io[P_IN]);
	if (first->next && dup2(fd_pipe->io[P_OUT], STDOUT_FILENO) == -1)
		exit_program(b, F_CMD, E_DUP, ft_itoa(fd_pipe->io[P_OUT]));
	if (first->next == NULL && dup2(b->fd.io[FILE_OUT], STDOUT_FILENO) == -1)
		exit_program(b, F_CMD, E_DUP, ft_itoa(b->fd.io[FILE_OUT]));
	close(fd_pipe->io[P_OUT]);
	close(b->fd.io[FILE_IN]);
	close(b->fd.io[FILE_OUT]);
	execve(token->path, token->exec_args, b->envp);
	exit_program(b, F_CMD, E_CMD, token->exec_args[0]);
}

void	pipex(t_pipex_block *b)
{
	t_list	*first;
	t_pipe	fd_pipe;
	pid_t	pid;

	if (dup2(b->fd.io[FILE_IN], STDIN_FILENO) == -1)
		exit_program(b, F_CMD, E_DUP, ft_itoa(b->fd.io[FILE_IN]));
	close(b->fd.io[FILE_IN]);
	first = b->tokens;
	while (first)
	{
		if (pipe(fd_pipe.io) == -1)
			exit_program(b, F_CMD, E_PIPE, NULL);
		pid = fork();
		if (pid == -1)
			exit_program(b, F_CMD, E_FORK, strerror(errno));
		else if (pid == 0)
			child_process(b, &fd_pipe, first);
		close(fd_pipe.io[P_OUT]);
		if (first->next && dup2(fd_pipe.io[P_IN], STDIN_FILENO) == -1)
			exit_program(b, F_CMD, E_DUP, ft_itoa(b->fd.io[FILE_IN]));
		waitpid(pid, NULL, 0);
		close(fd_pipe.io[P_IN]);
		first = first->next;
	}
}

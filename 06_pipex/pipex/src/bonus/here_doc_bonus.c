/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 21:43:42 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/09 13:39:28 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	stream_literal(t_pipex_block *b)
{
	char	*stack;
	char	*tmp;
	char	buff[2];

	buff[1] = '\0';
	stack = NULL;
	while (stack == NULL || ft_strlen(stack) - 1 != ft_strlen(b->limit) || \
			ft_strncmp(b->limit, stack, ft_strlen (stack) - 1))
	{
		tmp = b->literal;
		b->literal = ft_strjoin(b->literal, stack);
		tmp = ft_memfree(tmp, NULL);
		stack = ft_memfree(stack, NULL);
		buff[0] = 0;
		ft_dprintf(1, "heredoc> ");
		while (buff[0] != '\n')
		{
			read(0, buff, 1);
			tmp = stack;
			stack = ft_strjoin(stack, buff);
			tmp = ft_memfree(tmp, NULL);
		}
	}
	stack = ft_memfree(stack, NULL);
}

int	here_document(t_pipex_block *b)
{
	t_pipe	fd_pipe;
	pid_t	pid;

	stream_literal(b);
	if (pipe(fd_pipe.io) == -1)
		exit_program(b, F_LITERAL, E_PIPE, NULL);
	pid = fork();
	if (pid == -1)
		exit_program(b, F_LITERAL, E_FORK, strerror(errno));
	else if (pid == 0)
	{
		close(fd_pipe.io[P_IN]);
		ft_dprintf(fd_pipe.io[P_OUT], b->literal);
		b->fd.io[FILE_IN] = fd_pipe.io[P_IN];
		close(fd_pipe.io[P_OUT]);
		exit_program(b, F_SUCCESS, E_SUCCESS, NULL);
	}
	close(fd_pipe.io[P_OUT]);
	b->literal = ft_memfree(b->literal, NULL);
	return (fd_pipe.io[P_IN]);
}

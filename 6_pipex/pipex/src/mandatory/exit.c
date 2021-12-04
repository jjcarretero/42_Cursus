/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 12:35:54 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/09 16:30:18 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	error_str(int status)
{
	if (status == E_MEM)
		ft_dprintf(STDERR_FILENO, "unable to allocate memory: ");
	else if (status == E_ARGS)
		ft_dprintf(STDERR_FILENO, "invalid number of arguments.");
	else if (status == E_FILE)
		ft_dprintf(STDERR_FILENO, "no such file or directory: ");
	else if (status == E_PERM_R)
		ft_dprintf(STDERR_FILENO, "permission denied. Can't read file: ");
	else if (status == E_PERM_W)
		ft_dprintf(STDERR_FILENO, "permission denied. Can't write file: ");
	else if (status == E_PATH)
		ft_dprintf(STDERR_FILENO, "PATH variable is not set.");
	else if (status == E_CMD)
		ft_dprintf(STDERR_FILENO, "command not found: ");
	else if (status == E_DUP)
		ft_dprintf(STDERR_FILENO, "could not dup fd: ");
	else if (status == E_PIPE)
		ft_dprintf(STDERR_FILENO, "could not create pipe.");
	else if (status == E_FORK)
		ft_dprintf(STDERR_FILENO, "can't fork, error: ");
}

void	free_char_array(char ***arr)
{
	int	i;

	i = 0;
	while (arr[0][i])
	{
		arr[0][i] = ft_memfree(arr[0][i], NULL);
		i++;
	}
	if (arr[0][0] != NULL)
		arr[0] = ft_memfree(arr[0], NULL);
}

static void	pipex_free_list(void *token)
{
	t_tok	*tmp;

	tmp = (struct s_tok *)token;
	tmp->path = ft_memfree(tmp->path, NULL);
	if (tmp->exec_args[0])
		free_char_array(&tmp->exec_args);
	tmp = ft_memfree(tmp, NULL);
}

static void	free_program(t_pipex_block *b, int status)
{
	if (status >= F_BLOCK)
	{
		close(STDIN_FILENO);
		close(b->fd.io[0]);
		close(b->fd.io[1]);
		if (status >= F_ENVP && b->envp)
			free_char_array(&b->envp);
		if (status >= F_CMD && b->tokens)
			ft_lstclear(&b->tokens, pipex_free_list);
		if (b->tmp_cmd)
			free_char_array(&b->tmp_cmd);
		b = ft_memfree(b, NULL);
	}
}

void	exit_program(t_pipex_block *b, int status, int err, char *extra)
{
	if (status == F_SUCCESS)
	{
		free_program(b, status);
		exit (EXIT_SUCCESS);
	}
	ft_dprintf(STDERR_FILENO, "ERROR:\n");
	if (err != E_NONE)
		error_str(err);
	if (extra != NULL)
		ft_dprintf(STDERR_FILENO, extra);
	ft_dprintf(STDERR_FILENO, "\n");
	free_program(b, status);
	exit(EXIT_FAILURE);
}

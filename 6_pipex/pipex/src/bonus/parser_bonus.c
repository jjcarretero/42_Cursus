/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 17:57:58 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/01 19:11:02 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static t_tok	*new_token(char *path, char **tmp_cmd)
{
	t_tok	*ret;

	if (tmp_cmd == NULL)
		return (NULL);
	ret = ft_memalloc(sizeof(t_tok));
	if (ret == NULL)
		return (NULL);
	ret->path = ft_strdup(path);
	if (path && ret->path == NULL)
	{
		ret = ft_memfree(ret, NULL);
		return (NULL);
	}
	ret->exec_args = tmp_cmd;
	return (ret);
}

static void	write_command_path(t_pipex_block *b, char **path, char *cmd)
{
	int		i;
	char	*tmp_path;

	i = 0;
	*path = NULL;
	while (b->envp[i])
	{
		*path = ft_memfree(*path, NULL);
		tmp_path = ft_strappend_nchr(b->envp[i], '/', 1);
		if (tmp_path == NULL)
			exit_program(b, F_CMD, E_MEM, strerror(errno));
		*path = ft_strjoin(tmp_path, cmd);
		tmp_path = ft_memfree(tmp_path, NULL);
		if (path == NULL)
			exit_program(b, F_CMD, E_MEM, strerror(errno));
		if (access(*path, F_OK) == 0)
			break ;
		i++;
	}
	if (b->envp == NULL || b->envp[i] == NULL)
	{
		*path = ft_memfree(*path, NULL);
		exit_program(b, F_CMD, E_CMD, cmd);
	}
}

void	parser(int argc, char **argv, t_pipex_block *b)
{
	int		i;
	char	*path;
	t_list	*tmp_lst;

	i = 2;
	while (i < (argc - 1))
	{
		b->tmp_cmd = ft_split(argv[i], ' ');
		if (b->tmp_cmd == NULL || b->tmp_cmd[0] == NULL)
			exit_program(b, F_CMD, E_CMD, argv[i]);
		write_command_path(b, &path, b->tmp_cmd[0]);
		tmp_lst = ft_lstnew(new_token(path, b->tmp_cmd));
		ft_lstadd_back(&(b->tokens), tmp_lst);
		path = ft_memfree(path, NULL);
		i++;
	}
}

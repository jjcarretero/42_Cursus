/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 21:43:34 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/05 00:32:16 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_if_redir(int type)
{
	if (type == REDIR_NODE || type == APPEND_NODE || \
		type == INDIR_NODE || type == LIMIT_NODE)
		return (TRUE);
	if (type == T_REDIR || type == T_APPEND || \
		type == T_INDIR || type == T_LIMITER)
		return (TRUE);
	return (FALSE);
}

int	count_commands(t_ast_node *cmd_node)
{
	int			ret;
	t_ast_node	*curr;

	curr = cmd_node;
	ret = 0;
	while (curr != NULL && \
		(curr->type == CMDNAME_NODE || curr->type == TOKEN_NODE))
	{
		ret++;
		curr = curr->right;
	}
	return (ret);
}

char	*check_directories(DIR **dir, char **args, char **paths, int i)
{
	char			*path;
	struct dirent	*d;

	*dir = opendir(paths[i]);
	if (!*dir)
	{
		closedir(*dir);
		return (NULL);
	}
	errno = 0;
	d = readdir(*dir);
	while (*dir && errno == 0 && d)
	{
		if (!ft_strcmp(d->d_name, args[0]))
		{
			path = ft_strjoin(paths[i], "/");
			free_char_array(paths, double_len(paths));
			closedir(*dir);
			return (path);
		}
		d = readdir(*dir);
	}
	closedir(*dir);
	return (NULL);
}

char	*find_directory(DIR **dir, char **args)
{
	char		*path_var;
	char		**paths;
	int			i;
	t_minishell	*shell;

	shell = get_minishell(NULL);
	if (!ft_strcmp(args[0], "minishell"))
		return (find_value(shell->envp_dup, "_"));
	path_var = find_value(shell->envp_dup, "PATH");
	if (path_var)
	{
		paths = ft_split(path_var, ':');
		path_var = ft_memfree(path_var, NULL);
		i = 0;
		while (paths && paths[i])
		{
			path_var = check_directories(dir, args, paths, i);
			if (path_var != NULL)
				return (ft_memfree(path_var, ft_strjoin(path_var, args[0])));
			i++;
		}
		free_char_array(paths, double_len(paths));
	}
	return (NULL);
}

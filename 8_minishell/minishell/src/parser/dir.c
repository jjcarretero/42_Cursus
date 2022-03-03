/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 17:26:05 by rpunet            #+#    #+#             */
/*   Updated: 2022/01/22 23:29:15 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node	*gr_dir(void)
{
	t_tok		*save;
	t_ast_node	*node;

	save = g_current_tok;
	node = gr_dir_2();
	if (node != NULL)
		return (node);
	g_current_tok = save;
	node = gr_dir_1();
	if (node != NULL)
		return (node);
	return (NULL);
}

t_ast_node	*gr_dir_2(void)
{
	t_ast_node	*filename;
	t_ast_node	*dir;
	int			dir_type;

	filename = gr_dir_1();
	if (filename == NULL)
		return (NULL);
	if (g_current_tok != NULL)
		dir_type = get_dir_type();
	if (terminal_redir())
	{
		ast_delete(&filename);
		return (NULL);
	}
	dir = gr_dir();
	if (dir == NULL)
	{
		ast_delete(&filename);
		return (NULL);
	}
	return (create_parent_node(dir_type, NULL, filename, dir));
}

t_ast_node	*gr_dir_1(void)
{
	char		*dataname;

	dataname = NULL;
	if (g_current_tok != NULL)
		dataname = ft_strdup(g_current_tok->data);
	if (terminal(T_TOKEN))
		return (return_null(dataname));
	return (create_parent_node(FILENAME_NODE, dataname, NULL, NULL));
}

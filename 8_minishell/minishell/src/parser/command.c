/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:27:42 by jcarrete          #+#    #+#             */
/*   Updated: 2022/01/22 23:29:28 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ast_node	*gr_cmd(void)
{
	t_ast_node	*node;

	node = gr_cmd_1();
	if (node != NULL)
		return (node);
	return (NULL);
}

t_ast_node	*gr_cmd_1(void)
{
	t_ast_node	*tokenlist;
	char		*dataname;

	dataname = NULL;
	if (g_current_tok != NULL)
		dataname = ft_strdup(g_current_tok->data);
	if (terminal(T_TOKEN))
		return (return_null(dataname));
	tokenlist = gr_tokenlist();
	return (create_parent_node(CMDNAME_NODE, dataname, NULL, tokenlist));
}

t_ast_node	*gr_tokenlist(void)
{
	t_tok		*save;
	t_ast_node	*node;

	save = g_current_tok;
	node = gr_tokenlist_1();
	if (node != NULL)
		return (node);
	g_current_tok = save;
	node = gr_tokenlist_2();
	if (node != NULL)
		return (node);
	return (NULL);
}

t_ast_node	*gr_tokenlist_1(void)
{
	t_ast_node	*tokenlist;
	char		*dataarg;

	dataarg = NULL;
	if (g_current_tok != NULL)
		dataarg = ft_strdup(g_current_tok->data);
	if (terminal(T_TOKEN))
		return (return_null(dataarg));
	tokenlist = gr_tokenlist();
	return (create_parent_node(TOKEN_NODE, dataarg, NULL, tokenlist));
}

t_ast_node	*gr_tokenlist_2(void)
{
	return (NULL);
}

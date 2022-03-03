/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 21:04:33 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/05 15:11:34 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ast_delete(t_ast_node **node)
{
	t_ast_node	*right;
	t_ast_node	*left;

	if ((*node) == NULL)
		return ;
	if ((*node)->data != NULL)
		(*node)->data = ft_memfree((*node)->data, NULL);
	right = (*node)->right;
	left = (*node)->left;
	(*node) = ft_memfree((*node), NULL);
	ast_delete(&left);
	ast_delete(&right);
}

void	delete_single_ast(t_ast_node **node)
{
	if ((*node) == NULL)
		return ;
	if ((*node)->type >= CMDNAME_NODE && (*node)->data != NULL)
		(*node)->data = ft_memfree((*node)->data, NULL);
	if ((*node)->right != NULL)
		(*node)->right->left = NULL;
	if ((*node)->left != NULL)
		(*node)->left->right = NULL;
	(*node) = ft_memfree((*node), NULL);
}

t_ast_node	*create_parent_node(int type, char *data, \
				t_ast_node *left, t_ast_node *right)
{
	t_ast_node	*ret;

	ret = malloc(sizeof(t_ast_node));
	if (ret == NULL)
		exit_program(NULL, F_SHELL, E_MEM, strerror(errno));
	ret->type = type;
	ret->data = data;
	ret->left = left;
	ret->right = right;
	return (ret);
}

int	get_operator_type(int type)
{
	if (type == T_AND)
		return (AND_NODE);
	else if (type == T_SEMICOLON)
		return (SEQ_NODE);
	else if (type == T_OR)
		return (OR_NODE);
	return (0);
}

t_bst	*create_bst_node(void)
{
	t_bst	*statement;

	statement = malloc(sizeof(t_bst));
	if (statement == NULL)
		return (NULL);
	statement->operator_child = 0;
	statement->operator_next = 0;
	statement->tree = NULL;
	statement->child = NULL;
	statement->next = NULL;
	statement->prev = NULL;
	return (statement);
}

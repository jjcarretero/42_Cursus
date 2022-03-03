/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 22:36:14 by rpunet            #+#    #+#             */
/*   Updated: 2022/02/05 16:31:36 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** ----------shell grammar rules:---------------
** SEQUENCE			:=		JOB		&&	SEQUENCE
**							JOB		||	SEQUENCE
**							JOB		;	SEQUENCE
** 							JOB		;
** 							JOB
**
** JOB				:=		INSTR	|	JOB
** 							INSTR
**
** INSTR			:=		CMD		>	DIR
**							CMD
**
**	DIR				:=		filename	>	DIR
**							filename
**
** CMD				:=		cmdname	TOKENLIST
**
** TOKENLIST		:=		token	TOKENLIST
** 							(empty)
*/

int	terminal(int tokentype)
{
	if (g_current_tok == NULL)
		return (EXIT_FAILURE);
	if (g_current_tok->type == tokentype)
	{
		g_current_tok = g_current_tok->next;
		return (EXIT_SUCCESS);
	}
	g_current_tok = g_current_tok->next;
	return (EXIT_FAILURE);
}

int	terminal_redir(void)
{
	if (g_current_tok == NULL)
		return (EXIT_FAILURE);
	if (check_if_redir(g_current_tok->type))
	{
		g_current_tok = g_current_tok->next;
		return (EXIT_SUCCESS);
	}
	g_current_tok = g_current_tok->next;
	return (EXIT_FAILURE);
}

int	terminal_seq(void)
{
	if (g_current_tok == NULL)
		return (EXIT_FAILURE);
	if (g_current_tok->type == T_AND || \
		g_current_tok->type == T_OR || \
		g_current_tok->type == T_SEMICOLON)
	{
		g_current_tok = g_current_tok->next;
		return (EXIT_SUCCESS);
	}
	g_current_tok = g_current_tok->next;
	return (EXIT_FAILURE);
}

/*
** ----------------------  TREE ROOT ----------------------------
*/

int	ft_parser(t_minishell *shell)
{
	expand_filenames(&(shell->lexer.list_token));
	shell->bst = create_bst_node();
	if (shell->state == ST_OK && shell->lexer.brackets == 0)
	{
		g_current_tok = shell->lexer.list_token;
		shell->bst->tree = gr_seq();
	}
	else if (shell->state == ST_OK && shell->lexer.brackets != 0)
		parse_brackets(shell);
	if (g_current_tok != NULL && g_current_tok->type != T_NULTOK)
	{
		shell->state = ST_ERROR;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

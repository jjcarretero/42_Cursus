/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 22:19:55 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/05 16:39:52 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	advance_one(t_tok **curr, t_tok **prev, t_tok **ante)
{
	if (*prev != NULL)
		*ante = *prev;
	if (*curr != NULL)
		*prev = *curr;
	if ((*curr)->next)
		*curr = (*curr)->next;
}

static void	handle_open_bracket(t_bst **bst, t_tok **curr, \
								t_tok **prev, t_tok **ante)
{
	t_bst	*actual_bst;

	actual_bst = *bst;
	if ((*curr)->next->type == T_BRAKET_CLOSE)
		exit_program(get_minishell(NULL), F_SHELL, E_PARSER, "(");
	while ((*curr)->next->type == T_BRAKET_OPEN)
		*curr = (*curr)->next;
	actual_bst->operator_child = get_operator_type((*prev)->type);
	if (*ante)
		(*ante)->next = NULL;
	actual_bst->tree = gr_seq();
	actual_bst->child = create_bst_node();
	*bst = actual_bst->child;
	(*bst)->prev = actual_bst;
	g_current_tok = (*curr)->next;
}

static void	handle_close_bracket(t_bst **bst, t_tok **curr, t_tok **prev)
{
	t_bst	*actual_bst;
	t_bst	*link;

	actual_bst = *bst;
	(*prev)->next = NULL;
	actual_bst->tree = gr_seq();
	g_current_tok = NULL;
	if ((*curr)->next->type == T_NULTOK)
		return ;
	if ((*curr)->next->type == T_BRAKET_OPEN)
		exit_program(get_minishell(NULL), F_SHELL, E_PARSER, ")");
	link = actual_bst->prev;
	while ((*curr)->next->type == T_BRAKET_CLOSE)
	{
		*curr = (*curr)->next;
		link = link->prev;
	}
	while (link->next != NULL)
		link = link->prev;
	link->operator_next = get_operator_type((*curr)->next->type);
	link->next = create_bst_node();
	*bst = link->next;
	(*bst)->prev = link;
	g_current_tok = (*curr)->next->next;
}

static void	brackets_loop(t_bst **curr_bst, t_tok **curr_tok)
{
	t_tok	*pre_tok;
	t_tok	*ant_tok;

	pre_tok = NULL;
	ant_tok = NULL;
	while ((*curr_tok && (*curr_tok)->type != T_NULTOK) \
			&& (*curr_tok)->next != NULL)
	{
		while ((*curr_tok && (*curr_tok)->next != NULL) \
				&& ((*curr_tok)->type != T_BRAKET_OPEN && \
					(*curr_tok)->type != T_BRAKET_CLOSE))
			advance_one(&(*curr_tok), &pre_tok, &ant_tok);
		if (*curr_tok && (*curr_tok)->type == T_BRAKET_OPEN)
			handle_open_bracket(&(*curr_bst), &(*curr_tok), &pre_tok, &ant_tok);
		else if (*curr_tok && (*curr_tok)->type == T_BRAKET_CLOSE)
			handle_close_bracket(&(*curr_bst), &(*curr_tok), &pre_tok);
		else
		{
			(*curr_bst)->tree = gr_seq();
			g_current_tok = NULL;
		}
		advance_one(&(*curr_tok), &pre_tok, &ant_tok);
	}
}

void	parse_brackets(t_minishell *shell)
{
	t_bst	*curr_bst;
	t_tok	*curr_tok;

	curr_bst = shell->bst;
	curr_tok = shell->lexer.list_token;
	while (curr_tok && curr_tok->type == T_BRAKET_OPEN)
		curr_tok = curr_tok->next;
	g_current_tok = curr_tok;
	brackets_loop(&curr_bst, &curr_tok);
}

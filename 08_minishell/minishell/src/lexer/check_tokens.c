/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tokens.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 23:09:34 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/05 16:52:28 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_parenthesis(t_tok *curr, t_tok *prev, int *bracket, int cond)
{
	t_minishell	*shell;

	shell = get_minishell(NULL);
	if (curr->type == T_BRAKET_OPEN)
	{
		(*bracket)++;
		(shell->lexer.brackets)++;
	}
	if (curr->type == T_BRAKET_CLOSE)
	{
		(*bracket)--;
		if (*bracket < 0 || prev->type == T_BRAKET_OPEN)
			return (FALSE);
	}
	if ((curr->next == NULL || curr->next->type == T_NULTOK) && *bracket > 0)
		return (FALSE);
	return (cond);
}

static int	check_token_syntax(t_tok *curr, t_tok *prev)
{
	if (check_if_redir(curr->type) && curr->next->type > 0)
		return (FALSE);
	if ((curr->type == T_AND || curr->type == T_OR || \
		curr->type == T_PIPE) && (prev == NULL || curr->next == NULL || \
		(prev->type >= 0 && prev->type != T_BRAKET_CLOSE)))
		return (FALSE);
	return (TRUE);
}

void	check_tokens(t_minishell *shell, t_tok *list)
{
	int		condition;
	t_tok	*curr;
	t_tok	*prev;
	int		bracket;

	bracket = 0;
	shell->lexer.brackets = 0;
	curr = list;
	prev = NULL;
	while (curr)
	{
		condition = check_token_syntax(curr, prev);
		condition = check_parenthesis(curr, prev, &bracket, condition);
		if (condition == FALSE)
		{
			shell->exit_code = EB_MISUSE_BUILTINS;
			print_error(shell, E_SYNTAX, curr->data);
			break ;
		}
		prev = curr;
		curr = curr->next;
	}
}

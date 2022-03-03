/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 11:15:46 by jcarrete          #+#    #+#             */
/*   Updated: 2022/01/24 22:17:47 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	operator_length(t_lex *lexer, char *line)
{
	int	pos;

	pos = lexer->line_pos;
	if (ft_strlen(line) >= 2 && line[pos] == line[pos + 1])
		return (2);
	return (1);
}

void	fill_data(t_lex *lexer, t_tok **token, char *line, int end)
{
	if (end == 2)
	{
		(*token)->data[0] = (char)(line[lexer->line_pos++]);
		(*token)->data[1] = (char)(line[lexer->line_pos]);
		(*token)->data[2] = 0;
		if (line[lexer->line_pos] == '<')
			(*token)->type = T_LIMITER;
		if (line[lexer->line_pos] == '>')
			(*token)->type = T_APPEND;
		if (line[lexer->line_pos] == '|')
			(*token)->type = T_OR;
		if (line[lexer->line_pos] == '&')
			(*token)->type = T_AND;
	}
	else if (end == 1)
	{
		(*token)->data[0] = (char)(line[lexer->line_pos]);
		(*token)->data[1] = 0;
		(*token)->type = line[lexer->line_pos];
	}
}

t_tok	*tok_init(int datasize)
{
	t_tok	*token;

	token = malloc(sizeof(t_tok));
	if (token == NULL)
		return (NULL);
	token->data = malloc(datasize + 1);
	if (token->data == NULL)
		return (NULL);
	token->type = T_NULTOK;
	token->next = NULL;
	return (token);
}

void	tok_delete(t_tok **token)
{
	t_tok	*next;

	if ((*token) != NULL)
	{
		(*token)->data = ft_memfree((*token)->data, NULL);
		next = (*token)->next;
		(*token) = ft_memfree((*token), NULL);
		tok_delete(&next);
	}
}

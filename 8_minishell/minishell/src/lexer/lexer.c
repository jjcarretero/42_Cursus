/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 22:27:46 by rpunet            #+#    #+#             */
/*   Updated: 2022/02/05 13:58:21 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	check_quote_end(t_lex *lexer, t_tok *token, char *line)
{
	if (lexer->seq_state == S_QUOTED && line[lexer->line_pos] == '\'')
		lexer->seq_state = S_GENERAL;
	else if (lexer->seq_state == S_DQUOTED && line[lexer->line_pos] == '\"')
		lexer->seq_state = S_GENERAL;
	token->data[lexer->token_pos] = (char)(line[lexer->line_pos]);
	(lexer->token_pos)++;
}

static int	check_operators(t_lex *lexer, t_tok **token, char *line)
{
	int	end;

	end = operator_length(lexer, line);
	if (lexer->token_pos > 0)
	{
		(*token)->data[lexer->token_pos] = 0;
		(*token)->next = tok_init(end);
		if ((*token)->next == NULL)
			return (EXIT_FAILURE);
		(*token) = (*token)->next;
		lexer->token_pos = 0;
	}
	fill_data(lexer, token, line, end);
	(*token)->next = tok_init(ft_strlen(line) - lexer->line_pos);
	if ((*token)->next == NULL)
		return (EXIT_FAILURE);
	(*token) = (*token)->next;
	return (EXIT_SUCCESS);
}

static int	check_special_chars(t_lex *lexer, t_tok **token, char *line)
{
	const char	c = line[lexer->line_pos];

	if (c == ' ' && lexer->token_pos > 0)
	{
		(*token)->data[lexer->token_pos] = 0;
		(*token)->next = tok_init(ft_strlen(line) - lexer->line_pos);
		if ((*token)->next == NULL)
			return (EXIT_FAILURE);
		(*token) = (*token)->next;
		lexer->token_pos = 0;
	}
	else if (c != ' ')
	{
		if (c == '\'')
			lexer->seq_state = S_QUOTED;
		else if (c == '\"')
			lexer->seq_state = S_DQUOTED;
		else if (c == '\\')
			(lexer->line_pos)++;
		(*token)->type = T_TOKEN;
		(*token)->data[lexer->token_pos++] = (char)(line[lexer->line_pos]);
	}
	return (EXIT_SUCCESS);
}

static int	check_state(t_lex *lexer, char *line)
{
	t_tok	*token;
	int		ret;

	token = lexer->current_tok;
	ret = EXIT_SUCCESS;
	if (lexer->seq_state == S_GENERAL)
	{
		if (ft_strchr(SPECIAL_CHARS, line[lexer->line_pos]))
			ret = check_special_chars(lexer, &token, line);
		else if (ft_strchr(OPERATORS, line[lexer->line_pos]))
			ret = check_operators(lexer, &token, line);
		else
		{
			token->data[lexer->token_pos] = (char)(line[lexer->line_pos]);
			(lexer->token_pos)++;
			token->type = T_TOKEN;
		}
	}
	else if (lexer->seq_state == S_QUOTED || lexer->seq_state == S_DQUOTED)
		check_quote_end(lexer, token, line);
	lexer->current_tok = token;
	return (ret);
}

int	ft_lexer(t_minishell *shell)
{
	t_lex	*lexer;
	int		ret;

	lexer = &(shell->lexer);
	lexer->current_tok = tok_init(ft_strlen(shell->line));
	if (lexer->current_tok == NULL)
		return (EXIT_FAILURE);
	lexer->list_token = lexer->current_tok;
	lexer->seq_state = S_GENERAL;
	lexer->line_pos = 0;
	lexer->token_pos = 0;
	while (shell->line[lexer->line_pos] != 0)
	{
		ret = check_state(lexer, shell->line);
		if (ret == EXIT_FAILURE)
			return (EXIT_FAILURE);
		(lexer->line_pos)++;
	}
	shell->lexer.current_tok->data[lexer->token_pos] = 0;
	if (shell->lexer.seq_state != S_GENERAL)
		print_error(shell, E_LEXER, "Bad quoting");
	check_tokens(shell, lexer->list_token);
	return (EXIT_SUCCESS);
}

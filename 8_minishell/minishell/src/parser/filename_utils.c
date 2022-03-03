/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 22:24:28 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/01 00:31:50 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_tok	**add_new_token(t_tok **list, char *d_name)
{
	t_tok	*new_token;
	int		len;

	len = ft_strlen(d_name);
	new_token = tok_init(len);
	new_token->type = T_TOKEN;
	new_token->data = ft_memfree(new_token->data, ft_strdup(d_name));
	if (*list == NULL)
		*list = new_token;
	else
		ft_toklist_last(*list)->next = new_token;
	return (list);
}

int	check_if_wildcard(char *str)
{
	int		i;
	char	quote;

	i = 0;
	while (str[i])
	{
		if (str[i] == T_DQUOTE || str[i] == T_QUOTE)
		{
			quote = str[i];
			i++;
			while (str[i] != quote)
				i++;
		}
		if (str[i] == WILDCARD)
			return (TRUE);
		else
			i++;
	}
	return (FALSE);
}

t_tok	*ft_toklist_last(t_tok *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

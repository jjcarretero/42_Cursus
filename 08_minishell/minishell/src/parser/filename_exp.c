/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filename_exp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/31 00:05:45 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/01 00:32:16 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*last_match(char *d_name, char *curr_data, int len)
{
	char	*curr;
	int		num;

	curr = NULL;
	num = (ft_strlen(d_name) - len) + 1;
	while (num > 0)
	{
		if (!ft_strncmp(d_name, (curr_data + 1), len))
			curr = d_name;
		num--;
		d_name++;
	}
	if (curr == NULL)
		return (curr);
	return (curr + len);
}

static int	expanse_if_match(char *curr_data, char *d_name)
{
	int	len;

	while (*curr_data != '*')
	{
		if (*d_name != *curr_data)
			return (FALSE);
		curr_data++;
		d_name++;
	}
	while (*curr_data && *(curr_data + 1))
	{
		while (*(curr_data + 1) == '*')
			curr_data++;
		len = 1;
		while (curr_data[len] && curr_data[len] != '*')
			len++;
		len--;
		d_name = last_match(d_name, curr_data, len);
		if (!d_name)
			return (FALSE);
		curr_data += 1 + len;
	}
	return (TRUE);
}

static t_tok	**check_wildcard_matches(t_tok *curr)
{
	t_tok			**ret;
	DIR				*wd;
	struct dirent	*entry;
	char			*cwd;

	ret = ft_memalloc(sizeof(t_tok *));
	cwd = getcwd(NULL, 0);
	wd = opendir(cwd);
	if (wd == NULL)
		exit_program(get_minishell(NULL), F_SHELL, 0, strerror(errno));
	cwd = ft_memfree(cwd, NULL);
	entry = readdir(wd);
	while (entry)
	{
		if (expanse_if_match(curr->data, entry->d_name))
			ret = add_new_token(ret, entry->d_name);
		entry = readdir(wd);
	}
	closedir(wd);
	return (ret);
}

static t_tok	*insert_wildcard(t_tok **list, t_tok *prev, t_tok *curr)
{
	t_tok	**new_list;
	t_tok	*new_tok;

	new_tok = curr;
	new_list = check_wildcard_matches(curr);
	if (new_list && *new_list)
	{
		if (prev == NULL)
			*list = *new_list;
		else
			prev->next = *new_list;
		new_tok = ft_toklist_last(*new_list);
		new_tok->next = curr->next;
		curr->data = ft_memfree(curr->data, NULL);
		curr = ft_memfree(curr, new_tok);
	}
	new_list = ft_memfree(new_list, NULL);
	return (new_tok);
}

void	expand_filenames(t_tok **list)
{
	t_tok	*curr;
	t_tok	*prev;

	prev = NULL;
	curr = *list;
	while (curr)
	{
		if (curr->type == T_TOKEN)
		{
			if (check_if_wildcard(curr->data))
				curr = insert_wildcard(list, prev, curr);
		}
		prev = curr;
		curr = curr->next;
	}
}

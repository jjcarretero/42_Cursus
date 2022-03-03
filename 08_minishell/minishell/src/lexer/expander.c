/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 12:38:29 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/05 16:53:26 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_command(t_minishell *shell, char **aux, \
					char **find, char **str)
{
	char	*tmp;
	int		i;
	char	*var_value;

	var_value = find_value(shell->envp_dup, *aux);
	i = ft_strchr_pos(*str, '$');
	*aux = ft_memfree(*aux, ft_substr(*str, 0, i));
	if (var_value)
	{
		tmp = ft_strjoin(*aux, var_value);
		var_value = ft_memfree(var_value, NULL);
		*aux = ft_memfree(*aux, tmp);
	}
	else if (!strcmp(*str, "$?"))
	{
		tmp = ft_itoa(get_minishell(NULL)->exit_code);
		*aux = ft_memfree(*aux, tmp);
	}
	*str = ft_memfree(*str, NULL);
	tmp = ft_strjoin(*aux, *find);
	if (ft_strchr_pos(*find, '$') == ERROR)
		*find = NULL;
	return (ft_memfree(*aux, tmp));
}

void	expand_vars(char **str)
{
	char		*find;
	char		*aux;
	int			i;

	find = ft_strchr(*str, '$');
	while (find)
	{
		if (++find)
		{
			i = ft_strchr_pos(find, '$');
			if (i == ERROR)
			{
				i = 0;
				while (find[i] == '_' || ft_isalnum(find[i]))
					i++;
			}
			aux = ft_substr(find, 0, i);
			find += i;
			*str = get_command(get_minishell(NULL), &aux, &find, str);
			find = ft_strchr(*str, '$');
		}
	}
}

static void	handle_quotes(char *str, char **line, int *i)
{
	char	delim;
	int		j;
	char	*quoted;

	delim = str[*i];
	j = 0;
	quoted = ft_strnew(ft_strlen(str) + 1);
	*i += 1;
	while (str[*i] != delim)
	{
		quoted[j] = str[*i];
		*i += 1;
		j++;
	}
	quoted[j] = '\0';
	if (delim == T_DQUOTE)
		expand_vars(&quoted);
	*line = ft_strjoin_gnl(*line, quoted);
	quoted = ft_memfree(quoted, NULL);
}

static int	handle_unquoted(char **line, char *str, int *i)
{
	int		ret;

	ret = FALSE;
	while (str[*i] && (str[*i] != T_QUOTE && str[*i] != T_DQUOTE))
	{
		ret = TRUE;
		(*line)[*i] = str[*i];
		*i += 1;
	}
	return (ret);
}

char	*check_expansion(char *str)
{
	char	*line;
	int		i;

	i = 0;
	line = ft_strnew(ft_strlen(str) + 1);
	while (str[i])
	{
		if (handle_unquoted(&line, str, &i))
		{
			line[i] = '\0';
			expand_vars(&line);
		}
		if (str[i] == T_QUOTE || str[i] == T_DQUOTE)
			handle_quotes(str, &line, &i);
		if (str[i])
			i++;
	}
	return (line);
}

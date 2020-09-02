/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:14:16 by jcarrete          #+#    #+#             */
/*   Updated: 2020/07/23 17:14:41 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

static char		**split_malloc_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static size_t	split_str_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	if (!s[0])
		return (0);
	count = 0;
	i = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i])
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static void		split_get_str(char **str, size_t *len, char c)
{
	size_t	i;

	*str += *len;
	*len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*len)++;
		i++;
	}
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	char	*str;
	size_t	len;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	i = split_str_count(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	j = 0;
	str = (char *)s;
	len = 0;
	while (j < i)
	{
		split_get_str(&str, &len, c);
		if (!(tab[j] = (char *)malloc(sizeof(char) * (len + 1))))
			return (split_malloc_error(tab));
		ft_strlcpy(tab[j], str, len + 1);
		j++;
	}
	tab[j] = NULL;
	return (tab);
}

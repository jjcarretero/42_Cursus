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

static size_t	split_str_count(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] != c)
				i++;
		}
	}
	return (count);
}

static void		split_get_str(char **str, size_t *len, char c)
{
	size_t	i;
	size_t	j;

	j += *len;
	while (*str[j] && *str[j] == c)
		j++;
	i = 0;
	*len = 0;
	while (str[j][i])
	{
		if (str[j][i] == c)
			return ;
		i++;
		*len += 1;
	}
}

static char		**split_malloc_error(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	tab = ft_memfree(tab, NULL);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	char	**tab;
	char	*str;
	size_t	len;
	size_t	j;

	if (!s || !(tab = (char **)malloc(sizeof(char *) *\
				(split_str_count(s, c) + 1))))
		return (NULL);
	str = (char *)s;
	len = 0;
	j = 0;
	while (j < (split_str_count(s, c)))
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

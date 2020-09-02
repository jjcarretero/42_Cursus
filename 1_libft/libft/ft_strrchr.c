/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:24:01 by jcarrete          #+#    #+#             */
/*   Updated: 2020/07/23 17:24:16 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*r;

	c = (char)c;
	r = (char *)s;
	len = ft_strlen(s);
	while (len > 0)
	{
		if (r[len] == c)
			return (&r[len]);
		len--;
	}
	if (r[len] == c)
		return (r);
	return (0);
}

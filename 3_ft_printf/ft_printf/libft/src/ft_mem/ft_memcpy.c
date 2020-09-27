/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:00:30 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/02 00:17:29 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dst && !src)
		return (0);
	d = dst;
	s = (unsigned char *)src;
	i = 0;
	while (len--)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	unsigned char	find;
	size_t			i;

	find = c;
	i = 0;
	d = dst;
	s = (unsigned char *)src;
	if (!src && !dst)
		return (NULL);
	while (i < n)
	{
		d[i] = s[i];
		if (s[i] == find)
			return (d + (i + 1));
		i++;
	}
	return (NULL);
}

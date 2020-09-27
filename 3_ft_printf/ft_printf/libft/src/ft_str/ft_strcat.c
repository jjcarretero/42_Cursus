/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:18:37 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/25 13:41:33 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	while (src[j] != '\0')
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	destlen = ft_strlen(dest);
	srclen = ft_strlen(src);
	if (destlen + 1 > dstsize)
		return (srclen + dstsize);
	else if (destlen + 1 < dstsize)
	{
		while ((src[i] != 0) && (destlen + 1 + i < dstsize))
		{
			dest[destlen + i] = src[i];
			i++;
		}
	}
	dest[destlen + i] = 0;
	return (destlen + srclen);
}

char	*ft_strncat(char *dest, char *src, size_t nb)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
		i++;
	while (j < nb && src[j] != '\0')
	{
		dest[i] = src[j];
		j++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

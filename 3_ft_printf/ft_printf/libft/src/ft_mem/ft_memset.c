/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:08:54 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/02 00:17:29 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*pb;
	size_t			i;

	pb = (unsigned char *)b;
	i = 0;
	while (i < len)
		pb[i++] = (unsigned char)c;
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ps;
	size_t			i;

	ps = (unsigned char *)s;
	i = 0;
	while (i < n)
		ps[i++] = '\0';
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:47:04 by jcarrete          #+#    #+#             */
/*   Updated: 2020/07/23 16:47:08 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_itoa(int n)
{
	char	*r;
	char	s;
	size_t	len;
	int		i;

	s = (n < 0) ? -1 : 1;
	len = 2 + (n < 0);
	i = n;
	while ((n = n / 10))
		len++;
	if (!(r = (char *)malloc(sizeof(char) * len--)))
		return (NULL);
	r[len--] = '\0';
	r[len--] = s * (i % 10) + 48;
	while ((i = i / 10))
		r[len--] = s * (i % 10) + 48;
	if (s < 0)
		r[len] = '-';
	return (r);
}

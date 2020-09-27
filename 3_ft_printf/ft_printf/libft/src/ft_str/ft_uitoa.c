/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 12:45:27 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/11 12:45:53 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_uitoa(unsigned int n)
{
	char			*r;
	size_t			len;
	unsigned int	i;

	len = 2;
	i = n;
	while ((n = n / 10))
		len++;
	if (!(r = (char *)malloc(sizeof(char) * len--)))
		return (NULL);
	r[len--] = '\0';
	r[len--] = (i % 10) + 48;
	while ((i = i / 10))
		r[len--] = (i % 10) + 48;
	return (r);
}

char	*ft_ultoa(unsigned long n)
{
	char			*r;
	size_t			len;
	unsigned long	i;

	len = 2;
	i = n;
	while ((n = n / 10))
		len++;
	if (!(r = (char *)malloc(sizeof(char) * len--)))
		return (NULL);
	r[len--] = '\0';
	r[len--] = (i % 10) + 48;
	while ((i = i / 10))
		r[len--] = (i % 10) + 48;
	return (r);
}

char	*ft_ulltoa(unsigned long long n)
{
	char				*r;
	size_t				len;
	unsigned long long	i;

	len = 2;
	i = n;
	while ((n = n / 10))
		len++;
	if (!(r = (char *)malloc(sizeof(char) * len--)))
		return (NULL);
	r[len--] = '\0';
	r[len--] = (i % 10) + 48;
	while ((i = i / 10))
		r[len--] = (i % 10) + 48;
	return (r);
}

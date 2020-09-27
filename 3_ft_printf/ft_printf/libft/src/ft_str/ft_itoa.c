/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:47:04 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/11 12:48:49 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_itoa(int n)
{
	char	*r;
	char	s;
	int		len;
	long	i;

	s = (n < 0) ? -1 : 1;
	len = 2 + (n < 0);
	i = (long)n;
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

char	*ft_ltoa(long n)
{
	char	*r;
	char	s;
	size_t	len;
	long	i;

	if (n == LONG_MIN)
		return (ft_strdup("-9223372036854775808"));
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

char	*ft_lltoa(long long n)
{
	char		*r;
	char		s;
	size_t		len;
	long long	i;

	if (n == LLONG_MIN)
		return (ft_strdup("-9223372036854775808"));
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

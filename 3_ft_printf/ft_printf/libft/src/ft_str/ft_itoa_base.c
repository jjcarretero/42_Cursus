/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 23:14:43 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/02 00:19:03 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_itoa_base(int n, int base)
{
	char	*r;
	char	s;
	size_t	len;
	long	i;

	s = (n < 0) ? -1 : 1;
	len = 2 + (n < 0);
	i = (long)n;
	while ((n = n / base))
		len++;
	if (!(r = (char *)malloc(sizeof(char) * --len)))
		return (NULL);
	r[len--] = '\0';
	r[len--] = (s * (i % base) < 10) ? s * (i % base) + 48\
				: s * (i % base) + 87;
	while ((i = i / base))
		r[len--] = (s * (i % base) < 10) ? s * (i % base) + 48\
				: s * (i % base) + 87;
	if (s < 0)
		r[len] = '-';
	return (r);
}

char	*ft_ltoa_base(long n, int base)
{
	char	*r;
	char	s;
	size_t	len;
	long	i;

	s = (n < 0) ? -1 : 1;
	len = 2 + (n < 0);
	i = n;
	while ((n = n / base))
		len++;
	if (!(r = (char *)malloc(sizeof(char) * len--)))
		return (NULL);
	r[len--] = '\0';
	r[len--] = (s * (i % base) < 10) ? s * (i % base) + 48\
				: s * (i % base) + 87;
	while ((i = i / base))
		r[len--] = (s * (i % base) < 10) ? s * (i % base) + 48\
				: s * (i % base) + 87;
	if (s < 0)
		r[len] = '-';
	return (r);
}

char	*ft_uitoa_base(unsigned int n, int base)
{
	char			*r;
	size_t			len;
	unsigned int	i;

	len = 2;
	i = n;
	while ((n = n / (unsigned)base))
		len++;
	if (!(r = (char *)malloc(sizeof(char) * len--)))
		return (NULL);
	r[len--] = '\0';
	r[len--] = ((i % base) < 10) ? (i % base) + 48\
				: (i % base) + 87;
	while ((i = i / (unsigned)base))
		r[len--] = ((i % base) < 10) ? (i % base) + 48\
				: (i % base) + 87;
	return (r);
}

char	*ft_ultoa_base(unsigned long n, int base)
{
	char			*r;
	size_t			len;
	unsigned long	i;

	len = 2;
	i = n;
	while ((n = n / (unsigned)base))
		len++;
	if (!(r = (char *)malloc(sizeof(char) * len--)))
		return (NULL);
	r[len--] = '\0';
	r[len--] = ((i % base) < 10) ? (i % base) + 48\
				: (i % base) + 87;
	while ((i = i / (unsigned)base))
		r[len--] = ((i % base) < 10) ? (i % base) + 48\
				: (i % base) + 87;
	return (r);
}

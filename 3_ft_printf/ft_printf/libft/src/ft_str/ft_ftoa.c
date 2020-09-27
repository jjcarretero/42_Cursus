/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 22:05:30 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/02 00:19:03 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_ftoa(long double ld)
{
	char	*r;
	long	temp;
	int		len;
	int		s;

	s = (ld < 0) ? -1 : 1;
	len = (ld < 0);
	ld *= s;
	temp = (long)ld;
	while (temp > 0 && len++ >= 0)
		temp /= 10;
	while (ld - (long)ld != 0 && len++ >= 0)
		ld *= 10;
	r = ft_strnew(len);
	while (--len >= 0)
	{
		r[len] = (long)ld % 10 + 48;
		ld /= 10;
		if (s == -1 && len == 1)
		{
			r[0] = '-';
			break ;
		}
	}
	return (r);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/27 12:44:04 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/02 00:19:03 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

int		ft_wstrlen(wchar_t *wstr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (wstr[i])
	{
		if (wstr[i] <= 0x7F)
			len++;
		else if (wstr[i] >= 0x80 && wstr[i] <= 0x7FF)
			len += 2;
		else if (wstr[i] >= 0x800 && wstr[i] <= 0xFFFF)
			len += 3;
		else if (wstr[i] >= 0x10000 && wstr[i] <= 0x10FFFF)
			len += 4;
		i++;
	}
	return (len);
}

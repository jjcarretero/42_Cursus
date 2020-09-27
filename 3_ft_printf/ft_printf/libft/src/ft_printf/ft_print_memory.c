/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:25:57 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/02 00:17:29 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static char	hex_conv(unsigned char i)
{
	return (i <= 9 ? '0' + i : 'a' - 10 + i);
}

static void	puthex(unsigned char c)
{
	unsigned char p;
	unsigned char s;

	p = hex_conv(c / 16);
	s = hex_conv(c % 16);
	ft_putchar_fd(p, 1);
	ft_putchar_fd(s, 1);
}

static void	putstr(char *str, size_t start, size_t len)
{
	size_t i;

	i = 0;
	while ((start + i) < len && i < 16)
	{
		if (ft_isprint(str[i + start]))
			ft_putchar_fd(str[i + start], 1);
		else
			ft_putchar_fd('.', 1);
		i++;
	}
}

void		ft_print_memory(void *addr, size_t len)
{
	char	*str;
	size_t	l;
	size_t	i;

	str = addr;
	l = 0;
	while (l <= (len) / 16)
	{
		i = 0;
		while (i < 16)
		{
			if (i < len - (l * 16))
				puthex(str[i + (l * 16)]);
			else
				ft_putstr_fd("  ", 1);
			if (i % 4 == 3)
				ft_putchar_fd(' ', 1);
			i++;
		}
		putstr(str, l * 16, len);
		ft_putchar_fd('\n', 1);
		l++;
	}
}

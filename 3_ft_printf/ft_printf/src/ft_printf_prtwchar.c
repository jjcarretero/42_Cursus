/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prtwchar.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:25:59 by jcarrete          #+#    #+#             */
/*   Updated: 2020/08/12 13:25:59 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static void	encode_wchar(wchar_t wc)
{
	if (wc <= 0x7F)
		ft_putchar_fd(wc, 1);
	else if (wc >= 0x80 && wc <= 0x7FF)
	{
		ft_putchar_fd(((wc >> 6) + 0xC0), 1);
		ft_putchar_fd(((wc & 0x3F) + 0x80), 1);
	}
	else if (wc >= 0x800 && wc <= 0xFFFF)
	{
		ft_putchar_fd(((wc >> 12) + 0xE0), 1);
		ft_putchar_fd((((wc >> 6) & 0x3F) + 0x80), 1);
		ft_putchar_fd(((wc & 0x3F) + 0x80), 1);
	}
	else if (wc >= 0x10000 && wc <= 0x10FFFF)
	{
		ft_putchar_fd(((wc >> 18) + 0xF0), 1);
		ft_putchar_fd((((wc >> 12) & 0x3F) + 0x80), 1);
		ft_putchar_fd((((wc >> 6) & 0x3F) + 0x80), 1);
		ft_putchar_fd(((wc & 0x3F) + 0x80), 1);
	}
}

static void	ft_print_wchar(t_block *b, wchar_t wc)
{
	if (b->flags.f_minus)
	{
		encode_wchar(wc);
		(b->ret)++;
		ft_printf_prtwidth(b, 1);
	}
	else
	{
		ft_printf_prtwidth(b, 1);
		encode_wchar(wc);
		(b->ret)++;
	}
	(b->i)++;
}

void		ft_printf_prtwchar(t_block *b, char c)
{
	wchar_t	*wstr;
	wchar_t	wc;

	b->type = c;
	if (b->flags.f_minus)
		b->flags.f_zero = 0;
	if (b->type == 'c')
	{
		if ((wc = va_arg(b->ap, wchar_t)) == 0)
			return (ft_printf_prtnull(b));
		ft_print_wchar(b, wc);
	}
	else if (b->type == 's')
	{
		if (!(wstr = va_arg(b->ap, wchar_t *)))
			return (ft_printf_prtnull(b));
		ft_printf_prtwstr(b, wstr);
	}
}

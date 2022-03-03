/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 23:14:53 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/11 22:11:23 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static void	restart_block(t_block *b)
{
	b->type = '0';
	b->flags.neg = 0;
	b->flags.fltround = 0;
	b->flags.exp_add = 0;
	b->flags.f_blank = 0;
	b->flags.f_minus = 0;
	b->flags.f_pad = 0;
	b->flags.f_plus = 0;
	b->flags.f_zero = 0;
	b->flags.len_h = 0;
	b->flags.len_hh = 0;
	b->flags.len_l = 0;
	b->flags.len_ll = 0;
	b->flags.pre = -1;
	b->flags.width = 0;
}

int			ft_printf(const char *format, ...)
{
	t_block	b;

	ft_bzero(&b, sizeof(b));
	va_start(b.ap, format);
	while (format[b.i])
	{
		if (format[b.i] == '%')
		{
			b.i++;
			restart_block(&b);
			ft_printf_conv_flag(format, &b);
			ft_printf_conv_type(format, &b);
		}
		else
			b.ret += write(1, &format[b.i++], 1);
	}
	va_end(b.ap);
	return (b.ret);
}

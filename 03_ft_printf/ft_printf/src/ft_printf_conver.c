/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_conver.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 20:18:26 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/22 21:45:43 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void		ft_printf_conv_type(const char *format, t_block *b)
{
	if (format[b->i] == '%')
		ft_printf_prtpct(b);
	else if (format[b->i] == 'c' || format[b->i] == 's')
		if (b->flags.len_l == 0)
			ft_printf_prtchar(b, format[b->i]);
		else
			ft_printf_prtwchar(b, format[b->i]);
	else if (format[b->i] == 'p')
		ft_printf_prtpoint(b);
	else if (format[b->i] == 'd' || format[b->i] == 'i')
		ft_printf_prtint(b);
	else if (format[b->i] == 'u')
		ft_printf_prtuint(b);
	else if (format[b->i] == 'x' || format[b->i] == 'X')
		ft_printf_prthex(b, format[b->i]);
	else if (format[b->i] == 'n')
		ft_printf_prtret(b);
	else if (format[b->i] == 'f' || format[b->i] == 'g' ||\
			format[b->i] == 'e' || format[b->i] == 'G' || format[b->i] == 'E')
		ft_printf_parseflt(b, format[b->i]);
	else if (format[b->i] == 'o')
		ft_printf_prtoct(b, format[b->i]);
	else if (format[b->i] != '\0')
		ft_printf_noprt(b, format[b->i]);
}

static void	flag_pre(const char *format, t_block *b)
{
	if (b->flags.pre >= 0)
	{
		(b->i)++;
		return ;
	}
	if (format[b->i] == '.' && format[b->i + 1] == '*')
	{
		b->flags.pre = va_arg(b->ap, int);
		b->i += 2;
	}
	else if (format[b->i] == '.')
	{
		(b->i)++;
		b->flags.pre = ft_atoi(format + (b->i));
		while (ft_isdigit(format[b->i]))
			(b->i)++;
	}
}

static void	flag_len(const char *format, t_block *b)
{
	if (format[b->i] == 'h' && format[b->i + 1] != 'h')
		b->flags.len_h = 1;
	else if (format[b->i] == 'h' && format[b->i + 1] == 'h')
	{
		b->flags.len_hh = 1;
		(b->i)++;
	}
	else if (format[b->i] == 'l' && format[b->i + 1] != 'l')
		b->flags.len_l = 1;
	else if (format[b->i] == 'l' && format[b->i + 1] == 'l')
	{
		b->flags.len_ll = 1;
		(b->i)++;
	}
}

static void	flag_width(t_block *b)
{
	b->flags.width = va_arg(b->ap, int);
	if (b->flags.width < 0)
	{
		b->flags.width *= -1;
		b->flags.f_minus = 1;
	}
}

void		ft_printf_conv_flag(const char *format, t_block *b)
{
	while (ft_strchr(PRINTF_FLAG, format[b->i]) && format[b->i] != '\0')
	{
		format[b->i] == '0' ? b->flags.f_zero = 1 : 0;
		format[b->i] == '+' ? b->flags.f_plus = 1 : 0;
		format[b->i] == '-' ? b->flags.f_minus = 1 : 0;
		format[b->i] == '#' ? b->flags.f_pad = 1 : 0;
		format[b->i] == ' ' ? b->flags.f_blank = 1 : 0;
		format[b->i] == '*' ? flag_width(b) : 0;
		format[b->i] == 'l' || format[b->i] == 'h'\
			? flag_len(format, b) : 0;
		if (format[b->i] == '.')
			flag_pre(format, b);
		else if ((format[b->i] >= 49 && format[b->i] <= 57)\
			&& b->flags.pre < 0)
		{
			b->flags.width = ft_atoi(format + (b->i));
			while (format[b->i] >= 48 && format[b->i] <= 57)
				(b->i)++;
		}
		else
			(b->i)++;
	}
}

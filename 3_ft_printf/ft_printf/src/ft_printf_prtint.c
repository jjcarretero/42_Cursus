/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prtint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/15 00:04:26 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/11 12:49:53 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/ft_printf.h"

static void	print_digit_sign(t_block *b)
{
	if (b->flags.f_plus)
		b->ret += write(1, "+", 1);
	else if (b->flags.f_blank)
		b->ret += write(1, " ", 1);
	else if (b->flags.neg)
		b->ret += write(1, "-", 1);
}

static void	negative_number(t_block *b)
{
	char	*temp;

	if (b->s[0] == '-')
	{
		temp = ft_strdup((b->s) + 1);
		b->s = ft_memfree(b->s, temp);
		b->flags.neg = 1;
		b->flags.f_plus = 0;
		b->flags.f_blank = 0;
	}
}

static void	check_precision(t_block *b)
{
	int		len;
	char	*temp;
	char	*r;

	negative_number(b);
	len = ft_strlen(b->s);
	if (b->flags.pre == 0 && b->s[0] == '0')
		b->s[0] = '\0';
	else if (b->flags.pre == 0)
		b->flags.pre = 1;
	else if (len < b->flags.pre)
	{
		temp = ft_strnew(b->flags.pre - len);
		ft_memset(temp, '0', (b->flags.pre - len));
		r = ft_strjoin(temp, b->s);
		b->s = ft_memfree(b->s, r);
		temp = ft_memfree(temp, NULL);
	}
}

void		ft_printf_prtdig(t_block *b)
{
	check_precision(b);
	if (b->flags.f_minus)
	{
		print_digit_sign(b);
		b->ret += write(1, b->s, ft_strlen(b->s));
		ft_printf_prtintwidth(b);
	}
	else if (b->flags.f_zero)
	{
		print_digit_sign(b);
		ft_printf_prtintwidth(b);
		b->ret += write(1, b->s, ft_strlen(b->s));
	}
	else
	{
		ft_printf_prtintwidth(b);
		print_digit_sign(b);
		b->ret += write(1, b->s, ft_strlen(b->s));
	}
	(b->i)++;
	b->s = ft_memfree(b->s, NULL);
}

void		ft_printf_prtint(t_block *b)
{
	long long	temp;

	if (b->flags.f_minus || b->flags.pre >= 0)
		b->flags.f_zero = 0;
	if (b->flags.len_l || b->flags.len_ll)
	{
		temp = va_arg(b->ap, long long);
		if (temp == LONG_MIN || temp == LLONG_MIN)
			b->s = ft_strdup("-9223372036854775808");
		else if (b->flags.len_l)
			b->s = ft_ltoa((long)temp);
		else
			b->s = ft_lltoa(temp);
	}
	else
	{
		temp = va_arg(b->ap, signed int);
		if (b->flags.len_h)
			b->s = ft_itoa((signed short)temp);
		else if (b->flags.len_hh)
			b->s = ft_itoa((signed char)temp);
		else
			b->s = ft_itoa((signed int)temp);
	}
	ft_printf_prtdig(b);
}

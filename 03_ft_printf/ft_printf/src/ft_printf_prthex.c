/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prthex.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 13:05:54 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/22 23:01:56 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static void	ft_printf_prtbase_width(t_block *b)
{
	int	len;
	int	i;

	i = 0;
	len = ft_strlen(b->s);
	if (b->flags.f_pad && (b->s[0] != '\0'\
		&& ((int)ft_strchr_count(b->s, '0') != len)))
		if (b->type != 'o')
			b->flags.width -= 2;
	if (b->flags.pre >= 0)
	{
		while (b->flags.width > b->flags.pre + i &&\
			b->flags.width > len + i)
		{
			b->ret += write(1, " ", 1);
			i++;
		}
		while (b->flags.width > len + i)
		{
			b->ret += write(1, "0", 1);
			i++;
		}
	}
	else
		ft_printf_prtwidth(b, len);
}

static void	ft_printf_prtbase_ini(t_block *b, long l)
{
	if (b->flags.f_pad && l != 0 && b->s[0] != '\0')
	{
		if (b->type == 'x')
			b->ret += write(1, "0x", 2);
		else if (b->type == 'X')
			b->ret += write(1, "0X", 2);
	}
}

void		ft_printf_prtbase(t_block *b, long l)
{
	if (b->flags.f_minus)
	{
		ft_printf_prtbase_ini(b, l);
		b->ret += write(1, b->s, ft_strlen(b->s));
		ft_printf_prtbase_width(b);
	}
	else if ((b->flags.f_zero && b->flags.f_pad == 0) ||\
			(b->flags.f_zero && b->flags.f_pad && b->flags.pre < 0))
	{
		ft_printf_prtbase_ini(b, l);
		ft_printf_prtbase_width(b);
		b->ret += write(1, b->s, ft_strlen(b->s));
	}
	else
	{
		ft_printf_prtbase_width(b);
		ft_printf_prtbase_ini(b, l);
		b->ret += write(1, b->s, ft_strlen(b->s));
	}
	(b->i)++;
	b->s = ft_memfree(b->s, NULL);
}

void		ft_printf_basepre(t_block *b)
{
	int		len;
	char	*temp;
	char	*r;

	if (b->flags.f_minus)
		b->flags.f_zero = 0;
	if (b->type == 'X')
	{
		temp = ft_str_toupper(b->s);
		b->s = ft_memfree(b->s, temp);
	}
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

void		ft_printf_prthex(t_block *b, char c)
{
	unsigned long long	temp;
	unsigned long long	ul;

	b->type = c;
	if (b->flags.len_l || b->flags.len_ll)
	{
		temp = va_arg(b->ap, unsigned long long);
		if (b->flags.len_l)
			ul = (unsigned long)temp;
		else
			ul = temp;
	}
	else
	{
		temp = va_arg(b->ap, unsigned int);
		if (b->flags.len_h)
			ul = (unsigned short)temp;
		else if (b->flags.len_hh)
			ul = (unsigned char)temp;
		else
			ul = (unsigned int)temp;
	}
	b->s = ft_ultoa_base(ul, 16);
	ft_printf_basepre(b);
	ft_printf_prtbase(b, (long)ul);
}

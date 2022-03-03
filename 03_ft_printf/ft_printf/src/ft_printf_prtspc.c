/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prtspc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 23:01:21 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/11 16:23:32 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	ft_printf_noprt(t_block *b, char c)
{
	if (b->flags.f_minus)
	{
		b->ret += write(1, &c, 1);
		ft_printf_prtwidth(b, 1);
	}
	else
	{
		ft_printf_prtwidth(b, 1);
		b->ret += write(1, &c, 1);
	}
	(b->i)++;
}

void	ft_printf_prtnull(t_block *b)
{
	int len;

	if (b->type == 'c')
	{
		if (b->flags.f_minus)
			b->ret += write(1, "\0", 1);
		ft_printf_prtwidth(b, 1);
		if (!(b->flags.f_minus))
			b->ret += write(1, "\0", 1);
		(b->i)++;
	}
	else if (b->type == 's')
	{
		len = ((b->flags.pre < 0) || (b->flags.pre > 6)\
					? 6 : b->flags.pre);
		if (b->flags.f_minus)
			b->ret += write(1, "(null)", len);
		ft_printf_prtwidth(b, len);
		if (!(b->flags.f_minus))
			b->ret += write(1, "(null)", len);
		(b->i)++;
	}
}

void	ft_printf_prtpct(t_block *b)
{
	if (b->flags.f_minus)
	{
		b->flags.f_zero = 0;
		b->ret += write(1, "%", 1);
	}
	ft_printf_prtwidth(b, 1);
	if (!(b->flags.f_minus))
		b->ret += write(1, "%", 1);
	(b->i)++;
}

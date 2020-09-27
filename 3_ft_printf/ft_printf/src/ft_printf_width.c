/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:37:55 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/19 22:31:50 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void	ft_printf_prtflt_width(t_block *b)
{
	int	len;

	len = ft_strlen(b->s) +\
		(b->flags.f_plus) + (b->flags.f_blank) + (b->flags.neg);
	if (((b->flags.f_plus) || (b->flags.f_blank)) && (b->flags.neg))
		len--;
	if ((b->flags.f_plus) && (b->flags.f_blank))
		len--;
	ft_printf_prtwidth(b, len);
	if (b->flags.pre >= 0)
		len -= ((b->flags.f_plus) + (b->flags.f_blank) + (b->flags.neg));
	while ((int)ft_strlen(b->s) < len)
	{
		b->ret += write(1, "0", 1);
		len--;
	}
}

void	ft_printf_prtintwidth(t_block *b)
{
	int	len;

	len = ft_max(ft_strlen(b->s), b->flags.pre);
	if (b->flags.f_plus || b->flags.f_blank || b->flags.neg)
		b->flags.width--;
	if (b->flags.pre < 0)
		ft_printf_prtwidth(b, len);
	else
	{
		while ((b->flags.width) > len)
		{
			b->ret += write(1, " ", 1);
			b->flags.width--;
		}
		while (((int)ft_strlen(b->s)) < len)
		{
			b->ret += write(1, "0", 1);
			len--;
		}
	}
}

void	ft_printf_prtwidth(t_block *b, int len)
{
	while ((b->flags.width) > len)
	{
		if (b->flags.f_zero)
			b->ret += write(1, "0", 1);
		else
			b->ret += write(1, " ", 1);
		(b->flags.width)--;
	}
}

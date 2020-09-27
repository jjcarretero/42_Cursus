/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 15:42:14 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/22 22:55:04 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void		ft_printf_check_inf(t_block *b, double temp)
{
	b->flags.f_zero = 0;
	if (temp != temp)
	{
		b->flags.f_plus = 0;
		b->flags.f_blank = 0;
		b->s = ft_strdup("nan");
	}
	else if (temp * 2 == temp && temp != 0)
		b->s = ft_strdup("inf");
	ft_printf_prtfloat(b);
}

void		ft_printf_check_pre(t_block *b, char **flo)
{
	int		len;
	char	*temp;

	len = (int)ft_strlen(*flo);
	if (b->type == 'e' || b->type == 'E')
		len -= (4 + b->flags.exp_add);
	temp = ft_strappstart_nchr(*flo, '0', (b->flags.pre - len));
	*flo = ft_memfree(*flo, temp);
}

void		ft_printf_prtflt_pre(t_block *b, char **flo)
{
	int		len;
	char	*temp;

	len = (int)ft_strlen(*flo);
	temp = ft_strappstart_nchr(*flo, '0', (b->flags.pre - len));
	*flo = ft_memfree(*flo, temp);
}

void		ft_printf_prtflt_sign(t_block *b)
{
	if (b->flags.f_minus)
		b->flags.f_zero = 0;
	if (b->flags.neg)
		b->ret += write(1, "-", 1);
	else if ((b->flags.f_plus))
		b->ret += write(1, "+", 1);
	else if (b->flags.f_blank)
		b->ret += write(1, " ", 1);
}

void		ft_printf_prtfloat(t_block *b)
{
	if (b->flags.f_minus)
	{
		ft_printf_prtflt_sign(b);
		b->ret += write(1, b->s, ft_strlen(b->s));
		ft_printf_prtflt_width(b);
	}
	else if (b->flags.f_zero)
	{
		ft_printf_prtflt_sign(b);
		ft_printf_prtflt_width(b);
		b->ret += write(1, b->s, ft_strlen(b->s));
	}
	else
	{
		ft_printf_prtflt_width(b);
		ft_printf_prtflt_sign(b);
		b->ret += write(1, b->s, ft_strlen(b->s));
	}
	(b->i)++;
	b->s = ft_memfree(b->s, NULL);
}

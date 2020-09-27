/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prtret.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 16:22:55 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/11 16:23:52 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static void	ft_printf_prtret_length(t_block *b)
{
	long int		*l_temp;
	long long int	*ll_temp;
	short int		*s_temp;
	char			*c_temp;

	if (b->flags.len_l)
	{
		l_temp = va_arg(b->ap, long *);
		*l_temp = b->ret;
	}
	else if (b->flags.len_ll)
	{
		ll_temp = va_arg(b->ap, long long *);
		*ll_temp = b->ret;
	}
	else if (b->flags.len_h)
	{
		s_temp = (short *)va_arg(b->ap, int *);
		*s_temp = b->ret;
	}
	else if (b->flags.len_hh)
	{
		c_temp = (char *)va_arg(b->ap, int *);
		*c_temp = b->ret;
	}
}

void		ft_printf_prtret(t_block *b)
{
	int				*temp;

	if (b->flags.len_l || b->flags.len_ll ||\
		b->flags.len_h || b->flags.len_hh)
		ft_printf_prtret_length(b);
	else
	{
		temp = (int *)va_arg(b->ap, int *);
		*temp = b->ret;
	}
	(b->i)++;
}

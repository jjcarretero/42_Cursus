/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prtfloat.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 21:32:06 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/22 21:40:14 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static void			ft_printf_getfloat_floatstr(t_block *b, char *flo,\
											int j, int dot_bool)
{
	int i;

	if (b->flags.f_pad && dot_bool == 0)
		(b->s)[j++] = '.';
	i = 0;
	while (flo[i] != '\0')
		(b->s)[j++] = flo[i++];
}

void				ft_printf_getfloat_str(t_block *b, char *nb,\
											char *flo, int len)
{
	int		i;
	int		j;
	int		pre;
	int		dot_bool;

	i = 0;
	j = 0;
	dot_bool = 0;
	pre = b->flags.pre + ft_strlen(flo) + (b->flags.pre == 1);
	while (nb[i] != '\0')
	{
		(b->s)[j++] = nb[i];
		if (((i == (len - 1)) && pre >= 0) && dot_bool == 0)
		{
			(b->s)[j++] = '.';
			dot_bool = 1;
		}
		if (i >= pre)
		{
			(b->s)[j] = '\0';
			break ;
		}
		i++;
	}
	ft_printf_getfloat_floatstr(b, flo, j, dot_bool);
}

void				ft_printf_round_flt(t_block *b, long double ld,\
					unsigned long long *num, unsigned long long *f_num)
{
	double				dtemp;
	unsigned long long	utemp;

	dtemp = *f_num;
	utemp = *f_num;
	if (b->flags.pre <= 0)
	{
		if (*num + 0.5 < ld)
			*num += 1;
		else if (*num + 0.5 == ld)
			if ((*num % 10) % 2 || b->flags.pre == 1)
				*num += 1;
		return ;
	}
	if (((utemp + 0.5) * ft_float_power(18, 10)) <\
		(ld - *num) * ft_float_power(b->flags.pre + 18, 10))
		utemp = (utemp + 1) % (long)ft_float_power(b->flags.pre, 10);
	else if (utemp + 0.5 == (ld - *num) * ft_float_power(b->flags.pre, 10))
		if ((utemp % 10) % 2 || b->flags.pre == 1)
			utemp = (utemp + 1) % (long)ft_float_power(b->flags.pre, 10);
	if (!utemp && dtemp)
		*num += 1;
	*f_num = utemp;
}

void				ft_printf_flopoint(t_block *b, long double ld)
{
	char				*flo;
	char				*nb;
	unsigned long long	f_num;
	unsigned long long	num;

	num = (unsigned long long)ft_absf(ld);
	f_num = ((double)((ft_float_power(b->flags.pre, 10)) * ft_absf(ld))\
				- ((ft_float_power(b->flags.pre, 10)) * num));
	ft_printf_round_flt(b, ft_absf(ld), &num, &f_num);
	nb = ft_ulltoa(num);
	flo = ft_ulltoa(f_num);
	ft_printf_check_pre(b, &flo);
	if (b->flags.pre == 0)
	{
		nb = (b->flags.f_pad) ? ft_strappend_nchr(nb, '.', 1) : nb;
		b->s = ft_strdup(nb);
	}
	else
	{
		b->s = ft_strnew(ft_strlen(nb) + 1 + ft_strlen(flo));
		ft_printf_getfloat_str(b, nb, flo, ft_strlen(nb));
	}
	nb = ft_memfree(nb, NULL);
	flo = ft_memfree(flo, NULL);
	ft_printf_prtfloat(b);
}

void				ft_printf_parseflt(t_block *b, char c)
{
	double	temp;

	b->type = c;
	b->flags.pre = (b->flags.pre > -1) ? b->flags.pre : 6;
	temp = va_arg(b->ap, double);
	if (signbit(temp))
		b->flags.neg = 1;
	if (temp != temp || (temp * 2 == temp && temp != 0))
		ft_printf_check_inf(b, temp);
	else if (b->type == 'f')
		ft_printf_flopoint(b, temp);
	else if (b->type == 'e' || b->type == 'E')
		ft_printf_prtexp(b, temp);
	else if (b->type == 'g' || b->type == 'G')
		ft_printf_prtdecexp(b, temp);
}

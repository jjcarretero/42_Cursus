/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prtdecexp.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:54:23 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/22 21:42:13 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

static void	printf_prtgdec(t_block *b, long double ld)
{
	char				*flo;
	char				*nb;
	unsigned long long	f_num;
	unsigned long long	num;

	num = (unsigned long long)ft_absf(ld);
	f_num = ((ft_float_power(b->flags.pre, 10)) * ft_absf(ld))\
				- ((ft_float_power(b->flags.pre, 10)) * num);
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
}

static void	printf_prtgexp(t_block *b, long double ld)
{
	double				absd;
	int					e;
	unsigned long long	num;
	unsigned long long	f_num;

	if (ld < 0)
		b->flags.neg = 1;
	absd = ft_absf(ld);
	num = (unsigned long long)ft_printf_getexp_long(b, ld, &e);
	f_num = (e > 292) ? ((absd * ft_float_power(e - 1, 10) * 10) -
		(unsigned long long)(absd * ft_float_power(e - 1, 10) * 10))
		* ft_float_power(15, 10)
		: absd * ft_float_power(15 + e, 10) -
		(unsigned long long)(absd * ft_float_power(e, 10)) *
		ft_float_power(15, 10);
	if (b->flags.fltround)
		f_num = 0;
	ft_printf_round_exp(b, &e, &num, &f_num);
	if (ft_abs(e) > 99)
		b->flags.exp_add = ft_digits_long(e) - 2;
	ft_printf_expstr(b, num, e, f_num);
}

static int	check_nines(t_block *b, long double ld)
{
	long double		nb;
	int				i;
	unsigned long	rec;

	i = 0;
	rec = 9;
	nb = ld;
	while (i <= (b->flags.pre - 1) && ((unsigned long)nb == rec))
	{
		i++;
		nb *= 10;
		rec = rec * 10 + 9;
	}
	if (i == b->flags.pre && (unsigned long)nb > rec - 5)
		return (1);
	return (0);
}

static void	ft_printf_gtoef(t_block *b, long double ld, int e)
{
	if (ld > 9 && check_nines(b, ld))
		e++;
	while (ld > 0 && ld < 1)
	{
		e = e - 1;
		ld *= 10;
	}
	while (ld >= 10)
	{
		e = e + 1;
		ld /= 10;
	}
	if (e < -4 || e >= b->flags.pre)
	{
		b->type = (b->type == 'g') ? 'e' : 'E';
		b->flags.pre--;
	}
	else
	{
		b->type = 'f';
		b->flags.pre = b->flags.pre - (e + 1);
	}
}

void		ft_printf_prtdecexp(t_block *b, long double ld)
{
	int		e;

	if (b->flags.pre == 0)
		b->flags.pre = 1;
	if (ld < 0)
		b->flags.neg = 1;
	e = 0;
	ft_printf_gtoef(b, ft_absf(ld), e);
	if (b->type == 'f')
	{
		printf_prtgdec(b, ft_absf(ld));
		if (!(b->flags.f_pad))
			ft_printf_trimzeros_f(b);
	}
	else if (b->type == 'e' || b->type == 'E')
	{
		printf_prtgexp(b, ft_absf(ld));
		if (!(b->flags.f_pad))
			ft_printf_trimzeros_e(b);
	}
	ft_printf_prtfloat(b);
}

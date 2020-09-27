/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prtexp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 11:45:18 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/22 22:36:44 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

char				*ft_printf_getexp(int e, unsigned long long f_num)
{
	char	*temp1;
	char	*temp2;
	char	*exp;
	char	*flo;
	char	*r;

	if (e < 0)
		temp1 = ft_strjoin("e", e < -9 ? "-" : "-0");
	else
		temp1 = ft_strjoin("e", e > 9 ? "+" : "+0");
	temp2 = ft_itoa(ft_abs(e));
	exp = ft_strjoin(temp1, temp2);
	temp1 = ft_memfree(temp1, NULL);
	temp2 = ft_memfree(temp2, NULL);
	if (f_num)
	{
		flo = ft_ftoa(f_num);
		r = ft_strjoin(flo, exp);
		exp = ft_memfree(exp, NULL);
		flo = ft_memfree(flo, NULL);
		return (r);
	}
	return (exp);
}

double				ft_printf_getexp_long(t_block *b, double dob, int *exp)
{
	long double			num;
	int					e;

	num = ft_absf(dob);
	e = 0;
	if (num == 0)
		return (0);
	while (num > 0 && num < 1)
	{
		num *= 10;
		e++;
	}
	if (num >= 9 && num < 10)
		ft_printf_roundnine(b, &num);
	while (num >= 10)
	{
		num /= 10;
		e--;
	}
	*exp = e;
	return (num);
}

void				ft_printf_expstr(t_block *b, unsigned long long num,\
						int e, unsigned long long f_num)
{
	char				*nb;
	char				*exp;
	char				*temp;

	exp = ft_printf_getexp(-e, f_num);
	if (b->type == 'E')
	{
		temp = ft_str_toupper(exp);
		exp = ft_memfree(exp, temp);
	}
	ft_printf_check_pre(b, &exp);
	nb = ft_ulltoa(num);
	if (b->flags.pre == 0)
	{
		nb = (b->flags.f_pad) ? ft_strappend_nchr(nb, '.', 1) : nb;
		b->s = ft_strjoin(nb, exp);
	}
	else
	{
		b->s = ft_strnew(ft_strlen(nb) + 1 + ft_strlen(exp));
		ft_printf_getfloat_str(b, nb, exp, ft_strlen(nb));
	}
	nb = ft_memfree(nb, NULL);
	exp = ft_memfree(exp, NULL);
}

void				ft_printf_round_exp(t_block *b, int *e,\
			unsigned long long *num, unsigned long long *f_num)
{
	unsigned long long	nb;
	unsigned long long	flo;
	long long			l_nb;
	long long			l_flo;
	int					rec;

	rec = 0;
	flo = *num * ft_float_power(b->flags.pre, 10) +
		*f_num / ft_float_power(15 - b->flags.pre, 10);
	nb = (*num * ft_float_power(b->flags.pre + 1, 10)) +
		(*f_num / ft_float_power(15 - b->flags.pre - 1, 10));
	l_nb = flo;
	l_flo = *f_num - (long long)(*f_num / ft_float_power(15 - b->flags.pre, 10))
		* ft_float_power(15 - b->flags.pre, 10);
	if (5 * ft_float_power(15 - b->flags.pre - 1, 10) < l_flo)
		nb = flo++;
	else if (5 * ft_float_power(15 - b->flags.pre - 1, 10) == l_flo)
		if (((l_nb % 10) % 2) || b->flags.pre == 1)
			nb = flo++;
	rec = ft_printf_check_exp(b, nb, flo, e);
	*num = flo / (unsigned long long)ft_float_power(b->flags.pre, 10);
	*f_num = flo % (unsigned long long)ft_float_power(b->flags.pre, 10);
	if (rec != 0)
		b->flags.pre--;
}

void				ft_printf_prtexp(t_block *b, double dob)
{
	double				absd;
	int					e;
	unsigned long long	num;
	unsigned long long	f_num;

	if (dob < 0)
		b->flags.neg = 1;
	absd = ft_absf(dob);
	num = (unsigned long long)ft_printf_getexp_long(b, dob, &e);
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
	ft_printf_prtfloat(b);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_eg.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 19:41:21 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/22 23:10:54 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"
#include "../includes/libft.h"

void		ft_printf_roundnine(t_block *b, long double *num)
{
	long double		nb;
	int				i;
	unsigned long	rec;

	i = 0;
	rec = 9;
	nb = *num;
	while (i <= b->flags.pre && ((unsigned long)nb == rec))
	{
		i++;
		nb *= 10;
		rec = rec * 10 + 9;
	}
	if (i == (b->flags.pre + 1) && (unsigned long)nb > rec - 5)
	{
		*num = 10.0;
		b->flags.fltround = 1;
	}
}

int			ft_printf_check_exp(t_block *b, unsigned long long nb,\
				unsigned long long flo, int *e)
{
	int	floexp;
	int	nbexp;

	floexp = 0;
	nbexp = 0;
	while (nb)
	{
		nb = nb / 10;
		nbexp++;
	}
	while (flo)
	{
		flo = flo / 10;
		floexp++;
	}
	if (floexp > nbexp)
	{
		*e = *e - 1;
		b->flags.pre++;
		return (1);
	}
	return (0);
}

void		ft_printf_trimzeros_f(t_block *b)
{
	int		i;

	i = 0;
	while ((b->s)[i] != '.' && (b->s)[i])
		i++;
	if (i == (int)ft_strlen(b->s))
		return ;
	i = ft_strlen(b->s) - 1;
	while (i >= 0 && (b->s)[i] == '0')
		(b->s)[i--] = '\0';
	ft_strempt_endchar(b->s, '.');
}

void		ft_printf_trimzeros_e(t_block *b)
{
	int		i;
	char	*exp;
	char	*res;
	int		elong;

	i = 0;
	i = ft_strlen(b->s) - 5;
	elong = 4 + b->flags.exp_add;
	exp = ft_strnew(elong + 1);
	exp = ft_strncpy(exp, b->s + (i + 1), elong);
	b->s[i + 1] = '\0';
	while (i >= 0 && b->s[i] == '0')
		(b->s)[i--] = '\0';
	ft_strempt_endchar(b->s, '.');
	res = ft_strjoin(b->s, exp);
	b->s = ft_memfree(b->s, res);
	exp = ft_memfree(exp, NULL);
}

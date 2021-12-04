/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/08 23:14:10 by jcarrete          #+#    #+#             */
/*   Updated: 2021/04/11 22:42:09 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <wchar.h>
# include <math.h>

/*
** MACROS
*/

# define PRINTF_FLAG "0123456789-.*# +hl"

/*
** Structs
*/

typedef struct s_flags
{
	int			f_zero;
	int			f_plus;
	int			f_minus;
	int			f_pad;
	int			f_blank;

	int			neg;
	int			width;
	int			pre;
	int			fltround;
	int			exp_add;

	int			len_h;
	int			len_hh;
	int			len_l;
	int			len_ll;
}					t_flags;

typedef struct s_block
{
	char		*s;
	char		type;
	int			i;
	va_list		ap;
	t_flags		flags;
	int			ret;
	int			fd;
}					t_block;

/*
**Source Files
*/

int					ft_printf(const char *format, ...);
int					ft_dprintf(int fd, const char *format, ...);
void				ft_printf_basepre(t_block *b);
int					ft_printf_check_exp(t_block *b, unsigned long long nb, \
						unsigned long long flo, int *e);
void				ft_printf_check_inf(t_block *b, double temp);
void				ft_printf_check_pre(t_block *b, char **flo);
void				ft_printf_conv_flag(const char *format, t_block *b);
void				ft_printf_conv_type(const char *format, t_block *b);
char				*ft_printf_create_exponent(int e);
void				ft_printf_expstr(t_block *b, unsigned long long whole, \
						int e, unsigned long long f_num);
void				ft_printf_flopoint(t_block *b, long double ld);
char				*ft_printf_getfloat_nb(t_block *b, long double ld);
void				ft_printf_getfloat_str(t_block *b, char *nb, \
						char *flo, int len);
char				*ft_printf_getexp(int e, unsigned long long f_num);
double				ft_printf_getexp_long(t_block *b, double dob, int *exp);
void				ft_printf_noprt(t_block *b, char c);
void				ft_printf_prtbase(t_block *b, long l);
void				ft_printf_prtchar(t_block *b, char c);
void				ft_printf_prtdecexp(t_block *b, long double ld);
void				ft_printf_prtdig(t_block *b);
void				ft_printf_prtexp(t_block *b, double dob);
void				ft_printf_parseflt(t_block *b, char c);
void				ft_printf_prtfloat(t_block *b);
void				ft_printf_prtflt_sign(t_block *b);
void				ft_printf_prtflt_width(t_block *b);
void				ft_printf_prthex(t_block *b, char c);
void				ft_printf_prtint(t_block *b);
void				ft_printf_prtintwidth(t_block *b);
void				ft_printf_prtnull(t_block *b);
void				ft_printf_prtoct(t_block *b, char c);
void				ft_printf_prtpct(t_block *b);
void				ft_printf_prtpoint(t_block *b);
void				ft_printf_prtret(t_block *b);
void				ft_printf_prtuint(t_block *b);
void				ft_printf_prtwchar(t_block *b, char c);
void				ft_printf_prtwidth(t_block *b, int len);
void				ft_printf_prtwstr(t_block *b, wchar_t *wstr);
void				ft_printf_roundnine(t_block *b, long double *num);
void				ft_printf_round_exp(t_block *b, int *e, \
						unsigned long long *num, unsigned long long *f_num);
void				ft_printf_round_flt(t_block *b, long double ld, \
						unsigned long long *num, unsigned long long *f_num);
void				ft_printf_trimzeros_e(t_block *b);
void				ft_printf_trimzeros_f(t_block *b);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 13:04:51 by jcarrete          #+#    #+#             */
/*   Updated: 2020/10/01 19:51:22 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Assignment name  : ft_printf
**	Expected files   : ft_printf.c
**	Allowed functions: malloc, free, write, va_start, va_arg, va_copy, va_end
**	--------------------------------------------------------------------------------
**
**	Write a function named `ft_printf` that will mimic the real printf with the following constraints:
**
**	- It will manage only the following conversions: s,d and x
**	- It will manage the minimum field width. (we will never test with a field with of 0)
**	- It will manage only the precison flag `.`.
**
**	Your function must be declared as follows:
**
**	int ft_printf(const char *, ... );
**
**	Before you start we advise you to read the `man 3 printf` and the `man va_arg`.
**	To test your program compare your results with the true printf.
**
**	Exemples of the function output:
**
**	call: ft_printf("%10.2s\n", "toto");
**	out:        to$
**
**	call: ft_printf("Magic %s is %5d", "number", 42);
**	out:Magic number is    42%
**
**	call: ft_printf("Hexadecimal for %d is %x\n", 42, 42);
**	out:Hexadecimal for 42 is 2a$
*/

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

/*
**	////////////////////////////// STRUCT //////////////////////////////
*/

typedef struct		s_block
{
	int		i;
	char	*s;
	va_list	ap;
	int		ret;

	char	type;
	int		width;
	int		prec;
	int		sign;
}					t_block;

/*
**	////////////////////////// UTIL FUNCTIONS //////////////////////////
*/

char				*ltoa_base(long n, int base)
{
	int		len;
	char	*ret;
	long	i;

	len = 2;
	i = n;
	while ((i = i / base))
		len++;
	if (!(ret = (char *)malloc(sizeof(char) * len--)))
		return (NULL);
	ret[len--] = '\0';
	ret[len--] = ((n % base) < 10) ? (n % base) + '0': (n % base) + 'W';
	while ((n = n / base))
		ret[len--] = ((n % base) < 10) ? (n % base) + '0': (n % base) + 'W';
	return(ret);
}

char				*ft_strdup(char *src)
{
	char	*dest;
	int		i;

	if (!src)
		return (NULL);
	i = 0;
	while (src[i])
		i++;
	if (!(dest = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char				*ft_str_append_start(t_block *b, int len, char c)
{
	int		n_chars;
	int		i;
	int		j;
	char	*ret;

	n_chars = b->prec - len;
	if (!(ret = (char *)malloc(sizeof(char) * (len + n_chars + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (n_chars-- > 0)
		ret[i++] = c;
	while ((b->s)[j])
		ret[i++] = (b->s)[j++];
	ret[i] = '\0';
	free(b->s);
	return (ret);
}

/*
**	////////////////////////// MAIN FUNCTIONS //////////////////////////
*/

static void			ft_printf_check_precision(t_block *b)
{
	int	len;

	len = 0;
	while ((b->s)[len])
		len++;
	if ((b->prec > len) && b->type != 's')
		b->s = ft_str_append_start(b, len, '0');
	else if ((b->prec > -1 && b->prec < len) && b->type == 's')
		(b->s)[b->prec] = '\0';
	else if (b->prec == 0 && (b->s)[0] == '0')
		(b->s)[0] = '\0';
}

static void			ft_printf_conv_type(const char *format, t_block *b)
{
	char	*temp;
	long	long_temp;

	b->type = format[b->i];
	if (b->type == 's')
	{
		if (!(temp = va_arg(b->ap, char *)))
			b->s = ft_strdup("(null)");
		else
			b->s = ft_strdup(temp);
	}
	else if (b->type == 'd')
	{
		long_temp = va_arg(b->ap, int);
		if (long_temp < 0)
		{
			long_temp *= -1;
			b->sign = 1;
		}
		b->s = ltoa_base(long_temp, 10);
	}
	else if (b->type == 'x')
	{
		long_temp = va_arg(b->ap, unsigned int);
		b->s = ltoa_base(long_temp, 16);
	}
}

static void			ft_printf_conv_flag(const char *format, t_block *b)
{
	while (format[b->i] >= '0' && format[b->i] <= '9')
	{
		b->width = (b->width * 10) + (format[b->i] - '0');
		(b->i)++;
	}
	if (format[b->i] == '.')
	{
		(b->i)++;
		b->prec = 0;
		while (format[b->i] >= '0' && format[b->i] <= '9')
		{
			b->prec = (b->prec * 10) + (format[b->i] - '0');
			(b->i)++;
		}
	}
}

int					ft_printf(const char *format, ...)
{
	t_block	b;
	int		len;

	b.i = 0;
	b.ret = 0;
	va_start(b.ap, format);
	while (format[b.i])
	{
		if (format[b.i] == '%')
		{
			b.i++;
			b.width = 0;
			b.prec = -1;
			b.sign = 0;
			b.type = '0';
			ft_printf_conv_flag(format, &b);
			ft_printf_conv_type(format, &b);
			ft_printf_check_precision(&b);
			len = 0;
			while ((b.s)[len])
				len++;
			b.width = b.width - len - b.sign;
			while ((b.width)-- > 0)
				b.ret += write(1, " ", 1);
			if (b.sign)
				b.ret += write(1, "-", 1);
			b.ret += write(1, b.s, len);
			free(b.s);
			b.i++;
		}
		else
			b.ret += write(1, &format[b.i++], 1);
	}
	va_end(b.ap);
	return (b.ret);
}

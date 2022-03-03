/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/08 16:28:06 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/12 13:17:17 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_block(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		argv[i] = ft_memfree(argv[i], NULL);
		i++;
	}
	argv = ft_memfree(argv, NULL);
}

void	free_stack(t_stack *stack)
{
	t_element	*cur;
	t_element	*next;

	while (stack && stack->start)
	{
		cur = stack->start;
		next = stack->start;
		while (next->next)
		{
			cur = next;
			next = next->next;
		}
		if (cur == next)
			stack->start = ft_memfree(stack->start, NULL);
		else
		{
			cur->next = NULL;
			next = ft_memfree(next, NULL);
		}
	}
	stack = ft_memfree(stack, NULL);
}

static void	failure_puttype(char *format, int *i, va_list *ap)
{
	char	*s1;

	if (format[*i] == 's')
	{
		s1 = va_arg(*ap, char *);
		if (s1 == NULL)
			ft_dprintf(STDERR_FILENO, "(null)");
		else
			ft_dprintf(STDERR_FILENO, s1);
		(*i)++;
	}
	else if (format[*i] == 'c')
	{
		ft_putchar_fd((char)va_arg(*ap, int), STDERR_FILENO);
		(*i)++;
	}
	else if (format[*i] == 'i')
	{
		s1 = ft_itoa((int)(va_arg(*ap, int)));
		ft_dprintf(STDERR_FILENO, s1);
		(*i)++;
	}
}

void	free_program(t_ps_block *b, int status)
{
	if (b->is_string)
		free_block(b->argv);
	if (status > E_NOARGS)
		free_stack(b->stack_a);
	if (status > E_FREE_A)
		free_stack(b->stack_b);
}

void	exit_program(t_ps_block *b, int status, char *format, ...)
{
	va_list	ap;
	int		i;

	free_program(b, status);
	if (status == E_SUCCESS || status == E_NOARGS)
		exit (EXIT_SUCCESS);
	va_start(ap, format);
	ft_dprintf(STDERR_FILENO, "ERROR\n");
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			failure_puttype(format, &i, &ap);
		}
		else
			ft_putchar_fd(format[i++], STDERR_FILENO);
	}
	va_end(ap);
	exit(EXIT_FAILURE);
}

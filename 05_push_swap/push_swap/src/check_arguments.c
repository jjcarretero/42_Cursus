/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arguments.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 21:35:06 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/05 19:34:02 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_digits(t_ps_block *b)
{
	int	i;
	int	j;

	i = 0;
	while (i < b->argc)
	{
		if (!ft_strcmp(b->argv[i], "+") || !ft_strcmp(b->argv[i], "-"))
			exit_program(b, E_NONE, "Signs must complement an integer");
		j = 0;
		if (b->argv[i][0] == '+' || b->argv[i][0] == '-')
			j++;
		while (b->argv[i][j])
		{
			if (!ft_isdigit(b->argv[i][j]))
				exit_program(b, E_NONE, "Argument %i is not a digit", i + 1);
			j++;
		}
		i++;
	}
}

static int	check_int_limits(char *str, int len, int s)
{
	if (len < 10)
		return (TRUE);
	if (len > 10)
		return (FALSE);
	if ((s == S_POS || s == S_NONE) && ft_strcmp(str, S_INTMAX) > 0)
		return (FALSE);
	if (s == S_NEG && ft_strcmp(str, S_INTMIN) > 0)
		return (FALSE);
	return (TRUE);
}

static int	is_int(char *str)
{
	int		len;
	int		s;
	char	*ret;

	ret = str;
	s = S_NONE;
	len = ft_strlen(str);
	if (str[0] == '+' || str[0] == '-')
	{
		s = (S_POS * (str[0] == '+')) + (S_NEG * (str[0] == '-'));
		len--;
		ret++;
	}
	if (*ret == '0')
	{
		ret = ft_strtrim_start(ret, "0");
		if (ret == NULL)
			ret = ft_strdup("0");
		len = ft_strlen(ret);
	}
	return (check_int_limits(ret, len, s));
}

void	check_arguments(t_ps_block *b)
{
	int	i;

	check_digits(b);
	i = 0;
	while (i < b->argc)
	{
		if (!is_int(b->argv[i]))
			exit_program(b, E_NONE, "All arguments must be integers");
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 16:23:57 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/02 00:19:03 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

static int	check_base(char c)
{
	int		i;
	char	*base;

	base = "0123456789abcdefABCDEF";
	i = ft_strchr_pos(base, c);
	return (i);
}

int			ft_atoi_base(char *str, int base)
{
	int	i;
	int	s;
	int	pos;
	int	atoi;

	i = 0;
	atoi = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	s = (str[i] == 45) ? -1 : 1;
	if (str[i] == 45 || str[i] == 43)
		i++;
	while ((pos = check_base(str[i])) >= 0)
	{
		atoi *= base;
		if (ft_isdigit(str[i]))
			atoi += str[i] - 48;
		else if (str[i] >= 97 && str[i] <= 122)
			atoi += str[i] - 87;
		else if (str[i] >= 65 && str[i] <= 90)
			atoi += str[i] - 55;
		i++;
	}
	return (atoi * s);
}

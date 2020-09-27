/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:46:06 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/02 00:17:29 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int	ft_sqrt(int nb)
{
	int sqrt;
	int temp;

	if (nb < 0)
		return (0);
	else if (nb == 1)
		return (1);
	sqrt = nb / 2;
	temp = 0;
	while (sqrt != temp)
	{
		temp = sqrt;
		sqrt = (nb / temp + temp) / 2;
	}
	if ((sqrt * sqrt) != nb)
		return (0);
	else
		return (sqrt);
}

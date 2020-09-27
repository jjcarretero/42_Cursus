/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digits_long.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:08:58 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/19 15:56:26 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int	ft_digits_long(int nb)
{
	if (nb < 0)
		nb = (nb == INT_MIN) ? INT_MAX : -nb;
	if (nb < 10)
		return (1);
	if (nb < 100)
		return (2);
	if (nb < 1000)
		return (3);
	if (nb < 10000)
		return (4);
	if (nb < 100000)
		return (5);
	if (nb < 1000000)
		return (6);
	if (nb < 10000000)
		return (7);
	if (nb < 100000000)
		return (8);
	if (nb <= INT_MAX)
		return (9);
	return (-1);
}

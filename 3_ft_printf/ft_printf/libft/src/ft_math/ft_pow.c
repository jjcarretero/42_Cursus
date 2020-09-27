/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 19:05:28 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/25 16:18:15 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_pow(int x, unsigned int y)
{
	int	temp;

	if (y == 0)
		return (1);
	temp = ft_pow(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
		return (x * temp * temp);
}

long long	ft_llpow(long long x, unsigned long long y)
{
	long long	temp;

	if (y == 0)
		return (1);
	temp = ft_llpow(x, y / 2);
	if (y % 2 == 0)
		return (temp * temp);
	else
		return (x * temp * temp);
}

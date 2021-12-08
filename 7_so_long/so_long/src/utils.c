/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/31 17:51:21 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/21 23:20:26 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	print_map(t_so_long_game *game)
{
	int	i;
	int	j;

	j = 0;
	while (j < game->map_data.height)
	{
		i = 0;
		while (i < game->map_data.width)
		{
			ft_printf("%c", game->map_data.map[j][i]);
			i++;
		}
		ft_printf("\n");
		j++;
	}
}

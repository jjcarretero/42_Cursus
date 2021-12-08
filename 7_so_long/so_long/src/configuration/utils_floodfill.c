/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_floodfill.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/07 18:13:08 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/26 20:36:23 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ff_change_value(int old, int *new, int v)
{
	if (old == *new)
		*new = v;
}

int	ff_copy_coords(int x, int y, int *new_x, int *new_y)
{
	*new_y = y;
	*new_x = x;
	return (TRUE);
}

void	ff_print_map(t_so_long_game *game, int **hash)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < game->map_data.height)
	{
		x = 0;
		while (x < game->map_data.width)
		{
			ft_printf("%i", hash[y][x]);
			x++;
		}
		ft_printf("\n");
		y++;
	}
	ft_printf("\n");
	ft_printf("\n");
}

void	free_hash(t_so_long_game *game, int **hash)
{
	int	i;

	i = 0;
	while (i < game->map_data.height)
	{
		ft_memfree(hash[i], NULL);
		i++;
	}
	ft_memfree(hash, NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vi_start_enemies_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:26:16 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/21 13:31:36 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	get_monster_pos(t_so_long_game *game)
{
	t_point		pos;
	int			i;
	t_map_data	map;

	map = game->map_data;
	pos.y = 0;
	i = 0;
	while (pos.y < map.height)
	{
		pos.x = 0;
		while (pos.x < map.width)
		{
			if (map.map[pos.y][pos.x] == 'M')
			{
				game->map_data.monsters[i].pos_x = pos.x;
				game->map_data.monsters[i].pos_y = pos.y;
				i++;
			}
			(pos.x)++;
		}
		(pos.y)++;
	}
}

void	start_enemies(t_so_long_game *game)
{
	int			i;
	t_map_data	*data;

	data = &(game->map_data);
	data->monsters = ft_calloc(data->num_monsters, sizeof(t_monster));
	get_monster_pos(game);
	i = 0;
	while (i < data->num_monsters)
	{
		data->monsters[i].dir = (rand() % 4) * 5;
		data->monsters[i].frame = 0;
		data->monsters[i].img_monster.img = \
			mlx_xpm_file_to_image((game->mlx_data).mlx, \
			data->textures.monsters_path[0], \
			&data->monsters[i].img_monster.width, \
			&data->monsters[i].img_monster.height);
		i++;
	}
}

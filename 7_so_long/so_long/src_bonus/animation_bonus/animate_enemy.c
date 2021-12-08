/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_enemy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 10:58:42 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/21 17:20:26 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	enemy_select_stage(t_so_long_game *game, int i, int stage)
{
	t_map_data	*data;

	data = &(game->map_data);
	mlx_destroy_image(game->mlx_data.mlx, \
				data->monsters[i].img_monster.img);
	data->monsters[i].img_monster.img = \
		mlx_xpm_file_to_image((game->mlx_data).mlx, \
		game->map_data.textures.monsters_path[stage], \
		&data->monsters[i].img_monster.width, \
		&data->monsters[i].img_monster.height);
	mlx_put_image_to_window(game->mlx_data.mlx, game->mlx_data.win, \
						data->monsters[i].img_monster.img, \
						data->monsters[i].pos_x * TILE_SIZE, \
						data->monsters[i].pos_y * TILE_SIZE);
}

void	animate_enemy(t_so_long_game *game)
{
	int			i;
	int			stage;
	t_map_data	*data;

	data = &(game->map_data);
	i = 0;
	while (i < data->num_monsters)
	{
		stage = (data->monsters[i].frame / 5) + data->monsters[i].dir;
		enemy_select_stage(game, i, stage);
		if (data->monsters[i].frame > 18)
			data->monsters[i].frame = 0;
		enemy_movement(game, i);
		ft_delay(20);
		data->monsters[i].frame++;
		i++;
	}
}

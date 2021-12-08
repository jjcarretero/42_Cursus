/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_init_struct_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 21:45:33 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/21 17:27:37 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	init_textures(t_so_long_game *game)
{
	t_textures	*t;

	t = &(game->map_data.textures);
	t->img_background.img = mlx_xpm_file_to_image((game->mlx_data).mlx, \
		t->floor_path[0], &t->img_background.width, &t->img_background.height);
	t->img_wall.img = mlx_xpm_file_to_image((game->mlx_data).mlx, \
		t->wall_path[0], &t->img_wall.width, &t->img_wall.height);
	t->img_player.img = mlx_xpm_file_to_image((game->mlx_data).mlx, \
		t->player_path[0], &t->img_player.width, &t->img_player.height);
	t->img_collectable.img = mlx_xpm_file_to_image((game->mlx_data).mlx, \
		t->coin_path[0], &t->img_collectable.width, &t->img_collectable.height);
	t->img_exit.img = mlx_xpm_file_to_image((game->mlx_data).mlx, \
		t->exit_path[0], &t->img_exit.width, &t->img_exit.height);
	t->img_end.img = mlx_xpm_file_to_image((game->mlx_data).mlx, \
		t->end_path[0], &t->img_exit.width, &t->img_exit.height);
}

static void	init_mlx_data(t_so_long_game *game)
{
	(game->mlx_data).mlx = mlx_init();
	if ((game->mlx_data).mlx == NULL)
		exit_program(game, F_GAME, E_MLX, NULL);
	(game->mlx_data).win = NULL;
	(game->mlx_data).image.img = NULL;
	(game->mlx_data).width = 0;
	(game->mlx_data).height = 0;
}

static void	init_player(t_player_data *player)
{
	player->pos_x = -1;
	player->pos_y = -1;
	player->moves = 0;
	player->last = 0;
	player->dir = 0;
}

void	initialize_game_struct(t_so_long_game *game)
{
	srand(time(NULL));
	init_mlx_data(game);
	init_textures(game);
	game->keycode_state = K_KEY_NONE;
	init_player(&(game->player_data));
	game->map_data.map = NULL;
	game->map_data.collectables = 0;
	game->map_data.exit = 0;
	game->map_data.monsters = 0;
	game->map_data.monsters_init = FALSE;
}

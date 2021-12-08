/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ii_key_use_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:26:02 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/21 18:24:59 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	update_textures(t_so_long_game *game, int dir)
{
	t_textures	*t;

	t = &(game->map_data.textures);
	mlx_destroy_image(game->mlx_data.mlx, t->img_player.img);
	t->img_player.img = \
		mlx_xpm_file_to_image((game->mlx_data).mlx, t->player_path[dir], \
		&t->img_player.width, &t->img_player.height);
	if (game->map_data.collectables == 0)
	{
		mlx_destroy_image(game->mlx_data.mlx, t->img_exit.img);
		t->img_exit.img = \
		mlx_xpm_file_to_image((game->mlx_data).mlx, t->exit_path[1], \
		&t->img_exit.width, &t->img_exit.height);
		game->map_data.collectables = -1;
	}
}

static void	player_movement_horizontal(t_so_long_game *game, int dir)
{
	char			newpos;
	t_player_data	*player;

	player = &(game->player_data);
	newpos = game->map_data.map[player->pos_y] \
		[player->pos_x + (dir * 1)];
	if (newpos != '1' && newpos != 'E')
	{
		game->map_data.map[player->pos_y][player->pos_x] = '0';
		player->pos_x += (dir * 1);
		player->moves += 1;
		if (newpos == 'C')
			game->map_data.collectables -= 1;
		if (game->map_data.map[player->pos_y][player->pos_x] != 'M')
			game->map_data.map[player->pos_y][player->pos_x] = 'P';
	}
	else if (newpos == 'E' && game->map_data.collectables < 0)
	{
		game->map_data.map[player->pos_y][player->pos_x] = '0';
		player->pos_x += (dir * 1);
		player->moves += 1;
	}
}

static void	player_movement_vertical(t_so_long_game *game, int dir)
{
	char			newpos;
	t_player_data	*player;

	player = &(game->player_data);
	newpos = game->map_data.map[player->pos_y + (dir * 1)] \
		[player->pos_x];
	if (newpos != '1' && newpos != 'E')
	{
		game->map_data.map[player->pos_y][player->pos_x] = '0';
		player->pos_y += (dir * 1);
		player->moves += 1;
		if (newpos == 'C')
			game->map_data.collectables -= 1;
		if (game->map_data.map[player->pos_y][player->pos_x] != 'M' && \
				game->map_data.map[player->pos_y][player->pos_x] != 'E')
			game->map_data.map[player->pos_y][player->pos_x] = 'P';
	}
	else if (newpos == 'E' && game->map_data.collectables < 0)
	{
		game->map_data.map[player->pos_y][player->pos_x] = '0';
		player->pos_x += (dir * 1);
		player->moves += 1;
	}
}

static void	player_movement(int key, t_so_long_game *game)
{
	int	dir;

	if (key == KEY_S || key == KEY_AUX_DNAR)
		game->keycode_state = K_KEY_S;
	else if (key == KEY_W || key == KEY_AUX_UPAR)
		game->keycode_state = K_KEY_W;
	else if (key == KEY_D || key == KEY_AUX_RTAR)
		game->keycode_state = K_KEY_D;
	else if (key == KEY_A || key == KEY_AUX_LFAR)
		game->keycode_state = K_KEY_A;
	dir = 1;
	if (game->keycode_state % 2)
		dir = -1;
	if (game->keycode_state > 1)
		player_movement_horizontal(game, dir);
	else
		player_movement_vertical(game, dir);
	game->player_data.dir = game->keycode_state * 5;
	if (check_if_end(game) == S_RUNNING)
	{
		update_textures(game, game->player_data.dir);
		render_map(game);
	}
}

int	key_press_use(int key, t_so_long_game *game)
{
	if (key == KEY_ESC)
		exit_success(game);
	else if (game->game_state == S_RUNNING)
	{
		player_movement(key, game);
	}
	return (EXIT_SUCCESS);
}

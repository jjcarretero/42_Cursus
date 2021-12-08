/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ii_key_use.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:26:02 by jcarrete          #+#    #+#             */
/*   Updated: 2021/12/04 16:46:11 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	char	newpos;

	newpos = game->map_data.map[game->player_data.pos_y] \
		[game->player_data.pos_x + (dir * 1)];
	if (newpos != '1' && newpos != 'E')
	{
		game->map_data.map[game->player_data.pos_y] \
		[game->player_data.pos_x] = '0';
		game->player_data.pos_x += (dir * 1);
		game->player_data.moves += 1;
		if (newpos == 'C')
			game->map_data.collectables -= 1;
		game->map_data.map[game->player_data.pos_y] \
		[game->player_data.pos_x] = 'P';
	}
	if (newpos == 'E' && game->map_data.collectables < 0)
	{
		game->game_state = S_WON;
		render_end(game);
		return ;
	}
	render_map(game);
}

static void	player_movement_vertical(t_so_long_game *game, int dir)
{
	char	newpos;

	newpos = game->map_data.map[game->player_data.pos_y + (dir * 1)] \
		[game->player_data.pos_x];
	if (newpos != '1' && newpos != 'E')
	{
		game->map_data.map[game->player_data.pos_y] \
		[game->player_data.pos_x] = '0';
		game->player_data.pos_y += (dir * 1);
		game->player_data.moves += 1;
		if (newpos == 'C')
			game->map_data.collectables -= 1;
		game->map_data.map[game->player_data.pos_y] \
		[game->player_data.pos_x] = 'P';
	}
	if (newpos == 'E' && game->map_data.collectables < 0)
	{
		game->game_state = S_WON;
		render_end(game);
		return ;
	}
	render_map(game);
}

static void	player_movement(int key, t_so_long_game *game)
{
	if (key == KEY_S || key == KEY_AUX_DNAR)
	{
		player_movement_vertical(game, 1);
		update_textures(game, 0);
	}
	if (key == KEY_W || key == KEY_AUX_UPAR)
	{
		player_movement_vertical(game, -1);
		update_textures(game, 1);
	}
	if (key == KEY_D || key == KEY_AUX_RTAR)
	{
		player_movement_horizontal(game, 1);
		update_textures(game, 2);
	}
	if (key == KEY_A || key == KEY_AUX_LFAR)
	{
		player_movement_horizontal(game, -1);
		update_textures(game, 3);
	}
}

int	key_press_use(int key, t_so_long_game *game)
{
	if (key == KEY_ESC)
		exit_success(game);
	else if (game->game_state == S_RUNNING)
	{
		player_movement(key, game);
		ft_printf("\rMoves: %d", game->player_data.moves);
	}
	return (EXIT_SUCCESS);
}

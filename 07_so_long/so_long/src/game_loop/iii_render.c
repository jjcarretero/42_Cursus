/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iii_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:04:22 by jcarrete          #+#    #+#             */
/*   Updated: 2021/12/04 12:57:29 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_texture(int type, t_so_long_game *game, int y, int x)
{
	void	*ptr;

	ptr = NULL;
	if (type == T_WALL)
		ptr = game->map_data.textures.img_wall.img;
	else if (type == T_FLOOR)
		ptr = game->map_data.textures.img_background.img;
	else if (type == T_EXIT)
		ptr = game->map_data.textures.img_exit.img;
	else if (type == T_COLLECTABLE)
		ptr = game->map_data.textures.img_collectable.img;
	else if (type == T_PLAYER)
		ptr = game->map_data.textures.img_player.img;
	else if (type == T_END_WIN)
		ptr = game->map_data.textures.img_end.img;
	mlx_put_image_to_window(game->mlx_data.mlx, game->mlx_data.win, \
							ptr, x * TILE_SIZE, y * TILE_SIZE);
}

static int	render_poster(t_so_long_game *game, int y, int x)
{
	if (y == game->map_data.height / 2)
	{
		if (x == (game->map_data.width / 2 - 1))
		{
			render_texture(T_END_WIN, game, y, x);
			return (TRUE);
		}
		else if (x == (game->map_data.width / 2) || \
				x == (game->map_data.width / 2 + 1))
			return (TRUE);
	}
	return (FALSE);
}

int	render_end(t_so_long_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_data.height)
	{
		x = 0;
		while (x < game->map_data.width)
		{
			if (render_poster(game, y, x) == FALSE)
				render_texture(T_WALL, game, y, x);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

int	render_map(t_so_long_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->map_data.height && game->game_state == S_RUNNING)
	{
		x = 0;
		while (x < game->map_data.width)
		{
			if (game->map_data.map[y][x] == '1')
				render_texture(T_WALL, game, y, x);
			else if (game->map_data.map[y][x] == '0')
				render_texture(T_FLOOR, game, y, x);
			else if (game->map_data.map[y][x] == 'E')
				render_texture(T_EXIT, game, y, x);
			else if (game->map_data.map[y][x] == 'C')
				render_texture(T_COLLECTABLE, game, y, x);
			else if (game->map_data.map[y][x] == 'P')
				render_texture(T_PLAYER, game, y, x);
			x++;
		}
		y++;
	}
	return (EXIT_SUCCESS);
}

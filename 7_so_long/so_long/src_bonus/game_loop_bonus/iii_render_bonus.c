/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iii_render_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:04:22 by jcarrete          #+#    #+#             */
/*   Updated: 2021/12/04 12:59:57 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	search_monster(t_so_long_game *game, int y, int x)
{
	int	i;

	i = 0;
	while (i < game->map_data.num_monsters)
	{
		if (game->map_data.monsters[i].pos_x == x && \
				game->map_data.monsters[i].pos_y == y)
			return (i);
		i++;
	}
	return (i);
}

void	render_texture(int type, t_so_long_game *game, int y, int x)
{
	void	*ptr;
	int		i;

	i = 0;
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
	else if (type == T_MONSTER && game->map_data.monsters_init)
	{
		i = search_monster(game, y, x);
		ptr = game->map_data.monsters[i].img_monster.img;
	}
	else if (type == T_END)
		ptr = game->map_data.textures.img_end.img;
	mlx_put_image_to_window(game->mlx_data.mlx, game->mlx_data.win, \
							ptr, x * TILE_SIZE, y * TILE_SIZE);
}

static void	parse_map_item(t_so_long_game *game, int y, int x)
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
	else if (game->map_data.map[y][x] == 'M')
		render_texture(T_MONSTER, game, y, x);
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
			parse_map_item(game, y, x);
			x++;
		}
		y++;
	}
	render_moves(game);
	ft_delay(40);
	return (EXIT_SUCCESS);
}

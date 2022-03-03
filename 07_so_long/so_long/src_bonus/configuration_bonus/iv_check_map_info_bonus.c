/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iv_check_map_info_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 23:18:59 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/21 12:42:13 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_position(t_so_long_game *game, int x, int y, char c)
{
	t_map_data	*md;

	md = &(game->map_data);
	if (x > 0 && x < md->width - 1 && \
			y > 0 && y < md->height - 1 && \
			md->map[y][x] == c)
		exit_program(game, F_MAP, E_MAP, "Not closed");
}

static void	check_round_spaces(t_so_long_game *game, t_point *pos)
{
	int			x;
	int			y;

	x = (int)(pos->x);
	y = (int)(pos->y);
	check_position(game, x - 1, y, ' ');
	check_position(game, x - 1, y - 1, ' ');
	check_position(game, x, y - 1, ' ');
	check_position(game, x + 1, y - 1, ' ');
	check_position(game, x + 1, y, ' ');
	check_position(game, x + 1, y + 1, ' ');
	check_position(game, x, y + 1, ' ');
	check_position(game, x - 1, y + 1, ' ');
	if (ft_strchr("0CEP", (game->map_data.map)[y][x]) && \
		(x == (game->map_data.width - 1) || \
		y == (game->map_data.height - 1) || \
		(x == 0) || (y == 0)))
		exit_program(game, F_MAP, E_MAP, "Not closed");
}

static void	check_map_object(t_so_long_game *game, t_point *pos, char obj)
{
	if (obj == '1')
		(game->map_data.ones) += 1;
	else
	{
		check_round_spaces(game, pos);
		if (obj == 'C')
			(game->map_data.collectables) += 1;
		else if (obj == 'E')
			(game->map_data.exit) += 1;
		else if (obj == 'M')
			(game->map_data.num_monsters) += 1;
		else if (obj == 'P')
		{
			if (game->player_data.pos_x != -1)
				exit_program(game, F_MAP, E_MAP, \
							"Player can't be initialized twice");
			game->player_data.pos_x = pos->x;
			game->player_data.pos_y = pos->y;
		}
	}
}

void	check_map_info(t_so_long_game *game)
{
	t_point		pos;
	char		obj;
	t_map_data	map;

	map = game->map_data;
	pos.y = 0;
	while (pos.y < map.height)
	{
		pos.x = 0;
		while (pos.x < map.width)
		{
			obj = map.map[pos.y][pos.x];
			if (!(ft_strchr(MAP_OBJECTS, obj)))
				exit_program(game, F_MAP, E_MAP, "Invalid map char");
			check_map_object(game, &pos, obj);
			(pos.x)++;
		}
		(pos.y)++;
	}
}

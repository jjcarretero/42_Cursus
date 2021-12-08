/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_movement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:44:58 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/21 17:16:42 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	calculate_positions(t_monster	*monster, \
								t_point *pos, t_point *newpos)
{
	int			mod;

	if (monster->dir == D_SOUTH || monster->dir == D_EAST)
		mod = 1;
	if (monster->dir == D_NORTH || monster->dir == D_WEST)
		mod = -1;
	pos->x = monster->pos_x;
	pos->y = monster->pos_y;
	newpos->x = pos->x;
	newpos->y = pos->y;
	if (monster->dir == D_SOUTH || monster->dir == D_NORTH)
		newpos->y += mod;
	else if (monster->dir == D_EAST || monster->dir == D_WEST)
		newpos->x += mod;
}

static void	move_enemy(t_so_long_game *game, \
						t_monster	*monster, t_point *newpos)
{
	game->map_data.map[monster->pos_y][monster->pos_x] = '0';
	render_texture(T_FLOOR, game, monster->pos_y, monster->pos_x);
	monster->pos_x = newpos->x;
	monster->pos_y = newpos->y;
	game->map_data.map[monster->pos_y][monster->pos_x] = 'M';
	check_if_end(game);
}

static void	change_direction(t_so_long_game *game, t_monster *monster)
{
	int		new_dir;
	t_point	pos;
	t_point	newpos;
	int		free_way;

	free_way = FALSE;
	while (free_way == FALSE)
	{
		new_dir = (rand() % 4) * 5;
		monster->dir = new_dir;
		calculate_positions(monster, &pos, &newpos);
		if (game->map_data.map[newpos.y][newpos.x] == '0' || \
				game->map_data.map[newpos.y][newpos.x] == 'P')
		{
			free_way = TRUE;
			monster->frame = 0;
		}
	}
}

void	enemy_movement(t_so_long_game *game, int i)
{
	t_monster	*monster;
	t_point		newpos;
	t_point		pos;

	monster = &(game->map_data.monsters[i]);
	monster->wait++;
	if (monster->wait == WAITTIME)
	{
		calculate_positions(monster, &pos, &newpos);
		if (game->map_data.map[newpos.y][newpos.x] == '0' || \
				game->map_data.map[newpos.y][newpos.x] == 'P')
			move_enemy(game, monster, &newpos);
		else
			change_direction(game, monster);
		monster->wait = 0;
	}
}

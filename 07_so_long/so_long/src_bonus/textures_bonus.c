/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:58:47 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/18 22:54:34 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	monster_texture(t_so_long_game *game)
{
	t_textures	*t;

	t = &(game->map_data.textures);
	ft_strcpy(t->monsters_path[0], "./resources/tex/enemy/e_down_zero.xpm");
	ft_strcpy(t->monsters_path[1], "./resources/tex/enemy/e_down_one.xpm");
	ft_strcpy(t->monsters_path[2], "./resources/tex/enemy/e_down_two.xpm");
	ft_strcpy(t->monsters_path[3], "./resources/tex/enemy/e_down_three.xpm");
	ft_strcpy(t->monsters_path[4], "./resources/tex/enemy/e_down_four.xpm");
	ft_strcpy(t->monsters_path[5], "./resources/tex/enemy/e_up_zero.xpm");
	ft_strcpy(t->monsters_path[6], "./resources/tex/enemy/e_up_one.xpm");
	ft_strcpy(t->monsters_path[7], "./resources/tex/enemy/e_up_two.xpm");
	ft_strcpy(t->monsters_path[8], "./resources/tex/enemy/e_up_three.xpm");
	ft_strcpy(t->monsters_path[9], "./resources/tex/enemy/e_up_four.xpm");
	ft_strcpy(t->monsters_path[10], "./resources/tex/enemy/e_right_zero.xpm");
	ft_strcpy(t->monsters_path[11], "./resources/tex/enemy/e_right_one.xpm");
	ft_strcpy(t->monsters_path[12], "./resources/tex/enemy/e_right_two.xpm");
	ft_strcpy(t->monsters_path[13], "./resources/tex/enemy/e_right_three.xpm");
	ft_strcpy(t->monsters_path[14], "./resources/tex/enemy/e_right_four.xpm");
	ft_strcpy(t->monsters_path[15], "./resources/tex/enemy/e_left_zero.xpm");
	ft_strcpy(t->monsters_path[16], "./resources/tex/enemy/e_left_one.xpm");
	ft_strcpy(t->monsters_path[17], "./resources/tex/enemy/e_left_two.xpm");
	ft_strcpy(t->monsters_path[18], "./resources/tex/enemy/e_left_three.xpm");
	ft_strcpy(t->monsters_path[19], "./resources/tex/enemy/e_left_four.xpm");
}

static void	player_texture(t_so_long_game *game)
{
	t_textures	*t;

	t = &(game->map_data.textures);
	ft_strcpy(t->player_path[0], "./resources/tex/hero/down_zero.xpm");
	ft_strcpy(t->player_path[1], "./resources/tex/hero/down_one.xpm");
	ft_strcpy(t->player_path[2], "./resources/tex/hero/down_two.xpm");
	ft_strcpy(t->player_path[3], "./resources/tex/hero/down_three.xpm");
	ft_strcpy(t->player_path[4], "./resources/tex/hero/down_four.xpm");
	ft_strcpy(t->player_path[5], "./resources/tex/hero/up_zero.xpm");
	ft_strcpy(t->player_path[6], "./resources/tex/hero/up_one.xpm");
	ft_strcpy(t->player_path[7], "./resources/tex/hero/up_two.xpm");
	ft_strcpy(t->player_path[8], "./resources/tex/hero/up_three.xpm");
	ft_strcpy(t->player_path[9], "./resources/tex/hero/up_four.xpm");
	ft_strcpy(t->player_path[10], "./resources/tex/hero/right_zero.xpm");
	ft_strcpy(t->player_path[11], "./resources/tex/hero/right_one.xpm");
	ft_strcpy(t->player_path[12], "./resources/tex/hero/right_two.xpm");
	ft_strcpy(t->player_path[13], "./resources/tex/hero/right_three.xpm");
	ft_strcpy(t->player_path[14], "./resources/tex/hero/right_four.xpm");
	ft_strcpy(t->player_path[15], "./resources/tex/hero/left_zero.xpm");
	ft_strcpy(t->player_path[16], "./resources/tex/hero/left_one.xpm");
	ft_strcpy(t->player_path[17], "./resources/tex/hero/left_two.xpm");
	ft_strcpy(t->player_path[18], "./resources/tex/hero/left_three.xpm");
	ft_strcpy(t->player_path[19], "./resources/tex/hero/left_four.xpm");
}

static void	map_texture(t_so_long_game *game)
{
	t_textures	*t;

	t = &(game->map_data.textures);
	ft_strcpy(t->wall_path[0], \
		"./resources/tex/map/wall.xpm");
	ft_strcpy(t->floor_path[0], \
		"./resources/tex/map/floor.xpm");
	ft_strcpy(t->coin_path[0], \
		"./resources/tex/map/coin_zero.xpm");
	ft_strcpy(t->exit_path[0], \
		"./resources/tex/map/exit_zero.xpm");
	ft_strcpy(t->exit_path[1], \
		"./resources/tex/map/exit_one.xpm");
	ft_strcpy(t->end_path[0], \
		"./resources/tex/map/end_scene_win.xpm");
	ft_strcpy(t->end_path[1], \
		"./resources/tex/map/end_scene_lose.xpm");
}

void	load_textures(t_so_long_game *game)
{
	player_texture(game);
	monster_texture(game);
	map_texture(game);
}

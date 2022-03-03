/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 18:58:47 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/14 00:55:08 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	player_texture(t_so_long_game *game)
{
	t_textures	*t;

	t = &(game->map_data.textures);
	ft_strcpy(t->player_path[0], \
		"./resources/tex/hero/down_zero.xpm");
	ft_strcpy(t->player_path[1], \
		"./resources/tex/hero/up_zero.xpm");
	ft_strcpy(t->player_path[2], \
		"./resources/tex/hero/right_zero.xpm");
	ft_strcpy(t->player_path[3], \
		"./resources/tex/hero/left_zero.xpm");
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
}

void	load_textures(t_so_long_game *game)
{
	player_texture(game);
	map_texture(game);
}

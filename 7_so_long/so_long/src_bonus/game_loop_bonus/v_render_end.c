/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   v_render_end.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 18:30:23 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/21 18:24:39 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	render_poster(t_so_long_game *game, int y, int x)
{
	if (y == game->map_data.height / 2)
	{
		if (x == (game->map_data.width / 2 - 1))
		{
			render_texture(T_END, game, y, x);
			return (TRUE);
		}
		else if (x == (game->map_data.width / 2) || \
				x == (game->map_data.width / 2 + 1))
			return (TRUE);
	}
	return (FALSE);
}

static int	render_end(t_so_long_game *game)
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
	render_moves(game);
	return (EXIT_SUCCESS);
}

int	check_if_end(t_so_long_game *game)
{
	char		pos;
	t_textures	*t;

	t = &(game->map_data.textures);
	pos = game->map_data.map[game->player_data.pos_y] \
		[game->player_data.pos_x];
	if (pos == 'E' && game->map_data.collectables < 0)
	{
		game->game_state = S_EXIT;
		render_end(game);
	}
	if (pos == 'M')
	{
		game->game_state = S_EXIT;
		game->map_data.map[game->player_data.pos_y] \
		[game->player_data.pos_x] = '0';
		mlx_destroy_image(game->mlx_data.mlx, t->img_end.img);
		t->img_end.img = \
			mlx_xpm_file_to_image((game->mlx_data).mlx, t->end_path[1], \
			&t->img_end.width, &t->img_end.height);
		render_end(game);
	}
	return (game->game_state);
}

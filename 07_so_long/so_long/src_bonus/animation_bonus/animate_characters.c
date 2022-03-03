/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_characters.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 00:24:33 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/21 17:54:29 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	player_select_stage(t_so_long_game *game, int stage)
{
	t_textures	*t;

	if (game->game_state == S_RUNNING)
	{
		t = &(game->map_data.textures);
		mlx_destroy_image(game->mlx_data.mlx, t->img_player.img);
		t->img_player.img = \
			mlx_xpm_file_to_image((game->mlx_data).mlx, t->player_path[stage], \
			&t->img_end.width, &t->img_end.height);
		render_texture(T_PLAYER, game, \
			game->player_data.pos_y, game->player_data.pos_x);
	}
}

int	animate_characters(t_so_long_game *game)
{
	static int	frame;
	int			stage;

	if (game->game_state == S_RUNNING)
	{
		if (game->map_data.num_monsters >= 1)
			animate_enemy(game);
		stage = (frame / 5) + game->player_data.dir;
		player_select_stage(game, stage);
		if (frame > 18)
			frame = 0;
		ft_delay(20);
		frame++;
	}
	return (EXIT_SUCCESS);
}

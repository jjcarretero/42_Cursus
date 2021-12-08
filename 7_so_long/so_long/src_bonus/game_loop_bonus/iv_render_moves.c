/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iv_render_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 19:03:40 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/21 16:03:52 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	render_moves(t_so_long_game *game)
{
	char		*move_str;
	char		*last_str;
	static int	last = 0;
	t_point		pos;

	move_str = ft_itoa(game->player_data.moves);
	pos.y = (TILE_SIZE / 2);
	pos.x = TILE_SIZE;
	mlx_string_put(game->mlx_data.mlx, game->mlx_data.win, \
					pos.x, pos.y, CLR_YELLOW, "MOVES: ");
	if (game->player_data.moves > 0)
	{
		last = game->player_data.moves;
		mlx_string_put(game->mlx_data.mlx, game->mlx_data.win, \
					pos.x * 2, pos.y, CLR_YELLOW, move_str);
	}
	else
	{
		last_str = ft_itoa(last);
		mlx_string_put(game->mlx_data.mlx, game->mlx_data.win, \
					pos.x * 2, pos.y, CLR_YELLOW, last_str);
		last_str = ft_memfree(last_str, NULL);
	}
	move_str = ft_memfree(move_str, NULL);
}

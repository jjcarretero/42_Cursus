/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_game_loop.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:17:45 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/31 19:23:08 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	game_loop(t_so_long_game *game)
{
	mlx_hook(game->mlx_data.win, \
		KEY_PRESS, KEY_PRESS_MASK, key_press_use, game);
	if (LINUX == FALSE)
		mlx_hook(game->mlx_data.win, DESTROY_NOTIFY, \
			STRUCTURE_NOTIFY_MASK, exit_success, game);
	else
		mlx_hook(game->mlx_data.win, CLIENT_MESSAGE, \
			STRUCTURE_NOTIFY_MASK, exit_success, game);
	mlx_loop_hook(game->mlx_data.mlx, render_map, game);
	mlx_loop(game->mlx_data.mlx);
}

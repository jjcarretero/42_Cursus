/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   i_game_loop_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/28 21:17:45 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/21 09:59:25 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	key_release_use(int key, t_so_long_game *game)
{
	if (key)
		game->keycode_state = K_KEY_NONE;
	return (EXIT_SUCCESS);
}

void	game_loop(t_so_long_game *game)
{
	render_map(game);
	mlx_hook(game->mlx_data.win, \
		KEY_PRESS, KEY_PRESS_MASK, key_press_use, game);
	mlx_hook(game->mlx_data.win, \
		KEY_RELEASE, KEY_RELEASE_MASK, key_release_use, game);
	if (LINUX == FALSE)
		mlx_hook(game->mlx_data.win, DESTROY_NOTIFY, \
			STRUCTURE_NOTIFY_MASK, exit_success, game);
	else
		mlx_hook(game->mlx_data.win, CLIENT_MESSAGE, \
			STRUCTURE_NOTIFY_MASK, exit_success, game);
	mlx_loop_hook(game->mlx_data.mlx, animate_characters, game);
	mlx_loop(game->mlx_data.mlx);
}

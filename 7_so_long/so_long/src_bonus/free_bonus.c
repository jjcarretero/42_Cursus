/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 11:57:40 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/27 19:47:15 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	free_monsters(t_so_long_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_data.num_monsters)
	{
		if (game->map_data.monsters[i].img_monster.img != NULL)
			mlx_destroy_image(game->mlx_data.mlx, \
				game->map_data.monsters[i].img_monster.img);
		i++;
	}
	game->map_data.monsters = ft_memfree(game->map_data.monsters, NULL);
}

static void	free_mlx(t_so_long_game *game)
{
	if (game->mlx_data.image.img != NULL)
		mlx_destroy_image(game->mlx_data.mlx, game->mlx_data.image.img);
	if (game->map_data.textures.img_background.img != NULL)
		mlx_destroy_image(game->mlx_data.mlx, \
			game->map_data.textures.img_background.img);
	if (game->map_data.textures.img_collectable.img != NULL)
		mlx_destroy_image(game->mlx_data.mlx, \
			game->map_data.textures.img_collectable.img);
	if (game->map_data.textures.img_exit.img != NULL)
		mlx_destroy_image(game->mlx_data.mlx, \
			game->map_data.textures.img_exit.img);
	if (game->map_data.textures.img_player.img != NULL)
		mlx_destroy_image(game->mlx_data.mlx, \
			game->map_data.textures.img_player.img);
	if (game->map_data.textures.img_wall.img != NULL)
		mlx_destroy_image(game->mlx_data.mlx, \
			game->map_data.textures.img_wall.img);
	if (game->map_data.textures.img_end.img != NULL)
		mlx_destroy_image(game->mlx_data.mlx, \
			game->map_data.textures.img_end.img);
	if (game->mlx_data.win != NULL)
		mlx_destroy_window(game->mlx_data.mlx, game->mlx_data.win);
	game->mlx_data.win = NULL;
	if (game->mlx_data.mlx != NULL && LINUX == TRUE)
		mlx_destroy_display(game->mlx_data.mlx);
}

void	free_program(t_so_long_game *game, int status)
{
	int	i;

	if (status >= F_MAP)
	{
		i = 0;
		while (i < game->map_data.height)
		{
			game->map_data.map[i] = \
				ft_memfree(game->map_data.map[i], NULL);
			i++;
		}
		game->map_data.map = ft_memfree(game->map_data.map, NULL);
	}
	if (status >= F_WIN)
	{
		if (game->map_data.num_monsters > 0)
			free_monsters(game);
		free_mlx(game);
	}
	if (status >= F_MLX && game->mlx_data.mlx != NULL)
		game->mlx_data.mlx = ft_memfree(game->mlx_data.mlx, NULL);
	if (status >= F_GAME)
		game = ft_memfree(game, NULL);
}

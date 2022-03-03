/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:56:19 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/27 19:46:45 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	exit_success(t_so_long_game *game)
{
	if (game->game_state == S_WON)
		ft_printf("\nYou Won with %d movements!\n", game->player_data.moves);
	game->game_state = S_EXIT;
	exit_program(game, F_SUCCESS, E_NONE, NULL);
	return (EXIT_SUCCESS);
}

static void	free_mlx(t_so_long_game *game)
{
	if (game->mlx_data.win != NULL)
		mlx_destroy_window(game->mlx_data.mlx, game->mlx_data.win);
	game->mlx_data.win = NULL;
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
	if (game->mlx_data.mlx != NULL && LINUX == TRUE)
		mlx_destroy_display(game->mlx_data.mlx);
}

static void	error_str(int status)
{
	if (status == E_MEM)
		ft_dprintf(STDERR_FILENO, "Unable to allocate memory: ");
	else if (status == E_ARGS)
		ft_dprintf(STDERR_FILENO, "Invalid number of Arguments: ");
	else if (status == E_MLX)
		ft_dprintf(STDERR_FILENO, "Failed initializing MLX");
	else if (status == E_FILE_O)
		ft_dprintf(STDERR_FILENO, "Can't open file: ");
	else if (status == E_FILE_C)
		ft_dprintf(STDERR_FILENO, "Can't close file: ");
	else if (status == E_READ)
		ft_dprintf(STDERR_FILENO, "Can't read from file in fd: ");
	else if (status == E_MAP)
		ft_dprintf(STDERR_FILENO, "Map Error: ");
	else if (status == E_LIST)
		ft_dprintf(STDERR_FILENO, "Can't create list: ");
	else if (status == E_IMG)
		ft_dprintf(STDERR_FILENO, "Failed creating mlx image: ");
	else if (status == E_WIN)
		ft_dprintf(STDERR_FILENO, "Failed creating mlx window: ");
}

static void	free_program(t_so_long_game *game, int status)
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
		free_mlx(game);
	if (status >= F_MLX && game->mlx_data.mlx != NULL)
		game->mlx_data.mlx = ft_memfree(game->mlx_data.mlx, NULL);
	if (status >= F_GAME)
		game = ft_memfree(game, NULL);
}

void	exit_program(t_so_long_game *game, int status, int err, char *extra)
{
	free_program(game, status);
	if (status == F_SUCCESS)
		exit (EXIT_SUCCESS);
	ft_dprintf(STDERR_FILENO, "ERROR:\n");
	if (err != E_NONE)
		error_str(err);
	if (extra != NULL)
		ft_dprintf(STDERR_FILENO, extra);
	ft_dprintf(STDERR_FILENO, "\n");
	exit(EXIT_FAILURE);
}

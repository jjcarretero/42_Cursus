/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:43:14 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/14 00:53:04 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	initialize_window(t_so_long_game *game)
{
	game->mlx_data.image.width = game->map_data.width * TILE_SIZE;
	game->mlx_data.image.height = game->map_data.height * TILE_SIZE;
	game->mlx_data.image.img = mlx_new_image(game->mlx_data.mlx, \
			game->mlx_data.image.width, game->mlx_data.image.height);
	if (game->mlx_data.image.img == NULL)
		exit_program(game, F_MAP, E_IMG, strerror(errno));
	game->mlx_data.image.addr = \
			mlx_get_data_addr(game->mlx_data.image.img, \
			&(game->mlx_data.image.bits_per_pixel), \
			&(game->mlx_data.image.line_length), \
			&(game->mlx_data.image.endian));
	game->mlx_data.win = mlx_new_window(game->mlx_data.mlx, \
		game->map_data.width * TILE_SIZE, game->map_data.height * TILE_SIZE, \
		WINDOW_TITLE);
	if (game->mlx_data.win == NULL)
		exit_program(game, F_WIN, E_WIN, strerror(errno));
	game->game_state = S_RUNNING;
}

static void	check_arguments(t_so_long_game *game, int argc, char **argv)
{
	size_t	len;

	if (argc < 2)
		exit_program(game, F_GAME, E_ARGS, "No map specified. \
Program requires one FILE.ber argument.");
	else if (argc > 2)
		exit_program(game, F_GAME, E_ARGS, "Too many arguments.\n");
	else
	{
		len = ft_strlen(argv[1]);
		if (len < 4 || ft_strrncmp(argv[1], ".ber", 4))
			exit_program(game, F_GAME, E_MAP, "Unknown map file type");
		game->game_state = S_RENDER_START;
	}
}

int	main(int argc, char **argv)
{
	t_so_long_game	*game;

	game = ft_calloc(1, sizeof(t_so_long_game));
	if (game == NULL)
		exit_program(game, F_NONE, E_MEM, strerror(errno));
	game->game_state = S_START;
	check_arguments(game, argc, argv);
	load_textures(game);
	initialize_game_struct(game);
	load_scene_description(game, argv[1]);
	initialize_window(game);
	print_map(game);
	game_loop(game);
	exit_program(game, F_SUCCESS, E_SUCCESS, NULL);
}

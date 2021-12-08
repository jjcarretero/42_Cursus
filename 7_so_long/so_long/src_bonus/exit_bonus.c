/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 15:56:19 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/21 12:02:06 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	exit_success(t_so_long_game *game)
{
	game->game_state = S_EXIT;
	exit_program(game, F_SUCCESS, E_NONE, NULL);
	return (EXIT_SUCCESS);
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

void	exit_program(t_so_long_game *game, int status, int err, char *extra)
{
	if (status == F_SUCCESS)
	{
		free_program(game, status);
		exit (EXIT_SUCCESS);
	}
	ft_dprintf(STDERR_FILENO, "ERROR:\n");
	if (err != E_NONE)
		error_str(err);
	if (extra != NULL)
		ft_dprintf(STDERR_FILENO, extra);
	ft_dprintf(STDERR_FILENO, "\n");
	free_program(game, status);
	exit(EXIT_FAILURE);
}

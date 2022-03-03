/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ii_load_scene.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 22:17:08 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/26 23:31:19 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	extract_line_loop(t_so_long_game *game, char **line, \
						t_list **list, t_list **element)
{
	*element = ft_lstnew(*line);
	if ((ft_strlen(*line) == 0 || *element == NULL) && **line != '\0')
	{
		ft_lstclear(list, free);
		if (*element == NULL)
			exit_program(game, F_MLX, E_LIST, strerror(errno));
		exit_program(game, F_MLX, E_MAP, "Contains empty lines");
	}
	ft_lstadd_back(list, *element);
}

static void	extract_line_map(t_so_long_game *game, int fd, \
								char **line, t_list **list)
{
	int		value;
	t_list	*element;

	element = NULL;
	value = ft_get_next_line(fd, line);
	while (value > 0)
	{
		extract_line_loop(game, line, list, &element);
		value = ft_get_next_line(fd, line);
	}
	if (value >= 0 && *line)
		extract_line_loop(game, line, list, &element);
	if (value == -1)
	{
		ft_lstclear(list, free);
		exit_program(game, F_MLX, E_READ, ft_itoa(fd));
	}
}

static void	skip_empty_lines(t_so_long_game *game, int fd, char **line)
{
	int		value;

	value = ft_get_next_line(fd, line);
	while (value > 0)
	{
		if (ft_strlen(*line) > 0)
			break ;
		free(*line);
		value = ft_get_next_line(fd, line);
	}
	if (value == -1)
		exit_program(game, F_MLX, E_READ, ft_itoa(fd));
	if (value == 0)
		exit_program(game, F_MLX, E_MAP, "Empty file");
}

static void	load_map(t_so_long_game *game, int fd)
{
	t_list	*list;
	t_list	*element;
	char	*line;

	list = NULL;
	skip_empty_lines(game, fd, &line);
	element = ft_lstnew(line);
	if (element == NULL)
		exit_program(game, F_MLX, E_LIST, strerror(errno));
	ft_lstadd_back(&list, element);
	extract_line_map(game, fd, &line, &list);
	game->map_data.map = \
		set_map(game, list, &(game->map_data));
	if ((game->map_data.map) == NULL)
		exit_program(game, F_MLX, E_MAP, strerror(errno));
	ft_lstclear(&list, free);
}

void	load_scene_description(t_so_long_game *game, char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit_program(game, F_MLX, E_FILE_O, file);
	load_map(game, fd);
	if (close(fd) == -1)
		exit_program(game, F_MAP, E_FILE_C, file);
	check_map_info(game);
	if (game->player_data.pos_x == -1)
		exit_program(game, F_MAP, E_MAP, "Player doesn't exist");
	if (game->map_data.collectables == 0)
		exit_program(game, F_MAP, E_MAP, "At least one collectable");
	if (game->map_data.exit == 0)
		exit_program(game, F_MAP, E_MAP, "At least one exit");
	floodfilling_check(game);
}

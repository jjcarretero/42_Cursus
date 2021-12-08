/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iii_set_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/24 23:13:30 by jcarrete          #+#    #+#             */
/*   Updated: 2021/12/04 14:00:46 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	check_resolution(t_so_long_game *game, \
								int temp_width, int temp_height)
{
	int	screen_w;
	int	screen_h;

	mlx_get_screen_size(game->mlx_data.mlx, \
			&(screen_w), &(screen_h));
	if (temp_width > screen_w \
			|| temp_height > screen_h)
		exit_program(game, F_MLX, E_MAP, \
			"Map is too big for this screen's resolution");
}

static size_t	get_current_width(char *line)
{
	int		len;

	len = ft_strlen(line);
	while (len > 0)
	{
		if (!(ft_isspace(line[len - 1])))
			break ;
		len--;
	}
	return (len);
}

static void	copy_map_line(t_so_long_game *game, char *map, \
							char *list, int width)
{
	int	len;

	len = ft_strlen(list);
	if (width != len)
		exit_program(game, F_MLX, E_MAP, "Not rectangular");
	ft_memcpy(map, list, len);
	map[width] = '\0';
}

static void	set_map_size(t_list *list, int *width, int *height)
{
	int	current;
	int	max;

	*width = 0;
	*height = 0;
	current = 0;
	max = 0;
	while (list)
	{
		*height += (*(char *)(list->content) != '\0');
		current = get_current_width(list->content);
		if (current > max)
			max = current;
		list = list->next;
	}
	*width = max;
}

char	**set_map(t_so_long_game *game, t_list *list, t_map_data *data)
{
	int		i;
	char	**temp_map;

	set_map_size(list, &(data->width), &(data->height));
	check_resolution(game, data->width * TILE_SIZE, data->height * TILE_SIZE);
	temp_map = malloc(data->height * sizeof(char *));
	if (temp_map == NULL)
		exit_program(game, F_MLX, E_MEM, strerror(errno));
	i = 0;
	while (i < data->height)
	{
		temp_map[i] = malloc((data->width * sizeof(char)) + 1);
		if (temp_map[i] == NULL)
			exit_program(game, F_MLX, E_MEM, strerror(errno));
		copy_map_line(game, temp_map[i], list->content, data->width);
		list = list->next;
		i++;
	}
	return (temp_map);
}

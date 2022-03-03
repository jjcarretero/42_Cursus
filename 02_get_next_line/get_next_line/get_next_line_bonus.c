/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/03 22:33:03 by jcarrete          #+#    #+#             */
/*   Updated: 2020/08/03 22:33:03 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./get_next_line_bonus.h"

static void	free_mem(char **buff, char *temp)
{
	if (*buff)
	{
		free(*buff);
		*buff = temp;
	}
}

static int	found_carriage(char *buff)
{
	int	i;

	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	complete_line(char **buff, int pos, char **line)
{
	char	*temp;
	int		len;

	(*buff)[pos] = '\0';
	*line = ft_strdup(*buff);
	if ((len = ft_strlen(*buff + pos + 1)) == 0)
	{
		free_mem(buff, NULL);
		return (1);
	}
	temp = ft_strdup(*buff + pos + 1);
	free_mem(buff, temp);
	return (1);
}

static int	found_eof(char **buff, char **line)
{
	int		cut;

	if (*buff && (cut = found_carriage(*buff)) >= 0)
		return (complete_line(buff, cut, line));
	if (*buff)
	{
		*line = *buff;
		*buff = NULL;
		return (0);
	}
	*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*buff[OPEN_MAX];
	char		*stack;
	int			bytes;
	int			cut;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFFER_SIZE <= 0\
		|| !(stack = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((bytes = read(fd, stack, BUFFER_SIZE)) > 0)
	{
		stack[bytes] = '\0';
		buff[fd] = ft_strjoin(buff[fd], stack);
		if ((cut = found_carriage(buff[fd])) >= 0)
		{
			free_mem(&stack, NULL);
			return (complete_line(&buff[fd], cut, line));
		}
	}
	free_mem(&stack, NULL);
	if (bytes < 0)
		return (-1);
	return (found_eof(&buff[fd], line));
}

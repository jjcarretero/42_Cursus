/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 18:30:54 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/28 18:30:54 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Assignment name  : get_next_line
**	Expected files   : get_next_line.c get_next_line.h
**	Allowed functions: read, free, malloc
**	--------------------------------------------------------------------------------
**
**	Write a function will store, in the parameter "line", a line that has been read from the file descriptor 0.
**
**	Your function must be prototyped as follows: int get_next_line(char **line);
**
**	Your function should be memory leak free.
**
**	What we call a "line that has been read" is a succession of 0 to n characters that end with '\n' (ascii code 0x0a) or with End Of File (EOF).
**
**	The string stored in the parameter "line" should not contained any '\n'.
**
**	The parameter is the address of a pointer to a character that will be used to store the line read.
**
**	The return value can be 1, 0 or -1 depending on whether a line has been read, when the reading has been completed (meaning read has returned 0), or if an error has happened respectively.
**
**	When you've reached the End Of File, you must store the current buffer in "line". If the buffer is empty you must store an empty string in "line".
**
**	When you've reached the End Of File, your function should keep 0 memory allocated with malloc except the last buffer that you should have stored in "line".
**
**	What you've stored in "line" should be free-able.
**
**	Calling your function get_next_line in a loop will therefore allow you to read the text available on a file descriptor one line at a time until the end of the text, no matter the size of either the text or one of its lines.
**
**	Make sure that your function behaves well when it reads from a file, from the standard output, from a redirection etc.
**
**	No call to another function will be done on the file descriptor between 2 calls of get_next_line.
**
**	Finally we consider that get_next_line has an undefined behavior when reading from a binary file.
**
**	You should use the test.sh to help you test your get_next_line.
*/

/*
**	|-------------------------------- Main Function --------------------------------|
**
**	#include <stdio.h>
**	#include "get_next_line.h"
**
**	int	main(void)
**	{
**		int		r;
**		char	*line;
**
**		line = NULL;
**		while ((r = get_next_line(&line)) > 0)
**		{
**			printf("%s\n", line);
**			free(line);
**			line = NULL;
**		}
**		printf("%s", line);
**		free(line);
**		line = NULL;
**	}
*/

#include "./get_next_line.h"

void	*ft_memfree(void *all, void *npo)
{
	if (all)
		free(all);
	return (npo);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	while (s1[i])
		i++;
	str = (char *)malloc(i + 2);
	i = 0;
	j = 0;
	while (s1[i])
		str[j++] = s1[i++];
	str[j++] = s2[0];
	str[j] = '\0';
	return (str);
}

int		get_next_line(char **line)
{
	char	*buffer;
	char	*temp;
	int		bytes;

	if (!(buffer = (char *)malloc(sizeof(char) * 2))\
			|| !(*line = (char *)malloc(sizeof(char) * 1)))
		return (-1);
	(*line)[0] = '\0';
	while ((bytes = read(0, buffer, 1)) > 0)
	{
		buffer[bytes] = '\0';
		if (buffer[0] == '\n' || buffer[0] == '\0')
			break ;
		temp = ft_strjoin(*line, buffer);
		*line = ft_memfree(*line, temp);
	}
	buffer = ft_memfree(buffer, NULL);
	return (bytes);
}

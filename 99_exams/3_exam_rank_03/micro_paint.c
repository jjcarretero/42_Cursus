/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:56:13 by jcarrete          #+#    #+#             */
/*   Updated: 2021/12/16 00:04:58 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Assignment name  : micro_paint
**	Expected files   : *.c *.h
**	Allowed functions: fopen, fread, fscanf, fclose, write, malloc, calloc, realloc, free, memset, powf, sqrtf
**	--------------------------------------------------------------------------------------
**	
**	Write a program that will read an "operation file" and print the result in the terminal
**	
**	Your program must take one argument, it will be the path to the "operation file"
**	If 0 or more than 1 argument is given to your program write "Error: argument" followed by a \n in STDOUT
**	
**	$> ./micro_paint | cat -e
**	Error: argument$
**	$> ./micro_paint do not fear mathematics | cat -e
**	Error: argument$
**	$> 
**	
**	If any problem occurs while you open and/or read the "operation file" write "Error: Operation file corrupted" followed by a \n in STDOUT
**	
**	The "operation file" will contains lines with one operation per line
**	If a line is incorrect an error occurs.
**	If an error has occured your program must return 1
**	If no error has occured it must return 0
**	The last line can be with or without a \n
**	The lines must be read in order and therefore operations must be executed in the same order
**	There must be at least one space between each variable in a line
**	
**	WIDTH HEIGHT BACKGROUND_CHAR
**	This line is always the first line of the file and it defines the zone where to draw. Your program should not display anything outside the draw zone. It must be there only once.
**	- WIDTH: must be a int with 0 < WIDTH <= 300, the horizontal number of characters to use for the draw zone
**	- HEIGHT: must be a int with 0 < HEIGHT <= 300, the vertical number of characters to use for the draw zone 
**	- BACKGROUND_CHAR: any empty space will be filled with BACKGROUND_CHAR
**	
**	r X Y WIDTH HEIGHT CHAR
**	This operation will draw an empty rect, where only the border of the rect is drawn
**	- r: the character r
**	- X: any float, the horizontal position of the top left corner of the rect
**	- Y: any float, the vertical position of the top left corner of the rect
**	- WIDTH: a positive float but not 0, the width of the rect (horizontal)
**	- HEIGHT: a positive float but not 0, the height of the rect (vertical)
**	- CHAR: the char use to draw the rect
**	
**	R X Y WIDTH HEIGHT CHAR
**	This operation will draw a filled rect
**	- R: the character R
**	- X: any float, the horizontal position of the top left corner of the rect
**	- Y: any float, the vertical position of the top left corner of the rect
**	- WIDTH: a positive float but not 0, the width of the rect (horizontal)
**	- HEIGHT: a positive float but not 0, the height of the rect (vertical)
**	- CHAR: the char use to draw the rect
**	
**	The draw zone is divided in rects that can contain one character each (because we are in a terminal...), we will call them pixel
**	To make everything easier, we will use only the top left corner of the pixel to know if that pixel is in a rect or not
**	A pixel with a top left corner with a distance bigger or equal than 1 from the border of a rect is not part of an empty rect 
**	A pixel with a top left corner with a distance lower than 1 from the border of a rect is part of an empty rect.
**	
**	You should look at the image while reading the next few lines. It represents a terminal. We've set a draw zone of WIDTH 5 and HEIGHT 3.
**	We've wrote different character to help you understand the following explanations.
**	- If you want to draw the operation: r 2.5 1.5 1 1 X (the green rect)
**	-- it means that the character 'D' in the image will be replaced by 'X' 
**	
**	You should find our_micro_paint to help you test yours with some operation_file.example
**	
**	Hint:
**	If a point is defined as (Xa, Ya)
**	And a rect with a top left corner (Xtl, Ytl) and a bottom right corner (Xbr, Ybr)
**	If Xtl <= Xa <= Xbr and Ytl <= Ya <= Ybr then the point is in the rect
*/

#include "micro_paint.h"

/*
**	-------------------  UTILS  -------------------
*/

int	ft_memfree(void *s, int i)
{
	if (s)
	{
		free(s);
		s = NULL;
	}
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
		while (s[i])
			i++;
	return (i);
}

void	print_error(char *str)
{
	int	i;

	i = ft_strlen(str);
	write (STDOUT_FILENO, str, i);
	write (STDOUT_FILENO, "\n", 1);
}

void	print_result(t_drawing *drawing)
{
	int	i;

	i = 0;
	while (i < drawing->height)
	{
		write(STDOUT_FILENO, drawing->matrix + \
				(i * drawing->width), drawing->width);
		write (STDOUT_FILENO, "\n", 1);
		i++;
	}
	ft_memfree(drawing->matrix, SUCCESS);
}

int	check_limits(int size)
{
	if (size < MIN_SIZE || size > MAX_SIZE)
		return (ERROR);
	return (SUCCESS);
}

int	check_rect(t_rect *rect)
{
	if (rect->width <= 0.0f || rect->height <= 0.0f)
		return (ERROR);
	if (rect->type != 'R' && rect->type != 'r')
		return (ERROR);
	return (SUCCESS);
}

/*
**	-----------------  MICROPAINT  -----------------
*/

void	draw_rect(t_rect *rect, t_drawing *drawing, int x, int y)
{
	int		pos;
	float	fx;
	float	fy;

	fx = (float)x;
	fy = (float)y;
	pos = S_INSIDE;
	if ((fx < rect->x || (rect->x + rect->width) < fx) \
		|| (fy < rect->y || (rect->y + rect->height) < fy))
		pos = S_OUT;
	else if (((fx - rect->x) < 1.0f || ((rect->x + rect->width) - fx) < 1.0f) \
		|| ((fy - rect->y) < 1.0f || ((rect->y + rect->height) - fy) < 1.0f))
		pos = S_BORDER;
	if (pos == S_BORDER || (pos == S_INSIDE && rect->type == 'R'))
		drawing->matrix[x + (y * drawing->width)] = rect->color;
}

int	create_rect(t_rect *rect, t_drawing *drawing)
{
	int	j;
	int	i;

	if (check_rect(rect) == ERROR)
		return (ERROR);
	i = 0;
	while (i < drawing->height)
	{
		j = 0;
		while (j < drawing->width)
		{
			draw_rect(rect, drawing, j, i);
			j++;
		}
		i++;
	}
	return (SUCCESS);
}

int	get_zone_info(FILE *file, t_drawing *drawing)
{
	int		scan_ret;
	char	*tmp;
	int		i;
	char	background;

	scan_ret = fscanf(file, "%d %d %c\n", \
				&drawing->width, &drawing->height, &background);
	if (scan_ret == ZONE_INFO)
	{
		if (check_limits(drawing->width) == ERROR \
			|| check_limits(drawing->height) == ERROR)
			return (ERROR);
		tmp = (char *)malloc(drawing->width * drawing->height);
		drawing->matrix = tmp;
		if (drawing->matrix == NULL)
			return (ERROR);
		i = 0;
		while (i < drawing->width * drawing->height)
			drawing->matrix[i++] = background;
		return (SUCCESS);
	}
	return (ERROR);
}

int	micro_paint(FILE *file)
{
	int			scan_ret;
	t_drawing	drawing;
	t_rect		rect;

	if (get_zone_info(file, &drawing) == SUCCESS)
	{
		scan_ret = fscanf(file, "%c %f %f %f %f %c\n", \
				&rect.type, &rect.x, &rect.y, \
				&rect.width, &rect.height, &rect.color);
		while (scan_ret == RECT_INFO)
		{
			if (create_rect(&rect, &drawing) == ERROR)
				return (ft_memfree(drawing.matrix, ERROR));
			scan_ret = fscanf(file, "%c %f %f %f %f %c\n", \
					&rect.type, &rect.x, &rect.y, \
					&rect.width, &rect.height, &rect.color);
		}
		if (scan_ret == EOF)
		{
			print_result(&drawing);
			return (SUCCESS);
		}
		return (ft_memfree(drawing.matrix, ERROR));
	}
	return (ERROR);
}

int	main(int argc, char **argv)
{
	FILE	*file;

	if (argc == 2)
	{
		file = fopen(argv[1], "r");
		if (file && micro_paint(file) == SUCCESS)
			return (EXIT_SUCCESS);
		print_error("Error: Operation file corrupted");
	}
	else
		print_error("Error: argument");
	return (EXIT_FAILURE);
}

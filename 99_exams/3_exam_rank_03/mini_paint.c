/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:50:20 by jcarrete          #+#    #+#             */
/*   Updated: 2021/12/08 18:52:55 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Assignment name  : mini_paint
**	Expected files   : *.c *.h
**	Allowed functions: fopen, fread, fscanf, fclose, write, malloc, calloc, realloc, free, memset, powf, sqrtf
**	--------------------------------------------------------------------------------------
**	
**	Write a program that will read an "operation file" and print the result in the terminal
**	
**	Your program must take one argument, it will be the path to the "operation file"
**	If 0 or more than 1 argument is given to your program write "Error: argument" followed by a \n in STDOUT
**	
**	$> ./mini_paint | cat -e
**	Error: argument$
**	$> ./mini_paint do not fear mathematics | cat -e
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
**	c X Y RADIUS CHAR
**	This operation will draw a empty circle, where only the border of the circle is drawn
**	- c: the character c
**	- X: a float, the horizontal position of the center of the circle
**	- Y: a float, the vertical position of the center of the circle
**	- RADIUS: a positive float but not 0, the radius of the circle
**	- CHAR: the char use to draw the circle
**	
**	C X Y RADIUS  CHAR
**	This operation will draw a filled circle
**	- C: the character C
**	- X: a float, the horizontal position of the center of the circle
**	- Y: a float, the vertical position of the center of the circle
**	- RADIUS: a positive float but not 0, the radius of the circle
**	- CHAR: the char use to draw the circle
**	
**	
**	The draw zone is divided in rectangles that can contain one character each (because we are in a terminal...), we will call them pixel
**	To make everything easier, we will use only the top left corner of the pixel to know if that pixel is in a circle or not
**	If the distance between the top left corner of a pixel and the center of a circle is lower or equal to the radius of the circle, the pixel is part of the circle
**	but also:
**		A pixel with a top left corner with a distance bigger or equal than 1 from the border of a circle is not part of an empty circle 
**		A pixel with a top left corner with a distance lower than 1 from the border of a circle is part of an empty circle.
**	
**	You should look at the image while reading the next few lines. It represents a terminal. We've set a draw zone of WIDTH 5 and HEIGHT 3.
**	We've wrote different character to help you understand the following explanations.
**	- If you want to draw the operation: C 1.5 1.5 1 0 @ (the pink circle)
**	-- it means that the characters 'b', 'c', 'B', 'C' in the image will be replaced by '@'
**	
**	You should find our_mini_paint to help you test yours with some operation_file.example
**	
**	Hint:
**	If you've got 2 points are defined as (Xa,Ya) and (Xb,Yb)
**	You can get the distance between the two points with this formula: srqt((Xa - Xb) * (Xa - Xb) + (Ya - Yb) * (Ya - Yb))
*/

#include "mini_paint.h"

/*
**	-------------------  UTILS  -------------------
*/

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
		printf("%.*s\n", drawing->width, drawing->matrix + i * drawing->width);
		i++;
	}
}

int	check_limits(int size)
{
	if (size < MIN_SIZE || size > MAX_SIZE)
		return (ERROR);
	return (SUCCESS);
}

int	check_circle(t_circle *circle)
{
	if (circle->radius = 0.0f)
		return (ERROR);
	if (circle->type != 'C' || circle->type != 'c')
		return (ERROR);
	return (SUCCESS);
}

/*
**	-----------------  MINIPAINT  -----------------
*/

int	create_circle(t_circle *circle, t_drawing *drawing)
{
	int	j;
	int	i;

	if (check_circle(circle) == ERROR)
		return (ERROR);
	i = 0;
	while (i < drawing->width)
	{
		j = 0;
		while (j < drawing->height)
		{
			execute_one(circle, drawing, i, j);
			i++;
			j++;
		}
	}
	return (0);
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

int	mini_paint(FILE *file)
{
	int			scan_ret;
	t_drawing	drawing;
	t_circle	circle;

	if (get_zone_info(file, &drawing) == SUCCESS)
	{
		scan_ret = fscanf(file, "%c %f %f %f %c\n", \
				&circle.type, &circle.x, &circle.y, \
				&circle.radius, &circle.color);
		while (scan_ret == CIRCLE_INFO)
		{
			if (create_circle(&circle, &drawing) == ERROR)
				return (ERROR);
			scan_ret = fscanf(file, "%c %f %f %f %c\n", \
					&circle.type, &circle.x, &circle.y, \
					&circle.radius, &circle.color);
		}
		if (scan_ret == EOF)
		{
			print_info(&drawing);
			return (SUCCESS);
		}
		return (ERROR);
	}
	return (ERROR);
}

int	main(int argc, char **argv)
{
	int		i;
	FILE	*file;

	if (argc == 2)
	{
		file = fopen(argv[1], "r");
		if (file && mini_paint(file) == SUCCESS)
			return (EXIT_SUCCESS);
		print_error("Error: Operation file corrupted");
	}
	else
		print_error("Error: argument");
	return (EXIT_FAILURE);
}

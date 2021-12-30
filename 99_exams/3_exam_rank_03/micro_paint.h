/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   micro_paint.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 13:56:38 by jcarrete          #+#    #+#             */
/*   Updated: 2021/12/11 15:47:15 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICRO_PAINT_H
# define MICRO_PAINT_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>

# define ERROR			-1
# define SUCCESS		0
# define ZONE_INFO		3
# define RECT_INFO		6
# define MATRIX_INFO		3
# define MIN_SIZE		1
# define MAX_SIZE		300

enum	e_state
{
	S_OUT,
	S_BORDER,
	S_INSIDE
};

typedef struct s_drawing
{
	int		width;
	int		height;
	char		background;
	char		*matrix;
}			t_drawing;

typedef struct s_rect
{
	char	type;
	float	x;
	float	y;
	float	width;
	float	height;
	char	color;
}			t_rect;
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 16:58:08 by jcarrete          #+#    #+#             */
/*   Updated: 2021/12/11 11:52:08 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_PAINT_H
# define MINI_PAINT_H

# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <unistd.h>

# define ERROR			-1
# define SUCCESS		0
# define ZONE_INFO		3
# define CIRCLE_INFO		5
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

typedef struct s_circle
{
	char	type;
	float	x;
	float	y;
	float	radius;
	char	color;
}			t_circle;
#endif

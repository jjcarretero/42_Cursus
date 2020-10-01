/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 15:44:15 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/28 15:44:15 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Assignment name  : union
**	Expected files   : union.c
**	Allowed functions: write
**	--------------------------------------------------------------------------------
**
**	Write a program that takes two strings and displays, without doubles, the
**	characters that appear in either one of the strings.
**
**	The display will be in the order characters appear in the command line, and
**	will be followed by a \n.
**
**	If the number of arguments is not 2, the program displays \n.
**
**	Example:
**
**	$>./union zpadinton "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
**	zpadintoqefwjy$
**	$>./union ddf6vewg64f gtwthgdwthdwfteewhrtag6h4ffdhsd | cat -e
**	df6vewg4thras$
**	$>./union "rien" "cette phrase ne cache rien" | cat -e
**	rienct phas$
**	$>./union | cat -e
**	$
**	$>
**	$>./union "rien" | cat -e
**	$
**	$>
*/

#include <unistd.h>

int main(int argc, char const *argv[])
{
	int	hashmap[256];
	int	i;
	int j;

	if (argc == 3)
	{
		i = 0;
		while (i < 256)
		{
			hashmap[i] = 0;
			i++;
		}
		j = 1;
		while (j < 3)
		{
			i = 0;
			while (argv[j][i])
			{
				if (hashmap[(int)argv[j][i]] == 0)
				{
					write (1, &argv[j][i], 1);
					hashmap[(int)argv[j][i]]++;
				}
				i++;
			}
			j++;
		}
	}
	write(1, "\n", 1);
	return (0);
}


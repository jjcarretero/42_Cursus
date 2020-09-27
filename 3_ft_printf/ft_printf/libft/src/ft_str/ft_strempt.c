/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strempt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 16:55:25 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/02 00:19:03 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

void	ft_strempt(char *s)
{
	ft_bzero(s, ft_strlen(s));
}

void	ft_strempt_endchar(char *str, char c)
{
	int	i;

	i = ft_strlen(str) - 1;
	while (i >= 0 && str[i] == c)
		str[i--] = '\0';
}

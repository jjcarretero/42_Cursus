/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 23:44:38 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/11 18:18:18 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

char	*ft_strappend_nchr(char *str, int c, int nb)
{
	int		len;
	int		s;
	int		i;
	char	*temp;

	len = ft_strlen(str) + nb;
	temp = ft_strnew(len + 1);
	i = 0;
	s = 0;
	while (str[s])
	{
		temp[s] = str[s];
		s++;
	}
	while (i < nb)
	{
		temp[s] = c;
		i++;
		s++;
	}
	temp[len] = '\0';
	return (temp);
}

char	*ft_strappstart_nchr(char *str, int c, int nb)
{
	int		len;
	int		s;
	int		i;
	char	*temp;

	len = ft_strlen(str) + nb;
	temp = ft_strnew(len + 1);
	i = 0;
	s = 0;
	while (i < nb)
	{
		temp[i] = c;
		i++;
	}
	while (str[s])
	{
		temp[i] = str[s];
		s++;
		i++;
	}
	temp[len] = '\0';
	return (temp);
}

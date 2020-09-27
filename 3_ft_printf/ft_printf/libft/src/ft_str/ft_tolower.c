/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:28:34 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/22 23:57:02 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int			ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}

char		*ft_str_tolower(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_calloc(sizeof(str), sizeof(char));
	while (str[i] != '\0')
	{
		if (str[i] >= 65 && str[i] <= 90)
			ret[i] = str[i] + 32;
		else
			ret[i] = str[i];
		i++;
	}
	return (ret);
}

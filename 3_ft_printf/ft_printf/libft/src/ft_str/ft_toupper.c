/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 17:29:44 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/23 00:04:31 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/libft.h"

int			ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}

char		*ft_str_toupper(char *str)
{
	int		i;
	char	*ret;

	i = 0;
	ret = ft_calloc(sizeof(str), sizeof(char));
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			ret[i] = str[i] - 32;
		else
			ret[i] = str[i];
		i++;
	}
	return (ret);
}

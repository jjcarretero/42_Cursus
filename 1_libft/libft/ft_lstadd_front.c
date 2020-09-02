/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 16:48:43 by jcarrete          #+#    #+#             */
/*   Updated: 2020/07/23 16:49:06 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

void	ft_lstadd_front(t_list **alst, t_list *newlst)
{
	if (alst == NULL || newlst == NULL)
		return ;
	newlst->next = *alst;
	*alst = newlst;
}

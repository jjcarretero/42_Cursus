/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 14:05:58 by jcarrete          #+#    #+#             */
/*   Updated: 2021/12/12 16:07:43 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	add_single_exp(char ***envp, char *arg)
{
	int		len;
	char	**print_exp;
	char	**aux;

	len = double_len(*envp);
	print_exp = ft_envdup(*envp, len, 2, NULL);
	print_exp[len] = ft_strdup(arg);
	aux = *envp;
	*envp = print_exp;
	free_char_array(aux, len);
}

void	delete_var(char ***envp, char *del)
{
	char	**new_envp;
	char	**aux;
	int		len;

	if (del == NULL)
		return ;
	len = double_len(*envp);
	new_envp = ft_envdup(*envp, len, 0, del);
	aux = *envp;
	*envp = new_envp;
	free_char_array(aux, len);
}

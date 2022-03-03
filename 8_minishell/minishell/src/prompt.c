/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 23:03:12 by jcarrete          #+#    #+#             */
/*   Updated: 2022/01/03 20:56:52 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*set_prompt(char *sep)
{
	t_minishell	*shell;
	char		*ret;
	char		*tmp;
	char		*nb;

	shell = get_minishell(NULL);
	tmp = find_value(shell->envp_dup, "USER");
	ret = ft_strjoin(tmp, "@MINIsh ");
	tmp = ft_memfree(tmp, ft_strjoin(ret, "("));
	nb = ft_itoa(shell->exit_code);
	ret = ft_memfree(ret, ft_strjoin(tmp, nb));
	tmp = ft_memfree(tmp, ft_strjoin(ret, ")"));
	ret = ft_memfree(ret, ft_strjoin(tmp, sep));
	tmp = ft_memfree(tmp, NULL);
	nb = ft_memfree(nb, NULL);
	return (ret);
}

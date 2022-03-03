/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_no_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 15:33:17 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/04 21:22:41 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_variables(char **envp, int i, int j)
{
	ft_putstr_fd("declare -x ", STDOUT_FILENO);
	if (ft_strchr((envp[i]), '='))
	{
		while (envp[i][j] != '=')
			j++;
		write(STDOUT_FILENO, envp[i], j + 1);
		ft_putchar_fd('\"', STDOUT_FILENO);
		ft_putstr_fd(&envp[i][j + 1], STDOUT_FILENO);
		ft_putchar_fd('\"', STDOUT_FILENO);
	}
	else
		ft_putstr_fd(envp[i], STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
}

static void	sort_envp(char ***envp)
{
	int		i;
	int		j;

	i = 0;
	while ((*envp)[i])
	{
		j = 0;
		while ((*envp)[j])
		{
			if (ft_strcmp((*envp)[i], (*envp)[j]) < 0)
				ft_swap_str(&((*envp)[i]), &((*envp)[j]));
			j++;
		}
		i++;
	}
}

int	no_args_export(char **envp_dup)
{
	int		i;
	int		j;
	int		len;
	char	**envp;

	if (!envp_dup)
		return (EXIT_FAILURE);
	envp = ft_envdup(envp_dup, double_len(envp_dup), 1, NULL);
	len = double_len(envp);
	sort_envp(&envp);
	i = 0;
	while (i < len)
	{
		if (envp[i][0] != '_')
		{
			j = 0;
			print_variables(envp, i, j);
		}
		i++;
	}
	free_char_array(envp, len);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/12 16:05:03 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/05 00:35:11 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	unset_variable(char **args, char ***envp, int i)
{
	char		*find;

	find = find_variable(*envp, args[i], NULL);
	if (find)
		delete_var(envp, args[i]);
	find = ft_memfree(find, NULL);
}

int	check_options(char **args, t_minishell *shell)
{
	if (args[1][0] == '-')
	{
		ft_putstr_fd("MINIshell: ", shell->save_std.out);
		ft_putstr_fd(args[0], shell->save_std.out);
		ft_putstr_fd(":`", shell->save_std.out);
		ft_putstr_fd(args[1], shell->save_std.out);
		ft_putstr_fd("': invalid option\n", shell->save_std.out);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_unset(char **args, char ***envp)
{
	t_minishell	*shell;
	int			i;

	shell = get_minishell(NULL);
	shell->exit_code = check_options(args, shell);
	i = 1;
	while (args[i] && shell->exit_code == EXIT_SUCCESS)
	{
		shell->exit_code = check_syntax(args[i]);
		if (shell->exit_code == EXIT_FAILURE)
		{
			ft_putstr_fd("MINIshell: unset:`", shell->save_std.out);
			ft_putstr_fd(args[i], shell->save_std.out);
			ft_putstr_fd("': not a valid identifier\n", shell->save_std.out);
		}
		else
			unset_variable(args, envp, i);
		i++;
	}
	return (shell->exit_code);
}

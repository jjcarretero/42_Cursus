/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 23:04:31 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/05 00:27:20 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_syntax(char *arg)
{
	int	i;

	i = 0;
	if (arg[0] == '=' || ft_isdigit(arg[0]))
		return (EXIT_FAILURE);
	while (arg[i] && arg[i] != '=')
	{
		if ((ft_isalnum(arg[i]) == 0) && (arg[i] != '_'))
			return (EXIT_FAILURE);
		i++;
	}
	return (EXIT_SUCCESS);
}

static void	export_variable(char **args, char ***envp, int i)
{
	int		no_deleted;
	char	*find;

	no_deleted = 0;
	find = find_variable(*envp, args[i], &no_deleted);
	delete_var(envp, find);
	if (!no_deleted)
		add_single_exp(envp, args[i]);
	find = ft_memfree(find, NULL);
}

int	ft_export(char **args, char ***envp)
{
	int			i;
	t_minishell	*shell;

	shell = get_minishell(NULL);
	i = 1;
	if (args[i] == NULL)
		shell->exit_code = no_args_export(*envp);
	else
		shell->exit_code = check_options(args, shell);
	while (args[i] && shell->exit_code == EXIT_SUCCESS)
	{
		shell->exit_code = check_syntax(args[i]);
		if (shell->exit_code == EXIT_FAILURE)
		{
			ft_putstr_fd("MINIshell: export:`", shell->save_std.out);
			ft_putstr_fd(args[i], shell->save_std.out);
			ft_putstr_fd("': not a valid identifier\n", shell->save_std.out);
		}
		else
			export_variable(args, envp, i);
		i++;
	}
	return (shell->exit_code);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpunet <rpunet@student.42madrid.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:51:47 by rpunet            #+#    #+#             */
/*   Updated: 2022/02/05 00:05:37 by rpunet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_minishell	*init_struct(void)
{
	t_minishell	*ret;

	ret = ft_calloc(1, sizeof(t_minishell));
	if (ret == NULL)
		exit_program(ret, F_NONE, E_MEM, strerror(errno));
	get_minishell(ret);
	ret->state = ST_OK;
	ret->line = NULL;
	ret->lexer.list_token = NULL;
	ret->bst = NULL;
	ret->envp_dup = NULL;
	ret->exit_code = EXIT_SUCCESS;
	ret->std.in = STDIN_FILENO;
	ret->save_std.in = STDIN_FILENO;
	ret->std.out = STDOUT_FILENO;
	ret->save_std.out = STDOUT_FILENO;
	ret->path = NULL;
	return (ret);
}

void	interactive_shell(t_minishell *shell, int argc)
{
	set_shell_signals(shell);
	initialize_minishell(shell, argc);
}

static void	init_noninteractive(t_minishell *shell, int fd)
{
	char	*line;
	int		size;

	size = 1;
	while (size > 0 && shell->state == ST_OK)
	{
		size = ft_get_next_line(fd, &line);
		if (size == -1)
		{
			ft_putstr_fd("MINIshell: GNL: ", STDOUT_FILENO);
			ft_putstr_fd(strerror(errno), STDOUT_FILENO);
			shell->exit_code = EXIT_FAILURE;
			break ;
		}
		initialize_minishell(shell, 2);
		line = ft_memfree(line, NULL);
	}
}

void	not_interactive_shell(t_minishell *shell, char *argv)
{
	int		fd;

	fd = open(argv, O_RDONLY);
	if (fd == ERROR)
	{
		ft_putstr_fd("MINIshell: ", STDOUT_FILENO);
		ft_putstr_fd(argv, STDOUT_FILENO);
		ft_putstr_fd(": ", STDOUT_FILENO);
		ft_putstr_fd(strerror(errno), STDOUT_FILENO);
		shell->exit_code = EB_CATCHALL;
		return ;
	}
	init_noninteractive(shell, fd);
	close(fd);
}

int	main(int argc, char **argv, char **envp)
{
	t_minishell	*shell;
	int			exit_code;

	shell = init_struct();
	shell->envp_dup = ft_envdup(envp, double_len(envp), 1, NULL);
	envp = shell->envp_dup;
	if (argc > 1 && !ft_strcmp(argv[1], "-c"))
	{
		shell->line = ft_strdup(argv[2]);
		interactive_shell(shell, argc);
	}
	else if (argc == 1)
		interactive_shell(shell, argc);
	else
		not_interactive_shell(shell, argv[1]);
	exit_code = shell->exit_code;
	free_program(shell, F_SUCCESS);
	return (exit_code);
}

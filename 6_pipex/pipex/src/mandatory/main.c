/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:37:01 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/09 16:48:56 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	create_envp(t_pipex_block	**ret, char **envp)
{
	int		i;
	int		count;
	char	**temp;

	i = 0;
	while (envp[i] && \
		ft_strnstr(envp[i], "PATH=", ft_strlen(envp[i])) == NULL)
		i++;
	temp = ft_split(envp[i], ':');
	count = ft_str_arr_count(temp);
	(*ret)->envp = ft_memalloc(sizeof(char *) * count);
	ft_memmove(&(*ret)->envp[0], &temp[1], \
				(count - 1) * sizeof((*ret)->envp[0]));
	temp[0] = ft_memfree(temp[0], NULL);
	temp = ft_memfree(temp, NULL);
	if ((*ret)->envp == FALSE)
		return (ERROR);
	return (SUCCESS);
}

static t_pipex_block	*prepare_block(char **argv, char **envp)
{
	t_pipex_block	*ret;

	ret = (t_pipex_block *)malloc(sizeof(t_pipex_block));
	if (ret == NULL)
		exit_program(ret, F_BLOCK, E_MEM, strerror(errno));
	ret->fd.io[FILE_IN] = open(argv[1], O_RDONLY);
	ret->fd.io[FILE_OUT] = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, S_IRWUGO);
	ret->tokens = NULL;
	ret->tmp_cmd = NULL;
	if (create_envp(&ret, envp) == ERROR)
		exit_program(ret, F_ENVP, E_PATH, NULL);
	return (ret);
}

static void	check_arguments(int argc, char **argv)
{
	if (argc != 5)
		exit_program(NULL, F_NONE, E_ARGS, NULL);
	if (access(argv[1], F_OK) == -1)
		exit_program(NULL, F_NONE, E_FILE, argv[1]);
	if (access(argv[1], R_OK) == -1)
		exit_program(NULL, F_NONE, E_PERM_R, argv[1]);
	if (access(argv[4], F_OK) == -1)
		exit_program(NULL, F_NONE, E_FILE, argv[4]);
	if (access(argv[4], W_OK) == -1)
		exit_program(NULL, F_NONE, E_PERM_W, argv[4]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex_block	*b;

	check_arguments(argc, argv);
	b = prepare_block(argv, envp);
	parser(argv, b);
	pipex(b);
	exit_program(b, F_SUCCESS, E_SUCCESS, NULL);
}

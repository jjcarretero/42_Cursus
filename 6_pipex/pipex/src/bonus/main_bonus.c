/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:37:01 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/09 16:48:00 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

static t_pipex_block	*prepare_block(int argc, char **argv, \
										char **envp, int here_doc)
{
	t_pipex_block	*ret;

	ret = (t_pipex_block *)malloc(sizeof(t_pipex_block));
	if (ret == NULL)
		exit_program(ret, F_BLOCK, E_MEM, strerror(errno));
	ret->here_doc = here_doc;
	ret->tokens = NULL;
	ret->tmp_cmd = NULL;
	ret->literal = NULL;
	if (ret->here_doc == TRUE)
	{
		ret->fd.io[P_OUT] = open(argv[argc - 1], \
								O_CREAT | O_WRONLY | O_APPEND, S_IRWUGO);
		ret->limit = argv[2];
	}
	else
	{
		ret->fd.io[P_IN] = open(argv[1], O_RDONLY);
		ret->fd.io[P_OUT] = open(argv[argc - 1], \
								O_CREAT | O_WRONLY | O_TRUNC, S_IRWUGO);
	}
	if (create_envp(&ret, envp) == ERROR)
		exit_program(ret, F_ENVP, E_PATH, NULL);
	return (ret);
}

static void	check_arguments(int argc, char **argv, int *here_doc)
{
	if (argc < 5)
		exit_program(NULL, F_NONE, E_ARGS, NULL);
	*here_doc = !ft_strncmp(argv[1], "here_doc", 9);
	if (*here_doc == TRUE && argc < 6)
		exit_program(NULL, F_NONE, E_ARGS, NULL);
	if (*here_doc == FALSE && access(argv[1], F_OK) == -1)
		exit_program(NULL, F_NONE, E_FILE, argv[1]);
	if (*here_doc == FALSE && access(argv[1], R_OK) == -1)
		exit_program(NULL, F_NONE, E_PERM_R, argv[1]);
	if (access(argv[argc - 1], F_OK) == -1)
		exit_program(NULL, F_NONE, E_FILE, argv[argc - 1]);
	if (access(argv[argc - 1], W_OK) == -1)
		exit_program(NULL, F_NONE, E_PERM_W, argv[argc - 1]);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex_block	*b;
	int				here_doc;

	check_arguments(argc, argv, &here_doc);
	b = prepare_block(argc, argv, envp, here_doc);
	if (b->here_doc == TRUE)
	{
		b->fd.io[P_IN] = here_document(b);
		argv++;
		argc--;
	}
	parser(argc, argv, b);
	pipex(b);
	exit_program(b, F_SUCCESS, E_SUCCESS, NULL);
}

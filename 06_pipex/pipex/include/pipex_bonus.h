/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:26:00 by jcarrete          #+#    #+#             */
/*   Updated: 2021/10/23 23:32:20 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "libft.h"
# include "ft_printf.h"
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

# define S_IRWUGO 0666
# define D_EQUAL 0

typedef struct s_pipe
{
	int				io[2];
}					t_pipe;

typedef struct s_tok
{
	char			*path;
	char			**exec_args;
}					t_tok;

typedef struct s_pipex_block
{
	t_pipe	fd;
	t_list	*tokens;
	char	**tmp_cmd;
	char	**envp;
	int		here_doc;
	char	*limit;
	char	*literal;
}				t_pipex_block;

enum e_file
{
	FILE_IN,
	FILE_OUT
};

enum e_pipe
{
	P_IN,
	P_OUT
};

enum e_free
{
	F_NONE,
	F_BLOCK,
	F_ENVP,
	F_LITERAL,
	F_CMD,
	F_SUCCESS
};

enum e_errors
{
	E_NONE,
	E_MEM,
	E_ARGS,
	E_FILE,
	E_PERM_R,
	E_PERM_W,
	E_PATH,
	E_CMD,
	E_DUP,
	E_PIPE,
	E_FORK,
	E_SUCCESS
};

void	exit_program(t_pipex_block *b, int status, int err, char *extra);
void	free_char_array(char ***arr);
void	parser(int argc, char **argv, t_pipex_block *b);
void	pipex(t_pipex_block *b);
int		here_document(t_pipex_block *b);
#endif

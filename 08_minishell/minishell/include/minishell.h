/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/20 19:51:50 by rpunet            #+#    #+#             */
/*   Updated: 2022/02/05 18:50:48 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

/*
** LIBRARIES ---------------------------------
*/

# include "libft.h"
# include "ft_printf.h"
# include <errno.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <dirent.h>
# include <signal.h>
# include <readline/readline.h>
# include <readline/history.h>

/*
** DEFINES ---------------------------------
*/

# define READ			0
# define WRITE			1
# define BUILTINS		2

# define S_IRWUGO		0666

# define TRUE			1
# define FALSE			0
# define EXEC_FAILURE		-1

# define EXIT_STATUS	128

# define WHOAMI			"/usr/bin/whoami"
# define OPERATORS		";><|()&"
# define SPECIAL_CHARS	"\'\"\\ "
# define WILDCARD		'*'

/*
** ENUMS ---------------------------------
*/

enum	e_tok
{
	T_TOKEN = -1,
	T_SEMICOLON = ';',
	T_SPACE = ' ',
	T_PIPE = '|',
	T_REDIR = '>',
	T_INDIR = '<',
	T_LIMITER = 6060,
	T_APPEND = 6262,
	T_DIR = 6666,
	T_QUOTE = '\'',
	T_DQUOTE = '\"',
	T_ESCAPE = '\\',
	T_BRAKET_OPEN = '(',
	T_BRAKET_CLOSE = ')',
	T_OR = 124124,
	T_AND = 3838,
	T_NULTOK = 0,
};

enum	e_seq
{
	S_GENERAL,
	S_QUOTED,
	S_DQUOTED,
	S_VAR,
	S_SCAPED,
};

enum	e_pipe
{
	P_IN,
	P_OUT
};

enum	e_node
{
	SEQ_NODE,
	PIPE_NODE,
	REDIR_NODE,
	INDIR_NODE,
	APPEND_NODE,
	LIMIT_NODE,
	AND_NODE,
	OR_NODE,
	CMDNAME_NODE,
	FILENAME_NODE,
	TOKEN_NODE
};

enum	e_state
{
	ST_OK = 1,
	ST_PREPARED,
	ST_SIGINT,
	ST_READLINE,
	ST_ERROR,
	ST_SUCCESS
};

enum	e_free
{
	F_NONE,
	F_SHELL,
	F_SUCCESS
};

enum	e_bash_error
{
	EB_NONE,
	EB_CATCHALL = 1,
	EB_MISUSE_BUILTINS = 2,
	EB_COMMAND_CANNOT_EXECUTE = 126,
	EB_COMMAND_NOT_FOUND = 127,
	EB_INVALID_ARG = 128,
	EB_EXIT_OUT_RANGE = 255
};

enum	e_error
{
	E_NONE,
	E_MEM = 3,
	E_SIG,
	E_LEXER,
	E_PARSER,
	E_SYNTAX,
	E_EXECUTE,
	E_EXIT
};

/*
** STRUCTS ---------------------------------
*/

typedef struct s_ast_node
{
	int					type;
	char				*data;
	struct s_ast_node	*left;
	struct s_ast_node	*right;
}					t_ast_node;

typedef struct s_pipe
{
	int				in;
	int				out;
}					t_pipe;

typedef struct s_exec
{
	t_ast_node	*cmd_node;
	int			fds[2];
	char		**args;
}					t_exec;

typedef struct s_tok
{
	char			*data;
	int				type;
	struct s_tok	*next;
}					t_tok;

typedef struct s_bst
{
	int				operator_child;
	int				operator_next;
	t_ast_node		*tree;
	struct s_bst	*child;
	struct s_bst	*next;
	struct s_bst	*prev;
}				t_bst;

typedef struct s_lex
{
	int				line_pos;
	int				token_pos;
	int				seq_state;
	int				last_quoted;
	int				brackets;
	t_tok			*current_tok;
	t_tok			*list_token;
}					t_lex;

typedef struct s_minishell
{
	int				state;
	char			*prompt;
	int				exit_code;
	char			*line;
	t_pipe			std;
	t_pipe			save_std;
	t_lex			lexer;
	t_bst			*bst;
	char			**envp_dup;
	char			*path;
}					t_minishell;

typedef int	(*t_ft_builtins)(char **, char ***);

/*
** tipo general para comprobaciones de free, etc
** de los tipos terminales que guardan datos en node->data.
** los demás solo tienen node->type
*/

t_tok		*g_current_tok;

/*
** MINISHELL ---------------------------------
*/

void		do_nothing(void *vd);
int			double_len(char **arr);
void		print_error(t_minishell *shell, int err, char *extra);
void		exit_program(t_minishell *shell, int status, int err, char *extra);
char		*find_directory(DIR **dir, char **args);
void		free_program(t_minishell *shell, int status);
void		free_char_array(char **arr, int size);
void		*free_bst(t_bst *bst);
char		**ft_envdup(char **envp, int len, int add, char *ignore);
t_minishell	*get_minishell(t_minishell *minishell);
void		initialize_minishell(t_minishell *shell, int argc);
void		null_line(void);
char		*read_key(char *var);
void		*return_null(char *ptr);
char		*set_prompt(char *sep);
void		set_shell_signals(t_minishell *shell);

/*
** PARSER ------------------------------------
*/

int			get_operator_type(int type);
int			get_dir_type(void);
int			get_seq_type(void);
int			ft_parser(t_minishell *shell);
void		ast_delete(t_ast_node **node);
void		delete_single_ast(t_ast_node **node);
int			terminal(int tokentype);
int			terminal_redir(void);
int			terminal_seq(void);
t_ast_node	*create_parent_node(int type, char *data, \
				t_ast_node *left, t_ast_node *right);
t_ast_node	*gr_seq(void);
t_ast_node	*gr_seq_1(void);
t_ast_node	*gr_seq_2(void);
t_ast_node	*gr_seq_3(void);
t_ast_node	*gr_job(void);
t_ast_node	*gr_job_1(void);
t_ast_node	*gr_job_2(void);
t_ast_node	*gr_instr(void);
t_ast_node	*gr_instr_1(void);
t_ast_node	*gr_instr_2(void);
t_ast_node	*gr_cmd(void);
t_ast_node	*gr_cmd_1(void);
t_ast_node	*gr_dir(void);
t_ast_node	*gr_dir_1(void);
t_ast_node	*gr_dir_2(void);
t_ast_node	*gr_tokenlist(void);
t_ast_node	*gr_tokenlist_1(void);
t_ast_node	*gr_tokenlist_2(void);
t_bst		*create_bst_node(void);
void		parse_brackets(t_minishell *shell);
void		expand_filenames(t_tok **list);
t_tok		**add_new_token(t_tok **list, char *d_name);
t_tok		*ft_toklist_last(t_tok *lst);
int			check_if_wildcard(char *str);

/*
** LEXER -------------------------------------
*/

void		expand_vars(char **str);
char		*find_value(char **envp, char *key);
int			ft_lexer(t_minishell *shell);
t_tok		*tok_init(int datasize);
void		tok_delete(t_tok **token);
void		fill_data(t_lex *lexer, t_tok **token, char *line, int end);
int			operator_length(t_lex *lexer, char *line);
void		check_tokens(t_minishell *shell, t_tok *list);
char		*check_expansion(char *str);

/*
** EXECUTOR ----------------------------------
*/

void		add_single_exp(char ***envp, char *arg);
int			check_builtins(char **args, char **envp);
int			check_if_redir(int type);
int			count_commands(t_ast_node *cmd_node);
void		delete_var(char ***envp, char *del);
int			exec_process(char **args, char **envp, int i);
void		execute_cmd(t_minishell *shell, t_exec *exec, char ***envp);
void		execute_instr(t_minishell *shell, t_exec *exec, char ***envp);
void		execute_instr_pipe(t_minishell *shell, t_exec *exec, char ***envp);
void		execute_job(t_minishell *shell, t_ast_node *job, char ***envp);
void		execute_seq(t_minishell *shell, t_ast_node *seq, char ***envp);
char		*find_variable(char **envp, char *arg, int *no_del);
int			ft_cd(char **args, char ***envp);
int			ft_echo(char **args, char ***envp);
int			ft_env(char **args, char ***envp);
void		ft_execute(t_minishell *shell);
int			ft_exit(char **argv);
int			ft_export(char **args, char ***envp);
int			ft_unset(char **args, char ***envp);
int			ft_pwd(char **arg, char ***envp);
int			no_args_export(char **envp_dup);
int			here_doc(t_minishell *shell, t_exec *exec);
char		*set_command_path(t_exec *exec);
void		execute_redirection(t_minishell *shell, t_exec *exec, char ***envp);
void		execute_bst(t_minishell *shell, t_bst *bst, char ***envp);
int			check_syntax(char *arg);
int			check_options(char **args, t_minishell *shell);
#endif

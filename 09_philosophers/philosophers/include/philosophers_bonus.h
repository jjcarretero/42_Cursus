/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 22:55:52 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/26 23:17:16 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_BONUS_H
# define PHILOSOPHERS_BONUS_H

/*
** LIBRARIES ---------------------------------
*/

# include "bash_colors.h"
# include <fcntl.h>
# include <limits.h>
# include <semaphore.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/time.h>
# include <sys/wait.h>
# include <unistd.h>

/*
** MESSAGES -----------------------------------
*/

# define MSG_MEMORY "Unable to allocate memory"
# define MSG_ARGS_NUM "Invalid number of arguments: "
# define MSG_ARGS_VAL "Arguments must be positive integers"
# define MSG_USAGE "This program should take the following arguments: \
number_of_philosophers time_to_die time_to_eat time_to_sleep \
[number_of_times_each_philosopher_must_eat]"
# define MSG_ADD_PHILO "Unable to create new philosophers"
# define MSG_OPEN_SEM "Unable to open semaphore"
# define MSG_CHILD "Unable to create child process"

# define BUF_SIZE 80
# define MSG_MID " | \033[0;35m"
# define MSG_FORK "\033[0;94m has taken a fork\n\033[0m"
# define MSG_EAT "\033[0;34m is eating\n\033[0m"
# define MSG_SLEEP "\033[0;33m is sleeping\n\033[0m"
# define MSG_THINK "\033[0;32m is thinking\n\033[0m"
# define MSG_DIE "\033[0;31m died\n\033[0m"

# define SEM_FORK "\\forks"
# define SEM_PRINT "\\print_status"
# define SEM_DEATH "\\death_status"

/*
** ENUMS -----------------------------------
*/

enum	e_sizes
{
	SIZE_MID = 11,
	SIZE_FORK = 30,
	SIZE_EAT = 23,
	SIZE_SLEEP = 25,
	SIZE_THINK = 25,
	SIZE_DIE = 18
};

enum	e_return
{
	RET_ERROR = -1,
	RET_SUCCESS = 0
};

enum	e_bool
{
	FALSE,
	TRUE
};

enum	e_nb_property
{
	NB_EVEN,
	NB_ODD
};

enum	e_philo_state
{
	STATE_FORK,
	STATE_THINKING,
	STATE_EATING,
	STATE_SLEEPING,
	STATE_DYING,
	STATE_DEAD
};

enum	e_errors
{
	ERROR_NONE,
	ERROR_ARGSNUM,
	ERROR_ARGVALUE,
	ERROR_MEM,
	ERROR_PHILO,
	ERROR_OPEN_SEM,
	ERROR_CHILD
};

enum	e_free_state
{
	FREE_NONE,
	FREE_PROG
};

/*
** STRUCTS ------------------------------------
*/

typedef struct s_list
{
	void			*ptr;
	struct s_list	*next;
}	t_list;

typedef struct s_args
{
	long			start_time;
	int				nb_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_to_eat;
}				t_args;

typedef struct s_philo
{
	t_args			*args;
	int				state;
	unsigned int	id;
	long			last_eat_time;
	int				eat_count;
}				t_philo;

typedef struct s_monitor
{
	int			nb_processes;
	t_philo		*philo;
	t_list		*garbage;
	t_args		*args;
	int			death;
	pid_t		*pid;
	int			*exit_code;
	sem_t		*print_status;
	sem_t		*death_status;
	sem_t		*forks;
}				t_monitor;

/*
** PHILOSOPHERS ---------------------------------
*/

int			init_monitor(t_monitor **monitor);
int			init_philos(t_philo **philo);
int			check_args(int argc, char **argv);

void		kill_processes(void);
int			handle_error(int free_state, int error);

void		*philo_cycle(t_philo *curr);
void		philo_take_forks(t_monitor *monitor, t_philo **philo);
void		philo_drop_forks(t_monitor *monitor);
void		philo_thinking(t_philo **philo);
void		philo_eating(t_monitor *monitor, t_philo **philo);
void		philo_sleeping(t_monitor *monitor, t_philo **philo);
int			philo_print_status(long time, unsigned int id, \
									char *state, int size);

int			create_monitor_process(t_monitor *monitor);

void		clean_gcollector(void);
t_list		*add_to_gcollector(void *ptr, int *error);

/*
** UTILS ---------------------------------------
*/

int			ft_atoi(const char *str);
t_monitor	*ft_getmonitor(t_monitor *ptr);
long		ft_gettime(void);
int			ft_ltoa(char *str, long n, int size);
void		*ft_memalloc(size_t n, int *error);
void		*ft_memfree(void *all, void *npo);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
size_t		ft_strlen(const char *s);
void		ft_usleep(int ms);

#endif

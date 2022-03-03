/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_monitor_process.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:00:45 by jcarrete          #+#    #+#             */
/*   Updated: 2022/03/01 16:41:56 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	monitor_status(t_monitor *monitor, int i, int full)
{
	while (monitor->death == FALSE && full != monitor->args->nb_philos)
	{
		waitpid(monitor->pid[i], &(monitor->exit_code[i]), WNOHANG);
		if (monitor->exit_code[i] > 0)
		{
			monitor->death = TRUE;
			kill_processes();
			return (RET_ERROR);
		}
		else if (monitor->exit_code[i] == EXIT_SUCCESS)
			full++;
		i++;
		if (full != monitor->args->nb_philos && \
			i == monitor->args->nb_philos && monitor->death == FALSE)
		{
			i = 0;
			full = 0;
		}
		if (monitor->death == TRUE)
			return (RET_ERROR);
	}
	return (RET_SUCCESS);
}

static int	one_philo(t_monitor *monitor)
{	
	philo_print_status(ft_gettime() - monitor->args->start_time, \
		1, MSG_FORK, SIZE_FORK);
	ft_usleep(monitor->args->time_to_die);
	philo_print_status(ft_gettime() - monitor->args->start_time, \
		1, MSG_DIE, SIZE_DIE);
	return (RET_ERROR);
}

int	create_monitor_process(t_monitor *monitor)
{
	pid_t	child_pid;

	child_pid = 0;
	if (monitor->args->nb_philos == 1)
		return (one_philo(monitor));
	monitor->args->start_time = ft_gettime();
	while (monitor->nb_processes < monitor->args->nb_philos)
	{
		child_pid = fork();
		if (child_pid < 0)
		{
			kill_processes();
			return (handle_error(FREE_PROG, ERROR_CHILD));
		}
		if (child_pid == 0)
			philo_cycle(&monitor->philo[monitor->nb_processes]);
		monitor->pid[monitor->nb_processes] = child_pid;
		monitor->nb_processes++;
	}
	if (monitor_status(monitor, 0, 0) == RET_ERROR)
		return (RET_ERROR);
	return (RET_SUCCESS);
}

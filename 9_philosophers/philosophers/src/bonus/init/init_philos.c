/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:30:27 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/26 21:53:00 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	add_new_philo(t_monitor *monitor, int i)
{
	monitor->philo[i].args = monitor->args;
	monitor->philo[i].id = i + 1;
	monitor->philo[i].last_eat_time = monitor->args->start_time;
	monitor->philo[i].eat_count = 0;
	monitor->exit_code[i] = RET_ERROR;
}

static int	prepare_semaphores(t_monitor *monitor)
{
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_DEATH);
	monitor->forks = sem_open(SEM_FORK, O_CREAT, S_IRWXU, \
		monitor->args->nb_philos);
	monitor->print_status = sem_open(SEM_PRINT, O_CREAT, S_IRWXU, 1);
	monitor->death_status = sem_open(SEM_DEATH, O_CREAT, S_IRWXU, 1);
	if (monitor->forks == SEM_FAILED \
		|| monitor->print_status == SEM_FAILED \
		|| monitor->death_status == SEM_FAILED)
		return (RET_ERROR);
	return (RET_SUCCESS);
}

static int	alloc_monitor(t_monitor **monitor)
{
	int	error;

	error = RET_SUCCESS;
	(*monitor)->philo = (t_philo *)ft_memalloc(sizeof(t_philo) * \
		(*monitor)->args->nb_philos, &error);
	(*monitor)->garbage = add_to_gcollector((*monitor)->philo, &error);
	(*monitor)->pid = ft_memalloc(sizeof(pid_t) * \
		(*monitor)->args->nb_philos, &error);
	(*monitor)->garbage = add_to_gcollector((*monitor)->forks, &error);
	(*monitor)->exit_code = ft_memalloc(sizeof(int) * \
		(*monitor)->args->nb_philos, &error);
	(*monitor)->garbage = add_to_gcollector((*monitor)->exit_code, &error);
	if (error == RET_ERROR)
		return (RET_ERROR);
	return (RET_SUCCESS);
}

int	init_philos(t_philo **philo)
{
	t_monitor	*monitor;
	int			i;

	monitor = ft_getmonitor(NULL);
	monitor->args->start_time = ft_gettime();
	i = 0;
	if (alloc_monitor(&monitor) == RET_ERROR)
		return (handle_error(FREE_PROG, ERROR_MEM));
	if (prepare_semaphores(monitor) == RET_ERROR)
		return (handle_error(FREE_PROG, ERROR_OPEN_SEM));
	while (i < monitor->args->nb_philos)
	{
		add_new_philo(monitor, i);
		i++;
	}
	(*philo) = monitor->philo;
	return (RET_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:30:27 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/16 23:50:28 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	add_new_philo(t_monitor *monitor, int i)
{
	monitor->philo[i].args = monitor->args;
	monitor->philo[i].id = i + 1;
	monitor->philo[i].last_eat_time = monitor->args->start_time;
	monitor->philo[i].eat_count = 0;
	monitor->philo[i].thread = 0;
	if (i % 2)
	{
		if (i == monitor->args->nb_philos - 1)
			monitor->philo[i].left_fork = 0;
		else
			monitor->philo[i].left_fork = i + 1;
		monitor->philo[i].right_fork = i;
	}
	else
	{
		if (i == monitor->args->nb_philos - 1)
			monitor->philo[i].right_fork = 0;
		else
			monitor->philo[i].right_fork = i + 1;
		monitor->philo[i].left_fork = i;
	}
	pthread_mutex_init(&monitor->philo[i].philo_mutex, NULL);
}

static int	init_monitor_mutex(t_monitor **monitor)
{
	int	error;
	int	i;

	error = RET_SUCCESS;
	(*monitor)->philo = (t_philo *)ft_memalloc(sizeof(t_philo) * \
		(*monitor)->args->nb_philos, &error);
	(*monitor)->garbage = add_to_gcollector((*monitor)->philo, &error);
	(*monitor)->forks = ft_memalloc(sizeof(pthread_mutex_t) * \
		(*monitor)->args->nb_philos, &error);
	(*monitor)->garbage = add_to_gcollector((*monitor)->forks, &error);
	if (error == RET_ERROR)
		return (RET_ERROR);
	i = 0;
	while (i < (*monitor)->args->nb_philos)
	{
		pthread_mutex_init(&(*monitor)->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&((*monitor)->print_status), NULL);
	pthread_mutex_init(&((*monitor)->death_status), NULL);
	return (RET_SUCCESS);
}

int	init_philos(t_philo **philo)
{
	t_monitor	*monitor;
	int			i;

	monitor = ft_getmonitor(NULL);
	monitor->args->start_time = ft_gettime();
	i = 0;
	if (init_monitor_mutex(&monitor) == RET_ERROR)
		return (handle_error(FREE_PROG, ERROR_MEM));
	while (i < monitor->args->nb_philos)
	{
		add_new_philo(monitor, i);
		i++;
	}
	(*philo) = monitor->philo;
	return (RET_SUCCESS);
}

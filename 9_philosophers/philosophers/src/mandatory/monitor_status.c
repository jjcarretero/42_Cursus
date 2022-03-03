/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_status.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:09:03 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/16 23:49:13 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_if_starve(t_monitor *monitor, int i)
{
	pthread_mutex_lock(&monitor->philo[i].philo_mutex);
	pthread_mutex_lock(&monitor->death_status);
	if ((ft_gettime() - monitor->philo[i].last_eat_time > \
		monitor->args->time_to_die) && monitor->death == FALSE)
	{
		pthread_mutex_unlock(&monitor->philo[i].philo_mutex);
		monitor->death = TRUE;
		pthread_mutex_unlock(&monitor->death_status);
		philo_print_status(ft_gettime() - monitor->args->start_time, \
			i + 1, MSG_DIE, SIZE_DIE);
		return (RET_ERROR);
	}
	pthread_mutex_unlock(&monitor->philo[i].philo_mutex);
	pthread_mutex_unlock(&monitor->death_status);
	return (RET_SUCCESS);
}

static int	check_if_full(t_monitor *monitor, int *i, int *full)
{
	if (monitor->death == FALSE && \
		monitor->args->n_times_to_eat != RET_ERROR && \
		*full < monitor->args->nb_philos)
	{
		pthread_mutex_lock(&monitor->philo[*i].philo_mutex);
		if (monitor->philo[*i].eat_count == monitor->args->n_times_to_eat)
			(*full)++;
		pthread_mutex_unlock(&monitor->philo[*i].philo_mutex);
	}
	(*i)++;
	if (*full != monitor->args->nb_philos && \
		*i == monitor->args->nb_philos)
	{
		*i = 0;
		*full = 0;
	}
	if (*full == monitor->args->nb_philos)
		return (RET_ERROR);
	return (RET_SUCCESS);
}

void	monitor_status(t_monitor *monitor)
{
	int		status;
	int		full;
	int		i;

	i = 0;
	full = 0;
	status = TRUE;
	while (status)
	{
		if (check_if_starve(monitor, i) == RET_ERROR)
			return ;
		if (check_if_full(monitor, &i, &full) == RET_ERROR)
			return ;
	}
}

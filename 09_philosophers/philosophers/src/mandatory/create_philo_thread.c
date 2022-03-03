/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_philo_thread.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 20:20:04 by jcarrete          #+#    #+#             */
/*   Updated: 2022/03/01 19:42:23 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	create_philo_thread(t_monitor *monitor, int nb)
{
	while (nb < monitor->args->nb_philos)
	{
		if (pthread_create(&monitor->philo[nb].thread, NULL, \
			philo_cycle, &monitor->philo[nb]) != RET_SUCCESS)
		{
			pthread_mutex_lock(&monitor->death_status);
			monitor->death = TRUE;
			pthread_mutex_unlock(&monitor->death_status);
			join_philo_threads(monitor, nb);
		}
		nb += 2;
	}
}

static int	create_philo(void *vars)
{
	t_monitor	*monitor;

	monitor = vars;
	monitor->args->start_time = ft_gettime();
	create_philo_thread(monitor, NB_EVEN);
	usleep(10);
	create_philo_thread(monitor, NB_ODD);
	monitor_status(monitor);
	join_philo_threads(monitor, monitor->args->nb_philos);
	return (RET_SUCCESS);
}

int	create_monitor_thread(t_monitor *monitor)
{
	int		i;
	t_philo	*curr;

	i = 0;
	curr = monitor->philo;
	if (monitor->args->nb_philos == 1)
	{
		philo_print_status(ft_gettime() - monitor->args->start_time, \
			1, MSG_FORK, SIZE_FORK);
		ft_usleep(monitor->args->time_to_die);
		philo_print_status(ft_gettime() - monitor->args->start_time, \
			1, MSG_DIE, SIZE_DIE);
		return (handle_error(FREE_PROG, ERROR_NONE));
	}
	pthread_create(&monitor->thread, NULL, \
		(void *)&create_philo, (void *)monitor);
	return (RET_SUCCESS);
}

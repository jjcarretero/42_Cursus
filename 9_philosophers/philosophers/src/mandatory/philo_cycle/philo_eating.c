/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:47:30 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/21 22:42:52 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_eating(t_monitor *monitor, t_philo **philo)
{
	long	curr_time;
	long	start;

	(*philo)->state = STATE_EATING;
	pthread_mutex_lock(&monitor->print_status);
	start = (*philo)->args->start_time;
	curr_time = ft_gettime();
	philo_print_status(curr_time - start, (*philo)->id, MSG_EAT, SIZE_EAT);
	pthread_mutex_unlock(&monitor->print_status);
	pthread_mutex_lock(&(*philo)->philo_mutex);
	curr_time = ft_gettime();
	(*philo)->last_eat_time = curr_time;
	pthread_mutex_unlock(&(*philo)->philo_mutex);
	ft_usleep((*philo)->args->time_to_eat);
	philo_drop_forks(monitor, philo);
	if ((*philo)->args->n_times_to_eat != RET_ERROR)
		(*philo)->eat_count += 1;
}

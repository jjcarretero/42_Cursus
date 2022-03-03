/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:09:10 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/21 22:42:25 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_drop_forks(t_monitor *monitor, t_philo **philo)
{
	pthread_mutex_unlock(&(monitor->forks[(*philo)->left_fork]));
	pthread_mutex_unlock(&(monitor->forks[(*philo)->right_fork]));
}

void	philo_take_forks(t_monitor *monitor, t_philo **philo)
{
	long		curr_time;
	long		start;

	(*philo)->state = STATE_FORK;
	start = (*philo)->args->start_time;
	pthread_mutex_lock(&(monitor->forks[(*philo)->left_fork]));
	pthread_mutex_lock(&monitor->print_status);
	curr_time = ft_gettime();
	philo_print_status(curr_time - start, (*philo)->id, MSG_FORK, SIZE_FORK);
	pthread_mutex_unlock(&monitor->print_status);
	if ((*philo)->state != STATE_FORK)
		return ;
	pthread_mutex_lock(&(monitor->forks[(*philo)->right_fork]));
	pthread_mutex_lock(&monitor->print_status);
	curr_time = ft_gettime();
	philo_print_status(curr_time - start, (*philo)->id, MSG_FORK, SIZE_FORK);
	pthread_mutex_unlock(&monitor->print_status);
}

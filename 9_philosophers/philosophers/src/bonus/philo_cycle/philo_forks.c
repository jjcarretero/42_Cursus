/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_forks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:09:10 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/26 17:55:42 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_drop_forks(t_monitor *monitor)
{
	sem_post(monitor->forks);
	sem_post(monitor->forks);
}

void	philo_take_forks(t_monitor *monitor, t_philo **philo)
{
	long		curr_time;
	long		start;

	(*philo)->state = STATE_FORK;
	start = (*philo)->args->start_time;
	sem_wait(monitor->death_status);
	sem_wait(monitor->forks);
	curr_time = ft_gettime();
	philo_print_status(curr_time - start, (*philo)->id, MSG_FORK, SIZE_FORK);
	if ((*philo)->state != STATE_FORK)
	{
		sem_post(monitor->forks);
		sem_post(monitor->death_status);
		return ;
	}
	sem_wait(monitor->forks);
	sem_post(monitor->death_status);
	curr_time = ft_gettime();
	philo_print_status(curr_time - start, (*philo)->id, MSG_FORK, SIZE_FORK);
	if ((*philo)->state != STATE_FORK)
	{
		sem_post(monitor->forks);
		sem_post(monitor->death_status);
	}
}

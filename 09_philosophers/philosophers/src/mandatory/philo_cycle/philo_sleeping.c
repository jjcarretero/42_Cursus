/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:04:54 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/16 22:19:08 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_sleeping(t_monitor *monitor, t_philo **philo)
{
	long	curr_time;
	long	start;

	(*philo)->state = STATE_SLEEPING;
	pthread_mutex_lock(&monitor->print_status);
	start = (*philo)->args->start_time;
	curr_time = ft_gettime();
	philo_print_status(curr_time - start, (*philo)->id, MSG_SLEEP, SIZE_SLEEP);
	pthread_mutex_unlock(&monitor->print_status);
	ft_usleep(monitor->args->time_to_sleep);
}

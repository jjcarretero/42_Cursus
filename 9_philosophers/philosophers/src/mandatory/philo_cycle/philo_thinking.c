/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:54:47 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/16 22:19:52 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	philo_thinking(t_monitor *monitor, t_philo **philo)
{
	long	curr_time;
	long	start;

	(*philo)->state = STATE_THINKING;
	pthread_mutex_lock(&monitor->print_status);
	if ((*philo)->id)
	{
		start = (*philo)->args->start_time;
		curr_time = ft_gettime();
		philo_print_status(curr_time - start, \
						(*philo)->id, MSG_THINK, SIZE_THINK);
	}
	pthread_mutex_unlock(&monitor->print_status);
}

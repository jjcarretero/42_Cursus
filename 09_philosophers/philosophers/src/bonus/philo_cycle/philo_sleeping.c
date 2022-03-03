/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_sleeping.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 22:04:54 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/26 18:34:35 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_sleeping(t_monitor *monitor, t_philo **philo)
{
	long	curr_time;
	long	start;

	(*philo)->state = STATE_SLEEPING;
	start = (*philo)->args->start_time;
	curr_time = ft_gettime();
	philo_print_status(curr_time - start, (*philo)->id, MSG_SLEEP, SIZE_SLEEP);
	ft_usleep(monitor->args->time_to_sleep);
}

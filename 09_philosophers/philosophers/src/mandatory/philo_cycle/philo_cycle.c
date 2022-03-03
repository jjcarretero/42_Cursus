/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:48:54 by jcarrete          #+#    #+#             */
/*   Updated: 2022/03/01 20:15:11 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	loop_cycle(t_monitor *monitor, t_philo **philo)
{
	while ((*philo)->state != STATE_DEAD)
	{
		if ((*philo)->state == STATE_THINKING)
			philo_take_forks(monitor, philo);
		if ((*philo)->state == STATE_FORK)
			philo_eating(monitor, philo);
		if ((*philo)->state == STATE_EATING)
			philo_sleeping(monitor, philo);
		if ((ft_gettime() - (*philo)->last_eat_time) < \
				monitor->args->time_to_die * 75 / 100)
			ft_usleep(1);
		if (monitor->args->n_times_to_eat != RET_ERROR && \
			(*philo)->eat_count == monitor->args->n_times_to_eat)
			break ;
		if ((*philo)->state == STATE_SLEEPING)
			philo_thinking(monitor, philo);
	}
}

void	*philo_cycle(void *vars)
{
	t_philo		*curr;
	t_monitor	*monitor;

	monitor = ft_getmonitor(NULL);
	curr = vars;
	curr->last_eat_time = ft_gettime();
	philo_thinking(monitor, &curr);
	loop_cycle(monitor, &curr);
	return (NULL);
}

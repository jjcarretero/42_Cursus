/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_cycle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:48:54 by jcarrete          #+#    #+#             */
/*   Updated: 2022/03/01 17:08:56 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static int	check_exit_code(t_monitor *monitor, t_philo *philo)
{
	int	ret;

	ret = RET_SUCCESS;
	if (philo->state == STATE_DEAD)
	{
		sem_wait(monitor->print_status);
		philo_print_status(ft_gettime() - monitor->args->start_time, \
			philo->id, MSG_DIE, SIZE_DIE);
		ret = RET_ERROR;
	}
	clean_gcollector();
	return (ret);
}

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
		if (monitor->args->n_times_to_eat != RET_ERROR && \
			(*philo)->eat_count == monitor->args->n_times_to_eat)
			break ;
		if ((*philo)->state == STATE_SLEEPING)
			philo_thinking(philo);
	}
}

void	*philo_cycle(t_philo *curr)
{
	t_monitor	*monitor;

	monitor = ft_getmonitor(NULL);
	curr->last_eat_time = ft_gettime() - monitor->args->start_time;
	philo_thinking(&curr);
	loop_cycle(monitor, &curr);
	exit (check_exit_code(monitor, curr));
}

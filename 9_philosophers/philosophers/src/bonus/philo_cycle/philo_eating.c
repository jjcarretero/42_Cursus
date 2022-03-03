/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_eating.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 21:47:30 by jcarrete          #+#    #+#             */
/*   Updated: 2022/03/01 16:54:40 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_eating(t_monitor *monitor, t_philo **philo)
{
	long	curr_time;
	long	start;

	(*philo)->state = STATE_EATING;
	start = (*philo)->args->start_time;
	curr_time = ft_gettime();
	philo_print_status(curr_time - start, (*philo)->id, MSG_EAT, SIZE_EAT);
	if ((*philo)->state != STATE_EATING)
	{
		philo_drop_forks(monitor);
		return ;
	}
	curr_time = ft_gettime();
	(*philo)->last_eat_time = curr_time - start;
	ft_usleep((*philo)->args->time_to_eat);
	philo_drop_forks(monitor);
	if ((*philo)->args->n_times_to_eat != RET_ERROR)
		(*philo)->eat_count += 1;
}

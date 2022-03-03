/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_thinking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:54:47 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/26 23:09:44 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	philo_thinking(t_philo **philo)
{
	long	curr_time;
	long	start;

	(*philo)->state = STATE_THINKING;
	start = (*philo)->args->start_time;
	curr_time = ft_gettime();
	philo_print_status(curr_time - start, \
				(*philo)->id, MSG_THINK, SIZE_THINK);
}

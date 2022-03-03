/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 13:38:47 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/14 00:53:55 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	join_philo_threads(t_monitor *monitor, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		pthread_join(monitor->philo[i].thread, NULL);
		i++;
	}
}

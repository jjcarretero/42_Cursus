/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:27:00 by jcarrete          #+#    #+#             */
/*   Updated: 2022/03/01 19:40:23 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_monitor	*monitor;
	int			retval;

	if (init_monitor(&monitor) == RET_ERROR || \
		check_args(argc, argv) == RET_ERROR || \
		init_philos(&monitor->philo) == RET_ERROR || \
		create_monitor_thread(monitor) == RET_ERROR)
	{
		return (EXIT_FAILURE);
	}
	pthread_join(monitor->thread, (void **)&retval);
	clean_gcollector();
	return (EXIT_SUCCESS);
}

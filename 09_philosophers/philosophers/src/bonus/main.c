/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:36:00 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/26 23:18:03 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	main(int argc, char **argv)
{
	t_monitor	*monitor;
	t_philo		*philo;

	if (init_monitor(&monitor) == RET_ERROR || \
		check_args(argc, argv) == RET_ERROR || \
		init_philos(&philo) == RET_ERROR || \
		create_monitor_process(monitor) == RET_ERROR)
	{
		clean_gcollector();
		return (EXIT_FAILURE);
	}
	kill_processes();
	clean_gcollector();
	return (EXIT_SUCCESS);
}

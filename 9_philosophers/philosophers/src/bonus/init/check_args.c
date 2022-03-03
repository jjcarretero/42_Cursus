/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 22:54:28 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/26 11:55:38 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	check_args(int argc, char **argv)
{
	t_monitor	*monitor;
	t_args		*args;

	monitor = ft_getmonitor(NULL);
	args = monitor->args;
	if (argc < 5 || argc > 6)
		return (handle_error(FREE_PROG, ERROR_ARGSNUM));
	args->nb_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	if (argc == 6)
		args->n_times_to_eat = ft_atoi(argv[5]);
	if (args->nb_philos == RET_ERROR || args->time_to_die == RET_ERROR || \
	args->time_to_eat == RET_ERROR || args->time_to_sleep == RET_ERROR || \
	(argc == 6 && args->n_times_to_eat == RET_ERROR))
		return (handle_error(FREE_PROG, ERROR_ARGVALUE));
	return (RET_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:30:27 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/26 17:19:03 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

int	init_monitor(t_monitor **monitor)
{
	int	error;

	error = RET_SUCCESS;
	*monitor = ft_memalloc(sizeof(t_monitor), &error);
	(*monitor)->args = ft_memalloc(sizeof(t_args), &error);
	if (error == RET_ERROR)
		return (RET_ERROR);
	ft_getmonitor(*monitor);
	(*monitor)->garbage = add_to_gcollector((*monitor)->args, &error);
	if (error == RET_ERROR)
		return (RET_ERROR);
	(*monitor)->philo = NULL;
	(*monitor)->forks = NULL;
	(*monitor)->death_status = NULL;
	(*monitor)->print_status = NULL;
	(*monitor)->death = FALSE;
	(*monitor)->args->nb_philos = RET_ERROR;
	(*monitor)->args->time_to_die = RET_ERROR;
	(*monitor)->args->time_to_eat = RET_ERROR;
	(*monitor)->args->time_to_sleep = RET_ERROR;
	(*monitor)->args->n_times_to_eat = RET_ERROR;
	return (RET_SUCCESS);
}

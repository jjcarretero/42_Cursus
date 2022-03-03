/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_monitor.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:30:27 by jcarrete          #+#    #+#             */
/*   Updated: 2022/03/01 19:41:07 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	init_monitor(t_monitor **monitor)
{
	int	error;

	error = RET_SUCCESS;
	*monitor = ft_memalloc(sizeof(t_monitor), &error);
	(*monitor)->args = ft_memalloc(sizeof(t_args), &error);
	if (error == RET_ERROR)
		return (handle_error(FREE_PROG, ERROR_MEM));
	ft_getmonitor(*monitor);
	(*monitor)->garbage = NULL;
	(*monitor)->garbage = add_to_gcollector((*monitor)->args, &error);
	if (error == RET_ERROR)
		return (handle_error(FREE_PROG, ERROR_MEM));
	(*monitor)->philo = NULL;
	(*monitor)->death = FALSE;
	(*monitor)->args->nb_philos = RET_ERROR;
	(*monitor)->args->time_to_die = RET_ERROR;
	(*monitor)->args->time_to_eat = RET_ERROR;
	(*monitor)->args->time_to_sleep = RET_ERROR;
	(*monitor)->args->n_times_to_eat = RET_ERROR;
	return (RET_SUCCESS);
}

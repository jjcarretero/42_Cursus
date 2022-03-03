/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:48:36 by jcarrete          #+#    #+#             */
/*   Updated: 2022/03/01 19:30:57 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static void	destroy_mutex(t_monitor *monitor)
{
	int	i;

	if (monitor->forks)
	{
		i = 0;
		while (i < monitor->args->nb_philos)
		{
			pthread_mutex_destroy(&monitor->forks[i++]);
		}
	}
	if (monitor->philo)
	{
		i = 0;
		while (i < monitor->args->nb_philos)
		{
			pthread_mutex_destroy(&monitor->philo[i++].philo_mutex);
		}
	}
	pthread_mutex_destroy(&monitor->death_status);
	pthread_mutex_destroy(&monitor->print_status);
}

void	clean_gcollector(void)
{
	t_monitor	*monitor;
	t_list		*elem;
	t_list		*tmp;

	monitor = ft_getmonitor(NULL);
	if (monitor != NULL)
	{
		destroy_mutex(monitor);
		elem = monitor->garbage;
		while (elem)
		{
			tmp = elem->next;
			elem->ptr = ft_memfree(elem->ptr, NULL);
			elem = ft_memfree(elem, tmp);
		}
		monitor = ft_memfree(monitor, NULL);
	}
}

t_list	*add_to_gcollector(void *ptr, int *error)
{
	t_list		*new_element;
	t_monitor	*monitor;

	monitor = ft_getmonitor(NULL);
	new_element = ft_memalloc(sizeof(t_list), error);
	if (*error == RET_ERROR)
		return (NULL);
	new_element->ptr = ptr;
	new_element->next = monitor->garbage;
	return (new_element);
}

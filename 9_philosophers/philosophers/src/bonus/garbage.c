/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 00:26:44 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/26 17:20:37 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

void	kill_processes(void)
{
	t_monitor	*monitor;
	int			i;

	monitor = ft_getmonitor(NULL);
	i = monitor->nb_processes;
	if (i == monitor->args->nb_philos)
		i--;
	while (i >= 0)
	{
		kill(monitor->pid[i], SIGTERM);
		i--;
	}
}

static void	close_semaphores(t_monitor *monitor)
{
	if (monitor->forks)
		sem_close(monitor->forks);
	if (monitor->death_status)
		sem_close(monitor->death_status);
	if (monitor->print_status)
		sem_close(monitor->print_status);
	sem_unlink(SEM_FORK);
	sem_unlink(SEM_PRINT);
	sem_unlink(SEM_DEATH);
}

void	clean_gcollector(void)
{
	t_monitor	*monitor;
	t_list		*elem;
	t_list		*tmp;

	monitor = ft_getmonitor(NULL);
	close_semaphores(monitor);
	elem = monitor->garbage;
	while (elem)
	{
		tmp = elem->next;
		elem->ptr = ft_memfree(elem->ptr, NULL);
		elem = ft_memfree(elem, NULL);
		elem = tmp;
	}
	monitor = ft_memfree(monitor, NULL);
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

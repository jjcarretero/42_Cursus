/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:02:32 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/16 22:22:34 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

static int	check_death_flag(unsigned int id)
{
	t_monitor	*monitor;

	monitor = ft_getmonitor(NULL);
	pthread_mutex_lock(&monitor->death_status);
	if (monitor->death == TRUE)
	{
		monitor->philo[id - 1].state = STATE_DEAD;
		pthread_mutex_unlock(&monitor->death_status);
		return (RET_ERROR);
	}
	return (RET_SUCCESS);
}

static void	print_status(long time, unsigned int id, char *state, int size)
{
	int		len;
	int		i;
	char	buffer[BUF_SIZE];

	len = 0;
	len = ft_ltoa(&(buffer[0]), time, len);
	i = 0;
	while (i < SIZE_MID)
		buffer[len++] = MSG_MID[i++];
	len = ft_ltoa(&(buffer[0]), id, len);
	i = 0;
	while (i < size)
		buffer[len++] = state[i++];
	write(STDOUT_FILENO, buffer, len);
}

int	philo_print_status(long time, unsigned int id, char *state, int size)
{
	if (size == SIZE_DIE)
		print_status(time, id, state, size);
	else
	{
		if (check_death_flag(id) == RET_ERROR)
			return (RET_ERROR);
		print_status(time, id, state, size);
		pthread_mutex_unlock(&(ft_getmonitor(NULL))->death_status);
	}
	return (RET_SUCCESS);
}

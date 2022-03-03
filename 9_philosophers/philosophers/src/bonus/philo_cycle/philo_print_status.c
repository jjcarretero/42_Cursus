/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_print_status.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:02:32 by jcarrete          #+#    #+#             */
/*   Updated: 2022/03/01 17:33:03 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	print_values(long time, unsigned int id, char *state, int size)
{
	int			len;
	char		buffer[BUF_SIZE];
	t_monitor	*monitor;
	int			i;

	monitor = ft_getmonitor(NULL);
	len = 0;
	len = ft_ltoa(&(buffer[0]), time, len);
	i = 0;
	while (i < SIZE_MID)
		buffer[len++] = MSG_MID[i++];
	len = ft_ltoa(&(buffer[0]), id, len);
	i = 0;
	while (i < size)
		buffer[len++] = state[i++];
	sem_wait(monitor->print_status);
	write(STDOUT_FILENO, buffer, len);
	sem_post(monitor->print_status);
}

static void	print_dead(long time, unsigned int id, char *state, int size)
{
	int			len;
	char		buffer[BUF_SIZE];
	t_monitor	*monitor;
	int			i;

	monitor = ft_getmonitor(NULL);
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
	t_monitor	*monitor;

	monitor = ft_getmonitor(NULL);
	if (size == SIZE_DIE)
	{
		print_dead(time, id, state, size);
		return (RET_ERROR);
	}
	if ((time - monitor->philo[id - 1].last_eat_time) \
		> monitor->args->time_to_die)
	{
		monitor->philo[id - 1].state = STATE_DEAD;
		return (RET_ERROR);
	}
	print_values(time, id, state, size);
	return (RET_SUCCESS);
}

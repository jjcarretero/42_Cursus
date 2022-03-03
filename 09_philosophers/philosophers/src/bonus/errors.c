/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 20:42:52 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/26 17:04:09 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers_bonus.h"

static void	print_error(int error)
{
	if (error == ERROR_ARGSNUM)
	{
		ft_putstr_fd(MSG_ARGS_NUM, STDERR_FILENO);
		ft_putstr_fd(MSG_USAGE, STDERR_FILENO);
	}
	if (error == ERROR_ARGVALUE)
		ft_putstr_fd(MSG_ARGS_VAL, STDERR_FILENO);
	if (error == ERROR_MEM)
		ft_putstr_fd(MSG_MEMORY, STDERR_FILENO);
	if (error == ERROR_PHILO)
		ft_putstr_fd(MSG_ADD_PHILO, STDERR_FILENO);
	if (error == ERROR_OPEN_SEM)
		ft_putstr_fd(MSG_OPEN_SEM, STDERR_FILENO);
	if (error == ERROR_CHILD)
		ft_putstr_fd(MSG_CHILD, STDERR_FILENO);
}

int	handle_error(int free_state, int error)
{
	if (error != ERROR_NONE)
	{
		ft_putstr_fd(CB_RED, STDERR_FILENO);
		ft_putstr_fd("PHILOSOPHERS ERROR:\n", STDERR_FILENO);
		ft_putstr_fd(C_RED, STDERR_FILENO);
		print_error(error);
		ft_putstr_fd(C_WHITE, STDERR_FILENO);
		ft_putchar_fd('\n', STDERR_FILENO);
	}
	if (free_state == FREE_PROG)
		clean_gcollector();
	return (RET_ERROR);
}

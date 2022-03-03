/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bash_colors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:34:38 by jcarrete          #+#    #+#             */
/*   Updated: 2022/02/13 22:02:12 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASH_COLORS_H
# define BASH_COLORS_H

/*
** RESET ---------------------------------
*/

# define C_OFF "\033[0m"

/*
** COLORS ---------------------------------
*/

# define C_BLACK "\033[0;30m"
# define C_BLUE "\033[0;34m"
# define C_CYAN "\033[0;36m"
# define C_GREEN "\033[0;32m"
# define C_PURPLE "\033[0;35m"
# define C_RED "\033[0;31m"
# define C_WHITE "\033[0;37m"
# define C_YELLOW "\033[0;33m"

# define C_DARKGREY "\033[0;90m"
# define C_LIGHTBLUE "\033[0;94m"
# define C_LIGHTCYAN "\033[0;96m"
# define C_LIGHTGREEN "\033[0;92m"
# define C_LIGHTPURPLE "\033[0;95m"
# define C_LIGHTRED "\033[0;91m"
# define C_LIGHTYELLOW "\033[0;93m"

/*
** BOLD -----------------------------------
*/

# define CB_BLACK "\033[1;30m"
# define CB_BLUE "\033[1;34m"
# define CB_CYAN "\033[1;36m"
# define CB_GREEN "\033[1;32m"
# define CB_PURPLE "\033[1;35m"
# define CB_RED "\033[1;31m"
# define CB_WHITE "\033[1;37m"
# define CB_YELLOW "\033[1;33m"

/*
** UNDERLINE ------------------------------
*/

# define CU_BLACK "\033[4;30m"
# define CU_BLUE "\033[4;34m"
# define CU_CYAN "\033[4;36m"
# define CU_GREEN "\033[4;32m"
# define CU_PURPLE "\033[4;35m"
# define CU_RED "\033[4;31m"
# define CU_WHITE "\033[4;37m"
# define CU_YELLOW "\033[4;33m"

/*
** BACKGROUND ------------------------------
*/

# define CBACK_BLACK "\033[40m"
# define CBACK_BLUE "\033[44m"
# define CBACK_CYAN "\033[46m"
# define CBACKC_GREEN "\033[42m"
# define CBACKC_PURPLE "\033[45m"
# define CBACKC_RED "\033[41m"
# define CBACKC_WHITE "\033[47m"
# define CBACKC_YELLOW "\033[43m"

#endif

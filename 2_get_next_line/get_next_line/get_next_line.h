/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 17:58:19 by jcarrete          #+#    #+#             */
/*   Updated: 2020/07/30 17:58:19 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		get_next_line(int fd, char **line);
char	*ft_strdup(char *s1);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlcat(char *dest, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *s);
#endif

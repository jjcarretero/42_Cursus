/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:05:24 by jcarrete          #+#    #+#             */
/*   Updated: 2020/09/27 17:20:32 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

/*
** MACROS
*/

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

/*
** Structs
*/

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

/*
**Libft
*/

int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t count, size_t size);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
char				*ft_itoa(int n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *b, int c, size_t len);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr_fd(char *s, int fd);
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *s, int c);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t				ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t				ft_strlen(const char *s);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack,\
const char *needle, size_t len);
char				*ft_strrchr(const char *s, int c);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_tolower(int c);
int					ft_toupper(int c);

/*
**Bonus
*/

void				ft_lstadd_back(t_list **lst, t_list *newlst);
void				ft_lstadd_front(t_list **lst, t_list *newlst);
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),\
void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

/*
**Added
*/

int					ft_abs(int a);
long double			ft_absf(long double a);
int					ft_atoi_base(char *str, int base);
int					ft_digits_long(int nb);
int					ft_find_next_prime(int nb);
double				ft_float_power(int nb, int base);
char				*ft_ftoa(long double ld);
int					ft_get_next_line(int fd, char **line);
int					ft_is_prime(int nb);
char				*ft_itoa_base(int n, int base);
long long			ft_llpow(long long x, unsigned long long y);
char				*ft_lltoa(long long n);
char				*ft_ltoa(long n);
char				*ft_ltoa_base(long n, int base);
int					ft_max(int a, int b);
void				*ft_memalloc(size_t size);
void				*ft_memfree(void *all, void *npo);
int					ft_min(int a, int b);
void				ft_print_memory(void *addr, size_t len);
int					ft_pow(int x, unsigned int y);
int					ft_sqrt(int nb);
char				*ft_str_tolower(char *str);
char				*ft_str_toupper(char *str);
char				*ft_strappend_nchr(char *str, int c, int nb);
char				*ft_strappstart_nchr(char *str, int c, int nb);
char				*ft_strcat(char *dest, char *src);
size_t				ft_strchr_count(const char *str, char c);
int					ft_strchr_pos(char *str, int c);
int					ft_strcmp(char *s1, char *s2);
char				*ft_strcpy(char *dest, char *src);
void				ft_strempt(char *s);
void				ft_strempt_endchar(char *str, char c);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strjoin_gnl(char *s1, char *s2);
char				*ft_strncat(char *dest, char *src, size_t nb);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strnew(size_t size);
char				*ft_strrev(const char *s);
size_t				ft_strspn(const char *str, const char *chars);
void				ft_swap(void *a, void *b, size_t len);
void				ft_swap_array_elem(void **array, int a, int b);
void				ft_swap_int(int *p, int *q);
char				*ft_uitoa(unsigned int n);
char				*ft_uitoa_base(unsigned int n, int base);
char				*ft_ulltoa(unsigned long long n);
char				*ft_ultoa(unsigned long n);
char				*ft_ultoa_base(unsigned long n, int base);
int					ft_wstrlen(wchar_t *wstr);
#endif

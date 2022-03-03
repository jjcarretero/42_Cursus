/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/30 16:05:24 by jcarrete          #+#    #+#             */
/*   Updated: 2022/01/30 00:36:40 by jcarrete         ###   ########.fr       */
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

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 32
# endif

# define FALSE 0
# define TRUE 1
# define ERROR -1
# define SUCCESS 0

/*
** Structs
*/

typedef int			(*t_compare)(const void *, const void *);

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_qsort
{
	char	*lo;
	char	*hi;
}					t_qsort;

typedef struct s_qsort_data
{
	char			*base_ptr;
	size_t			nmemb;
	size_t			size;
	t_compare		cmp;
}					t_qsort_data;

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
char				*ft_itoa(long long n);
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
char				*ft_strnstr(const char *haystack, \
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
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *), \
						void (*del)(void *));
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);

/*
**Added
*/

int					ft_abs(int a);
double				ft_absd(double a);
long double			ft_absld(long double a);
int					ft_str_arr_count(char **arr);
int					ft_atoi_base(char *str, int base);
long				ft_atol(const char *str);
int					ft_digits_long(int nb);
int					ft_find_next_prime(int nb);
double				ft_float_pwr(int nb, int base);
void				*ft_free_lst(t_list **lst, void (*del)(void *));
char				*ft_ftoa(long double ld);
int					ft_get_next_line(int fd, char **line);
void				ft_insertion_sort(t_qsort_data *data);
int					ft_is_number(char *str);
int					ft_is_prime(int nb);
int					ft_isspace(int c);
int					ft_iteris(char *str, int (*f)(int));
char				*ft_itoa_base(long long n, int base);
long long			ft_llpow(long long x, unsigned long long y);
char				*ft_ltoa_base(long n, int base);
int					ft_max(int a, int b);
void				*ft_memalloc(size_t size);
void				*ft_memfree(void *all, void *npo);
int					ft_min(int a, int b);
void				ft_print_memory(void *addr, size_t len, int fd);
int					ft_pow(int x, unsigned int y);
void				ft_qsort_array(void *const base, size_t nmemb, size_t size, \
						t_compare cmp);
char				*ft_qsort_min(char *a, char *b);
void				ft_qsort_pop(t_qsort **top, char *low, char *high);
void				ft_qsort_push(t_qsort **top, char *low, char *high);
void				ft_qsort_swap(char *a, char *b, size_t size);
char				**ft_split_free(char **tab);
int					ft_sqrt(int nb);
char				*ft_str_tolower(char *str);
char				*ft_str_toupper(char *str);
char				*ft_strappend_nchr(char *str, int c, int nb);
char				*ft_strappstart_nchr(char *str, int c, int nb);
char				*ft_strcat(char *dest, char *src);
size_t				ft_strchr_count(const char *str, char c);
int					ft_strchr_pos(char *str, int c);
int					ft_strcmp(char *s1, char *s2);
int					ft_strcount(char **array);
char				*ft_strcpy(char *dest, char *src);
void				ft_strempt(char *s);
void				ft_strempt_endchar(char *str, char c);
void				ft_striter(char *s, void (*f)(char *));
char				*ft_strjoin_gnl(char *s1, char *s2);
char				*ft_strncat(char *dest, char *src, size_t nb);
char				*ft_strncpy(char *dest, char *src, unsigned int n);
char				*ft_strnew(size_t size);
int					ft_strrchr_pos(char *str, int c);
char				*ft_strrev(const char *s);
int					ft_strrncmp(const char *str, const char *suffix, size_t n);
size_t				ft_strspn(const char *str, const char *chars);
char				*ft_strtok(char *str, const char *delim);
char				*ft_strtrim_start(char const *s1, char const *set);
void				ft_swap(void *a, void *b, size_t len);
void				ft_swap_array_elem(void **array, int a, int b);
void				ft_swap_int(int *p, int *q);
void				ft_swap_str(char **a, char **b);
char				*ft_utoa(size_t n);
char				*ft_utoa_base(size_t n, int base);
int					ft_wstrlen(wchar_t *wstr);
#endif

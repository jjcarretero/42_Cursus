
## LIBFT FUNCTIONS

**ft_atoi**

*int	ft_atoi(const char \*str)*

The ft_atoi() function parses the C-string str interpreting its content as an integral number, which is returned as a value of type int.

**ft_bzero**

*void	ft_bzero(void \*s, size_t n)*

The ft_bzero() function erases the data in the n bytes of the memory starting at the location pointed to by s, by writing zeros (bytes containing '\0') to that area.

**ft_calloc**

*void	\*ft_calloc(size_t count, size_t size)*

The ft_calloc() function allocates the requested memory and returns a pointer to it. The difference in malloc and calloc is that malloc does not set the memory to zero where as calloc sets allocated memory to zero.

**ft_isalnum**

*int	ft_isalnum(int c)*

The ft_isalnum() function returns a non-zero integer if an argument (character) passed to the function is an alphanumeric (alphabet and number) character.

**ft_isalpha**

*int	ft_isalpha(int c)*

The ft_isalpha() function checks whether a character is an alphabet or not (a to z and A-Z) or not.

**ft_isascii**

*int	ft_isascii(int c)*

The ft_isascii() function tests for an ASCII character (in the range 0 to 127)

**ft_isdigit**

*int	ft_isdigit(int c)*

The ft_isdigit() function checks whether a character is numeric character (0-9) or not.

**ft_isprint**

*int	ft_isprint(int c)*

The ft_isprint() function checks whether a character is a printable character or not.

**ft_itoa**

*char	\*ft_itoa(int n)*

The ft_itoa() function converts an integer value to a null-terminated string using the specified base and returns the string.

**ft_memccpy**

*void	\*ft_memccpy(void \*dst, const void \*src, int c, size_t n)*

The ft_memccpy() function operates as efficiently as possible on memory areas. It does not check for overflow of any receiving memory area. Specifically, memccpy() copies bytes from memory area s2 into s1, stopping after the first occurrence of c has been copied, or after n bytes have been copied, whichever comes first.

**ft_memchr**

*void	\*ft_memchr(const void \*s, int c, size_t n)*

The ft_memchr() function operates as efficiently as possible on memory areas. It does not check for overflow of any receiving memory area. Specifically, the memchr() function returns a pointer to the first occurrence of c (converted to an unsigned char) in the first n bytes (each interpreted as an unsigned char) of memory area s. If c does not occur, it returns a null pointer.

**ft_memcmp**

*int	ft_memcmp(const void \*s1, const void \*s2, size_t n)*

The ft_memcmp() function compares n bytes of two regions of memory, treating each byte as an unsigned character. It returns an integer less than, equal to, or greater than zero according to whether s1 is lexicographically less than, equal to, or greater than s2.

**ft_memcpy**

*void	\*ft_memcpy(void \*dst, const void \*src, size_t n)*

The ft_memcpy() function operates as efficiently as possible on memory areas. It does not check for overflow of any receiving memory area. Specifically, memcpy() copies n bytes from memory area s2 to s1. It returns s1.

**ft_memmove**

*void	\*ft_memmove(void \*dst, const void \*src, size_t len)*

The ft_memmove() function operates as efficiently as possible on memory areas. It does not check for overflow of any receiving memory area. Specifically, memmove() copies n bytes from memory areas s2 to s1. It returns s1. If s1 and s2 overlap, all bytes are copied in a preserving manner (unlike memcpy()).

**ft_memset**

*void	\*ft_memset(void \*b, int c, size_t len)*

The ft_memset() function operates as efficiently as possible on memory areas. It does not check for overflow of any receiving memory area. Specifically, memset() sets the first n bytes in memory area s to the value of c (converted to an unsigned char). It returns s.

**ft_putchar_fd**

*void	ft_putchar_fd(char c, int fd)*

The ft_putchar_fd() function outputs the character ’c’ to the given file descriptor.

**ft_putendl_fd**

*void	ft_putendl_fd(char \*s, int fd)*

The ft_putendl_fd() function outputs the string ’s’ to the given file descriptor, followed by a newline.

**ft_putnbr_fd**

*void	ft_putnbr_fd(int n, int fd)*

The ft_putnbr_fd() function outputs the integer ’n’ to the given file descriptor.

**ft_putstr_fd**

*void	ft_putstr_fd(char \*s, int fd)*

The ft_putstr_fd() function outputs the string ’s’ to the given file descriptor.

**ft_split**

*char	\*\*ft_split(char const \*s, char c)*

The ft_split() function allocates (with malloc) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must be ended by a NULL pointer.

**ft_strchr**

*char	\*ft_strchr(const char \*s, int c)*

The ft_strchr() function searches the occurrence of a specified character in the given string and returns the pointer to it.

**ft_strdup**

*char	\*ft_strdup(const char \*s1)*

The ft_strdup() function returns a pointer to a null-terminated byte string, which is a duplicate of the string pointed to by s. The memory obtained is done dynamically using malloc and hence it can be freed using free().

**ft_strjoin**

*char	\*ft_strjoin(char const \*s1, char const \*s2)*

The ft_strjoin() function allocates (with malloc) and returns a new string, which is the result of the concatenation of ’s1’ and ’s2’.

**ft_strlcat**

*size_t	ft_strlcat(char \*dst, const char \*src, size_t dstsize)*

The ft_strlcat() function appends the NUL-terminated string src to the end of dst. It will append at most size - strlen(dst) - 1 bytes, NUL-terminating the result.

**ft_strlcpy**

*size_t	ft_strlcpy(char \*dst, const char \*src, size_t dstsize)*

The ft_strlcpy() function copies up to size - 1 characters from the NUL-terminated string src to dst, NUL-terminating the result.

**ft_strlen**

*size_t	ft_strlen(const char \*s)*

The ft_strlen() function calculates the length of a given string.

**ft_strmapi**

*char	\*ft_strmapi(char const \*s, char (\*f)(unsigned int, char))*

The ft_strmapi() function applies the function ’f’ to each character of the string ’s’ to create a new string (with malloc) resulting from successive applications of ’f’.

**ft_strncmp**

*int	ft_strncmp(const char \*s1, const char \*s2, size_t n)*

The ft_strncmp() function returns a negative, zero, or positive integer depending on whether the first n characters of the object pointed to by s1 are less than, equal to, or greater than the first n characters of the object pointed to by s2, until ’\0’ is reached.

**ft_strnstr**

*char	\*ft_strnstr(const char \*haystack, const char \*needle, size_t len)*

The ft_strnstr() function locates the first occurrence of the null-terminated string s2 in the string s1, where not more than n characters are searched. Characters that appear after a ’\0’ character are not searched.

**ft_strrchr**

*char	\*ft_strrchr(const char \*s, int c)*

The ft_strrchr() function returns a pointer to the last occurrence of c. The null character terminating a string is considered to be part of the string.

**ft_strtrim**

*char	\*ft_strtrim(char const \*s1, char const \*set)*

The ft_strtrim() function allocates (with malloc) and returns a copy of ’s1’ with the characters specified in ’set’ removed from the beginning and the end of the string.

**ft_substr**

*char	\*ft_substr(char const \*s, unsigned int start, size_t len)*

The ft_substr() function allocates (with malloc) and returns a substring from the string ’s’. The substring begins at index ’start’ and is of maximum size ’len’.

**ft_tolower**

*int	ft_tolower(int c)*

The ft_tolower() function takes an uppercase alphabet and convert it to a lowercase character.

**ft_toupper**

*int	ft_toupper(int c)*

The ft_toupper() function converts a lowercase alphabet to an uppercase alphabet, if the argument passed is an lowercase alphabet.


## BONUS FUNCTIONS

**ft_lstadd_back**

*void	ft_lstadd_back(t_list \*\*lst, t_list \*new)*

The ft_lstadd_back() function adds the element ’new’ at the end of the list.

**ft_lstadd_front**

*void	ft_lstadd_front(t_list \*\*lst, t_list \*new)*

The ft_lstadd_front() function adds the element ’new’ at the beginning of the list.

**ft_lstclear**

*void	ft_lstclear(t_list \*\*lst, void (\*del)(void \*))*

The ft_lstclear() function deletes and frees the given element and every successor of that element, using the function ’del’ and free. Finally, the pointer to the list must be set to
NULL.

**ft_lstdelone**

*void	ft_lstdelone(t_list \*lst, void (\*del)(void \*))*

The ft_lstdelone() function takes as a parameter an element and frees the memory of the element’s content using the function ’del’ given as a parameter and free the element. The memory of ’next’ must not be freed.

**ft_lstiter**

*void	ft_lstiter(t_list \*lst, void (\*f)(void \*))*

The ft_lstiter() function iterates the list ’lst’ and applies the function ’f’ to the content of each element.

**ft_lstlast**

*t_list	\*ft_lstlast(t_list \*lst)*

The ft_lstlast() function returns the last element of the list.

**ft_lstmap**

*t_list	\*ft_lstmap(t_list \*lst, void \*(\*f)(void \*), void (\*del)(void \*))*

The ft_lstmap() function iterates the list ’lst’ and applies the function ’f’ to the content of each element. Creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of an element if needed.

**ft_lstnew**

*t_list	\*ft_lstnew(void \*content)*

The ft_lstnew() function allocates (with malloc) and returns a new element. The variable content’ is initialized with the value of the parameter ’content’. The variable ’next’ is initialized to NULL.

**ft_lstsize**

*int	ft_lstsize(t_list \*lst)*

The ft_lstsize() function counts the number of elements in a list.


## EXTRA FUNCTIONS
*Las funciones extras están en nuevas carpetas, únicamente están aquí apuntadas como referencia*

**ft_abs**

*int	ft_abs(int a)*

The ft_abs() function returns the absolute value of its int operand.

**ft_atoi_base**

*int	ft_atoi_base(const char \*str, int base)*

The ft_atoi_base() function parses the C-string str interpreting its content as an integral number, which is returned as a value of type int. The character reveals the number in a specific base, given as a second parameter.

**ft_find_next_prime**

*int	ft_find_next_prime(int nb)*

The ft_find_next_prime() function returns the next prime number greater or equial to the number given as argument.

**ft_ftoa**

*char	\*ft_ftoa(long double ld)*

The ft_ftoa() function converts an float value to a null-terminated string using the specified base and returns the string.

**ft_is_prime**

*int	ft_is_prime(int nb)*

The ft_is_prime() function returns 1 if the number given as a parameter is a prime number and 0 if it is not.

**ft_itoa_base**

*char	\*ft_itoa_base(int n, int base)*

The ft_itoa_base() function converts an integer value to a null-terminated string using the specified base and stores the result in an allocated char array. The base is expressed as an integer, from 2 to 16.

**ft_ltoa**

*char	\*ft_ltoa(long n)*

The ft_ltoa() function converts an long integer value to a null-terminated string using the specified base and returns the string.

**ft_ltoa_base**

*char	\*ft_ltoa_base(long n, int base)*

The ft_ltoa_base() function converts a long integer value to a null-terminated string using the specified base and stores the result in an allocated char array. The base is expressed as an integer, from 2 to 16.

**ft_max**

*int	ft_max(int a, int b)*

The ft_max() function returns the greater value of both integers given as parameters.

**ft_memalloc**

*void	\*ft_memalloc(size_t size)*

The ft_memalloc() function allocates (with malloc) and fills its size by writing zeros (bytes containing '\0'). It should be cast with its data type on front.
Ex. (char *)ft_memalloc(size)

**ft_memfree**

*void	ft_memfree(void \*\*all, char \*new)*

The ft_memfree() function frees the memory allocated for all and changes it pointes for the one given in new. New could be filled with NULL to completely free the memory.

**ft_min**

*int	ft_min(int a, int b)*

The ft_min() function returns the minimum value of both integers given as parameters.

**ft_print_memory**

*void	ft_print_memory(void \*addr, size_t len)*

The ft_print_memory() function outputs the memory area of the hexadecimal address of addr on screen.

**ft_sqrt**

*int	ft_sqrt(int nb)*

The ft_sqrt() function computes the square root of a number.

**ft_str_tolower**

*char	\*ft_str_tolower(char \*str)*

The ft_str_tolower() function takes all string uppercase characters and convert them to a lowercase characters.

**ft_str_toupper**

*char	\*ft_str_toupper(char \*str)*

The ft_str_toupper() function takes all string lowercase characters and convert them to a uppercase characters.

**ft_strappend_nchr**

*char	\*ft_strappend_nchr(char \*str, int c, int nb)*

The ft_strappend_nchar() function adds nb c characters at the end of str. It allocates new memory, so str should be free after use.

**ft_strappstart_nchr**

*char	\*ft_strappend_nchr(char \*str, int c, int nb)*

The ft_strappend_nchar() function adds nb c characters at the start of str. It allocates new memory, so str should be free after use.

**ft_strchr_count**

*size_t	ft_strchr_count(const char \*str, char c)*

The ft_strchr_count() function searches for a specified character in the given string and counts all the occurrences.

**ft_strchr_pos**

*int	ft_strchr_pos(char \*str, int c)*

The ft_strchr_pos() function searches the first occurence of a specified character in the given string and return the position of that spot on the string. Returns -1 if not found.

**ft_strempt**

*void	ft_strempt(char \*s)*

The ft_strempt() function erases the data in the given string, by writing zeros (bytes containing '\0').

*void	ft_strempt_endchar(char \*s, char c)*

The ft_strempt_endchar() function erases the data in the given string, by writing zeros (bytes containing '\0'), from the end to the begining, while the specified character is found.

**ft_striter**

*void	ft_striter(char \*s, void (\*f)(char \*))*

The ft_striter() function iterates the given string and applies the function ’f’ to the content of each character.

**ft_strncat**

*char	\*ft_strncat(char \*dest, char \*src, size_t nb)*

The strncat() function appends at most n characters and returns a pointer to the null-terminated result. The initial character of s2 overrides the null character at the end of s1.

**ft_strnew**

*char	\*ft_strnew(size_t size)*

The ft_strnew() function allocates (with malloc) and returns a new string of size plus the null character at the end.

**ft_strrev**

*char	\*ft_strrev(const char \*s)*

The ft_strrev() function is used to reverse the given string. It returns a new allocated string (with malloc).

**ft_strspn**

*size_t	ft_strspn(const char \*str, const char \*chars)*

The function ft_strspn() searches specified string in the given string and returns the number of the characters that are matched in the given string.

**ft_swap**

*void	ft_swap(void \*a, void \*b, size_t len)*

The ft_swap() function swaps (converted to unsigned char) len bytes from memory allocated in a, to memory allocated in b.

**ft_uitoa**

*char	\*ft_uitoa(unsigned int n)*

The ft_uitoa() function converts an unsigned integer value to a null-terminated string using the specified base and returns the string.

**ft_uitoa_base**

*char	\*ft_uitoa_base(unsigned int n, int base)*

The ft_uitoa_base() function converts an unsigned integer value to a null-terminated string using the specified base and stores the result in an allocated char array. The base is expressed as an integer, from 2 to 16.

**ft_ultoa**

*char	\*ft_ultoa(unsigned long n)*

The ft_ultoa() function converts an unsigned long integer value to a null-terminated string using the specified base and returns the string.

**ft_ultoa_base**

*char	\*ft_ultoa_base(unsigned long n, int base)*

The ft_ultoa_base() function converts an unsigned long integer value to a null-terminated string using the specified base and stores the result in an allocated char array. The base is expressed as an integer, from 2 to 16.

**ft_wstrlen**

*int	ft_wstrlen(wchar_t *wstr)*

The ft_wstrlen() function calculates the length of a given wide string, taking care of the number of bytes of each wchar_t.

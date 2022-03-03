# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/06/29 18:31:05 by jcarrete          #+#    #+#              #
#    Updated: 2020/07/02 15:41:25 by jcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft
LNAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f
HDIR = -I ./
LIBS = libft.h

#################### Files for Libft ####################

FILES =	ft_atoi \
	ft_bzero \
	ft_calloc \
	ft_isalnum \
	ft_isalpha \
	ft_isascii \
	ft_isdigit \
	ft_isprint \
	ft_itoa \
	ft_memccpy \
	ft_memchr \
	ft_memcmp \
	ft_memcpy \
	ft_memmove \
	ft_memset \
	ft_putchar_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_putstr_fd \
	ft_split \
	ft_strchr \
	ft_strdup \
	ft_strjoin \
	ft_strlcat \
	ft_strlcpy \
	ft_strlen \
	ft_strmapi \
	ft_strncmp \
	ft_strnstr \
	ft_strrchr \
	ft_strtrim \
	ft_substr \
	ft_tolower \
	ft_toupper

FILES_B = ft_lstadd_back \
	ft_lstadd_front \
	ft_lstclear \
	ft_lstdelone \
	ft_lstiter \
	ft_lstlast \
	ft_lstmap \
	ft_lstnew \
	ft_lstsize

SRCS = $(addsuffix .c, $(FILES))
SRCS_B = $(addsuffix .c, $(FILES_B))

OBJS = $(SRCS:.c=.o)
OBJS_B = $(SRCS_B:.c=.o)

#################### Colors ####################

R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

#################### Rules ####################

all: $(NAME)

$(NAME) : $(OBJS)
	@echo "\n$(GR)[Compiling original $(B)'$(LNAME)'$(GR). Please, wait a few seconds...]${END}\n"
	$(CC) $(CFLAGS) -c $(SRCS) $(HDIR)
	$(AR) $(LNAME) $(OBJS)
	@echo "\n$(G)[Compiled $(B)'$(NAME)' $(G)successfully]${END}\n"

clean:
	$(RM) $(OBJS) $(OBJS_B)
	@echo "\n$(R)[Cleaned $(B)objects $(R)successfully]$(END)\n"

fclean: clean
	$(RM) $(LNAME)
	@echo "$(R)[Removed $(B)'$(NAME)' $(R)successfully]$(END)\n"

re: fclean all

bonus: $(OBJS) $(OBJS_B)
	@echo "\n$(GR)[Compiling original$(B)'$(LNAME)'$(GR) + bonus. Please, wait a few seconds...]${END}\n"
	$(CC) $(CFLAGS) -c $(SRCS) $(SRCS_B) $(HDIR)
	$(AR) $(LNAME) $(OBJS) $(OBJS_B)
	@echo "\n$(G)[Compiled $(B)bonus '$(LNAME)' $(G)successfully]${END}\n"

Norme:
	norminette -R CheckForbiddenSourceHeader $(SRCS) $(SRCS_B) $(LIBS)
	@echo "\n$(Y)[Checked norminette in $(B)'$(NAME)' $(Y)successfully]$(END)\n"

Leaks: CFLAGS += -g3 -fsanitize=address
Leaks: re
	@echo "\n$(Y)[Checked leaks in $(B)'$(LNAME)' $(Y)successfully]$(END)\n"

.PHONY: all clean fclean re bonus Norme Leaks

$(V).SILENT:

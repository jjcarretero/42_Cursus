# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/08 22:52:45 by jcarrete          #+#    #+#              #
#    Updated: 2020/09/19 20:05:22 by jcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LNAME = libftprintf.a
NAME = libftprintf

CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft
PRINTF = ft_printf
AR = ar rcs
RM = rm -rf

HDIR = includes
SDIR = src
ODIR = obj

#################### Files for FtPrintf ####################

FILES = ft_printf \
	ft_printf_conver \
	ft_printf_prtchar \
	ft_printf_prtdecexp \
	ft_printf_prtexp \
	ft_printf_prtfloat \
	ft_printf_prthex \
	ft_printf_prtint \
	ft_printf_prtoctal \
	ft_printf_prtpoint \
	ft_printf_prtret \
	ft_printf_prtspc \
	ft_printf_prtuint \
	ft_printf_prtwchar \
	ft_printf_prtwstr \
	ft_printf_utils \
	ft_printf_utils_eg \
	ft_printf_width


SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

########################## Colors ##########################

R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

########################## Rules ##########################

all: $(LNAME)

$(LNAME): $(OBJS)
	@echo "\n$(GR)[Compiling $(B)'$(LNAME)'$(GR). Please, wait a few seconds...]${END}\n"
	make -C $(LIBFT)
	cp libft/libft.a ./$(LNAME)
	$(AR) $(LNAME) $(OBJS)
	@echo "\n$(G)[Compiled $(B)'$(LNAME)' $(G)successfully]${END}\n"

$(ODIR)/%.o: $(SDIR)/%.c $(HDIR)/$(PRINTF).h
	mkdir -p $(ODIR)
	$(CC) $(CFLAGS) -I $(HDIR) -o $@ -c $<

clean:
	$(RM) $(OBJS) $(ODIR)
	make clean -C $(LIBFT)
	@echo "\n$(R)[Cleaned $(B) $(NAME) objects $(R)successfully]$(END)\n"

fclean:
	$(RM) $(OBJS) $(ODIR)
	@echo "\n$(R)[Cleaned $(B) $(NAME) objects $(R)successfully]$(END)\n"
	$(RM) $(LNAME)
	make fclean -C $(LIBFT)
	@echo "$(R)[Removed $(B)'$(LNAME)' $(R)successfully]$(END)\n"

re: fclean all

bonus: $(OBJS)
	@echo "\n$(GR)[Compiling $(B)'$(LNAME) bonus'$(GR). Please, wait a few seconds...]${END}\n"
	make -C $(LIBFT)
	cp libft/libft.a ./$(LNAME)
	$(AR) $(LNAME) $(OBJS)
	@echo "\n$(G)[Compiled $(B)'$(NAME) bonus' $(G)successfully]${END}\n"

Norme:
	norminette -R CheckForbiddenSourceHeader $(LIBFT)/ $(SDIR)/ $(HDIR)
	@echo "\n$(Y)[Checked norminette in $(B)'$(NAME)' $(Y)successfully]$(END)\n"

Debug: CFLAGS += -g3
Debug: fclean $(OBJS)
	@echo "\n$(GR)[Compiling $(B)'$(LNAME)'$(GR). Please, wait a few seconds...]${END}\n"
	make Debug -C $(LIBFT)
	cp libft/libft.a ./$(LNAME)
	$(AR) $(LNAME) $(OBJS)
	@echo "\n$(G)[Compiled $(B)'$(LNAME)' $(G)successfully]${END}\n"
	@echo "\n$(Y)[Mode debug activated for $(B)'$(NAME)']$(END)\n"

Leaks: CFLAGS += -g3 -fsanitize=address
Leaks: fclean $(OBJS)
	@echo "\n$(GR)[Compiling $(B)'$(LNAME)'$(GR). Please, wait a few seconds...]${END}\n"
	make Leaks -C $(LIBFT)
	cp libft/libft.a ./$(LNAME)
	$(AR) $(LNAME) $(OBJS)
	@echo "\n$(G)[Compiled $(B)'$(LNAME)' $(G)successfully]${END}\n"
	@echo "\n$(Y)[Mode leaks activated for $(B)'$(NAME)']$(END)\n"

.PHONY: all clean fclean re bonus Norme Leaks Debug

$(V).SILENT:

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 22:12:25 by jcarrete          #+#    #+#              #
#    Updated: 2021/10/12 20:47:54 by jcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap
CHECKER = checker
NAME = $(PUSH_SWAP)
BONUS =  $(CHECKER)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -rf

#################### Directories ####################

LDIR = lib
LIBFT = libft
LIBFT_A = libft.a
HDIR = include
SDIR = src
ODIR = obj

#################### Files for Push Swap ####################

FILES = main \
		exit \
		check_arguments \
		operations_utils \
		operations \
		prepare_stacks \
		print \
		utils_stacks \
		utils_stacks_2 \
		/push_swap/bubble_sort \
		/push_swap/bubble_utils \
		/push_swap/push_swap \
		/push_swap/sort_few_elem

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

FILES_B = main \
		exit \
		check_arguments \
		operations_utils \
		operations \
		prepare_stacks \
		print \
		utils_stacks \
		utils_stacks_2 \
		/checker/checker \
		/checker/instructions

SRCS_B = $(addsuffix .c, $(FILES_B))

OBJS_B = $(addprefix $(ODIR)/,$(SRCS_B:.c=.o))

########################## Colors ##########################

R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

########################## Rules ##########################

all: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(GR)[Compiling $(B)'$(NAME)'$(GR). Please, wait a few seconds...]${END}\n"
	make -C $(LDIR)/$(LIBFT)
	cp $(LDIR)/$(LIBFT)/$(LIBFT_A) ./$(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) -I/$(HDIR) ./$(LIBFT_A) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A)
	@echo "\n$(G)[Compiled $(B)'$(NAME)' $(G)successfully]${END}\n"

$(ODIR)/%.o: $(SDIR)/%.c $(HDIR)/push_swap.h | $(ODIR)
	$(CC) $(CFLAGS) -I $(HDIR) -o $@ -c $<

$(ODIR):
	mkdir -p $(ODIR)
	mkdir -p $(ODIR)/checker
	mkdir -p $(ODIR)/push_swap


bonus: $(OBJS_B)
	@echo "\n$(GR)[Compiling $(B)'$(BONUS)'$(GR). Please, wait a few seconds...]${END}\n"
	make -C $(LDIR)/$(LIBFT)
	cp $(LDIR)/$(LIBFT)/$(LIBFT_A) ./$(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS_B) -I/$(HDIR) ./$(LIBFT_A) $(LIBS) -o ${BONUS}
	$(RM) ./$(LIBFT_A)
	@echo "\n$(G)[Compiled $(B)'$(BONUS)' $(G)successfully]${END}\n"

clean:
	$(RM) $(OBJS) $(ODIR) $(OBDIR)
	make fclean -C $(LDIR)/$(LIBFT)
	@echo "\n$(R)[Cleaned $(B) $(NAME) objects $(R)successfully]$(END)\n"

fclean: clean
	@echo "\n$(R)[Cleaned $(B) $(NAME) objects $(R)successfully]$(END)\n"
	$(RM) $(NAME) $(BONUS)
	@echo "$(R)[Removed $(B)'$(NAME)' $(R)successfully]$(END)\n"

re: fclean all

re_bonus: fclean bonus

Norme:
	norminette $(LDIR)/$(LIBFT) $(SDIR)/ $(HDIR)
	@echo "\n$(Y)[Checked norminette in $(B)'$(NAME)' $(Y)successfully]$(END)\n"

Debug: CFLAGS += -g3 -fsanitize=address
Debug: fclean $(OBJS)
	@echo "\n$(GR)[Compiling $(B)'$(NAME)'$(GR). Please, wait a few seconds...]${END}\n"
	make Debug -C $(LDIR)/$(LIBFT)
	cp $(LDIR)/$(LIBFT)/$(LIBFT_A) ./$(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) -I/$(HDIR) ./$(LIBFT_A) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A)
	@echo "\n$(G)[Compiled $(B)'$(NAME)' $(G)successfully]${END}\n"
	@echo "\n$(Y)[Mode debug activated for $(B)'$(NAME)']$(END)\n"

.PHONY: all clean fclean re bonus Norme Debug

$(V).SILENT:

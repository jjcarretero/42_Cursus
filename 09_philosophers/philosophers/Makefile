# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/11 21:40:20 by jcarrete          #+#    #+#              #
#    Updated: 2022/03/01 20:29:06 by jcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = clang
CFLAGS = -Wall -Wextra -Werror -O3 -pthread
#CFLAGS += -g3 -fsanitize=address

AR = ar rcs
RM = rm -rf

NORME = norminette

#################### Directories ####################

HDIR = include
HEAD = philosophers.h
SDIR = src/mandatory
ODIR = obj/mandatory
OPARENT = obj

BHEAD = philosophers_bonus.h
SBDIR = src/bonus
OBDIR = obj/bonus

#################### Files for Philosophers ####################

FILES =	init/check_args \
		init/join_thread \
		init/init_monitor \
		init/init_philos \
		philo_cycle/philo_cycle \
		philo_cycle/philo_eating \
		philo_cycle/philo_forks \
		philo_cycle/philo_print_status \
		philo_cycle/philo_sleeping \
		philo_cycle/philo_thinking \
		utils/ft_atoi \
		utils/ft_getter \
		utils/ft_gettime \
		utils/ft_ltoa \
		utils/ft_memalloc \
		utils/ft_putchar_fd \
		utils/ft_strjoin \
		utils/ft_strlen \
		utils/ft_usleep \
		create_philo_thread \
		errors \
		garbage \
		main \
		monitor_status \

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

FILES_B = init/check_args \
		init/init_monitor \
		init/init_philos \
		philo_cycle/philo_cycle \
		philo_cycle/philo_eating \
		philo_cycle/philo_forks \
		philo_cycle/philo_print_status \
		philo_cycle/philo_sleeping \
		philo_cycle/philo_thinking \
		utils/ft_atoi \
		utils/ft_getter \
		utils/ft_gettime \
		utils/ft_ltoa \
		utils/ft_memalloc \
		utils/ft_putchar_fd \
		utils/ft_strlen \
		utils/ft_usleep \
		create_monitor_process \
		errors \
		garbage \
		main \

SRCS_B = $(addsuffix .c, $(FILES_B))

OBJS_B = $(addprefix $(OBDIR)/,$(SRCS_B:.c=.o))

########################## Colors ##########################

CUT = \033[K
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
	$(CC) $(CFLAGS) $(OBJS) -I/$(HDIR) -o ${NAME}
	@echo "\n$(G)[Compiled $(B)'$(NAME)' $(G)successfully]${END}\n"

$(ODIR)/%.o: $(SDIR)/%.c $(HDIR)/$(HEAD) | $(ODIR)
	$(eval STR=$(shell echo "${CUT}\t${Y}Compiling: ${END}$<${END}"))
	@bash -c "printf '\r$(STR)\0'"
	$(CC) $(CFLAGS) -I $(HDIR) -o $@ -c $<

$(ODIR):
	@echo "\n$(GR)[Compiling $(B)'$(NAME)'$(GR). Please wait...]${END}"
	mkdir -p $(ODIR)
	mkdir -p $(ODIR)/init
	mkdir -p $(ODIR)/philo_cycle
	mkdir -p $(ODIR)/utils

bonus: $(OBJS_B)
	$(CC) $(CFLAGS) $(OBJS_B) -I/$(HDIR) -o ${NAME}
	@echo "\n$(G)[Compiled $(B)'$(NAME)' $(G)successfully]${END}\n"

$(OBDIR)/%.o: $(SBDIR)/%.c $(HDIR)/$(BHEAD) | $(OBDIR)
	$(eval STR=$(shell echo "${CUT}\t${Y}Compiling: ${END}$<${END}"))
	@bash -c "printf '\r$(STR)\0'"
	$(CC) $(CFLAGS) -I $(HDIR) -o $@ -c $<

$(OBDIR):
	@echo "\n$(GR)[Compiling $(B)'$(NAME)_Bonus'$(GR). Please wait...]${END}"
	mkdir -p $(OBDIR)
	mkdir -p $(OBDIR)/init
	mkdir -p $(OBDIR)/philo_cycle
	mkdir -p $(OBDIR)/utils

clean:
ifneq ($(wildcard $(ODIR)/.*)$(wildcard $(OBDIR)/.*),)
	@echo "\n$(GR)[Cleaning $(B)'$(NAME)'$(GR). Please wait...]${END}"
ifneq ($(wildcard $(OBDIR)/.*),)
	$(RM) $(OBJS_B) $(OBDIR)
	@echo "$(G)[Removed $(B) $(NAME) bonus objects $(G)successfully]$(END)\n"
endif
ifneq ($(wildcard $(ODIR)/.*),)
	$(RM) $(OBJS) $(ODIR)
	@echo "$(G)[Removed $(B) $(NAME) objects $(G)successfully]$(END)\n"
endif
	$(RM) $(OPARENT)
else
	@echo "\n$(R)[No objects to clean in $(B)$(NAME)$(R)]$(END)\n"
endif

fclean:
ifneq ("$(wildcard $(NAME))$(wildcard $(BONUS))$(wildcard $(ODIR)/.*)$(wildcard $(OBDIR)/.*)","")
	@echo "\n$(GR)[Cleaning $(B)'$(NAME)'$(GR). Please wait...]${END}"
ifneq ($(wildcard $(ODIR)/.*),)
	$(RM) $(OBJS) $(ODIR)
	@echo "$(G)[Removed $(B) $(NAME) objects $(G)successfully]$(END)"
endif
ifneq ($(wildcard $(OBDIR)/.*),)
	$(RM) $(OBJS_B) $(OBDIR)
	@echo "$(G)[Removed $(B) $(NAME) bonus objects $(G)successfully]$(END)"
endif
ifneq ("$(wildcard $(NAME))","")
	$(RM) $(NAME)
	@echo "$(G)[Removed $(B) $(NAME) $(G)successfully]$(END)"
endif
ifneq ("$(wildcard $(BONUS))","")
	$(RM) $(BONUS)
	@echo "$(G)[Removed $(B) $(NAME) bonus objects $(G)successfully]$(END)"
endif
	$(RM) $(OPARENT)
else
	@echo "\n$(R)[Nothing to clean in $(B)$(NAME)$(R)]$(END)\n"
endif

re: fclean all

re_bonus: fclean bonus

norme:
	@echo "\n$(GR)[Checking $(B)'$(NORME)'$(GR) in $(B)'$(NAME)'$(GR). Please wait...]${END}"
	$(NORME) $(SDIR)/ $(HDIR) | GREP_COLORS='mt=01;32' egrep --color=always 'OK|' | \
	GREP_COLORS='mt=01;31' egrep --color=always 'Error|'
	@echo "\n$(Y)[Checked norminette in $(B)'$(NAME)' $(Y)successfully]$(END)\n"

.PHONY: all clean fclean re bonus norme

$(V).SILENT:

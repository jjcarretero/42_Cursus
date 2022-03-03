# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/20 20:00:18 by rpunet            #+#    #+#              #
#    Updated: 2022/01/31 23:16:39 by jcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

AR = ar rcs
RM = rm -rf

NORME = norminette

#################### Directories ####################

LDIR = lib
LIBFT = libft
LIBFT_A = libft.a
LIBS = -lreadline
HDIR = include
HEAD = minishell.h
SDIR = src
ODIR = obj

#################### Files for Minishell ####################

FILES =	exit \
		free \
		main \
		minishell \
		prompt \
		signs \
		utils \
		executor/builtins/builtins \
		executor/builtins/cd \
		executor/builtins/echo \
		executor/builtins/env \
		executor/builtins/exit \
		executor/builtins/pwd \
		executor/builtins/unset \
		executor/exec_bst \
		executor/exec_command \
		executor/exec_instr \
		executor/exec_process \
		executor/exec_utils \
		executor/exec_redir \
		executor/executor \
		executor/export_envp \
		executor/export_no_args \
		executor/export_utils \
		executor/export \
		executor/here_doc \
		lexer/check_tokens \
		lexer/expander \
		lexer/lexer \
		lexer/token_utils \
		parser/bst \
		parser/command \
		parser/instruction \
		parser/job \
		parser/parser \
		parser/sequence \
		parser/dir \
		parser/filename_exp \
		parser/filename_utils \
		parser/parser_utils \

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

FILES_B =

SRCS_B = $(addsuffix .c, $(FILES_B))

OBJS_B = $(addprefix $(ODIR)/,$(SRCS_B:.c=.o))

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
	$(CC) $(CFLAGS) $(OBJS) -I/$(HDIR) ./$(LDIR)/$(LIBFT)/$(LIBFT_A) $(LIBS) -o ${NAME}
	@echo "\n$(G)[Compiled $(B)'$(NAME)' $(G)successfully]${END}\n"

$(ODIR)/%.o: $(SDIR)/%.c $(HDIR)/$(HEAD) | $(ODIR)
	$(eval STR=$(shell echo "${CUT}\t${Y}Compiling: ${END}$<${END}"))
	@bash -c "printf '\r$(STR)\0'"
	$(CC) $(CFLAGS) -I $(HDIR) -o $@ -c $<

$(ODIR):
	make -C $(LDIR)/$(LIBFT)
	@echo "\n$(GR)[Compiling $(B)'$(NAME)'$(GR). Please, wait a few seconds...]${END}"
	mkdir -p $(ODIR)
	mkdir -p $(ODIR)/executor
	mkdir -p $(ODIR)/executor/builtins
	mkdir -p $(ODIR)/lexer
	mkdir -p $(ODIR)/parser

clean:
	make clean -C $(LDIR)/$(LIBFT)
ifneq ($(wildcard $(ODIR)/.*),)
	@echo "\n$(GR)[Cleaning $(B)'$(NAME)'$(GR). Please wait...]${END}"
	$(RM) $(OBJS) $(ODIR)
	@echo "$(G)[Removed $(B) $(NAME) objects $(G)successfully]$(END)\n"
else
	@echo "\n$(R)[No objects to clean in $(B)$(NAME)$(R)]$(END)\n"
endif

fclean:
	make fclean -C $(LDIR)/$(LIBFT)
ifneq ("$(wildcard $(NAME))$(wildcard $(ODIR)/.*)","")
	@echo "\n$(GR)[Cleaning $(B)'$(NAME)'$(GR). Please wait...]${END}"
ifneq ($(wildcard $(ODIR)/.*),)
	$(RM) $(OBJS) $(ODIR)
	@echo "$(G)[Removed $(B) $(NAME) objects $(G)successfully]$(END)"
endif
ifneq ("$(wildcard $(NAME))","")
	$(RM) $(NAME)
	@echo "$(G)[Removed $(B) $(NAME) $(G)successfully]$(END)"
endif
	@echo ""
else
	@echo "\n$(R)[Nothing to clean in $(B)$(NAME)$(R)]$(END)\n"
endif

re: fclean all

norme:
	make norme -C $(LDIR)/$(LIBFT)
	@echo "\n$(GR)[Checking $(B)'$(NORME)'$(GR) in $(B)'$(NAME)'$(GR). Please wait...]${END}"
	$(NORME) $(SDIR)/ $(HDIR) | GREP_COLORS='mt=01;32' egrep --color=always 'OK|' | \
	GREP_COLORS='mt=01;31' egrep --color=always 'Error|'
	@echo "\n$(Y)[Checked norminette in $(B)'$(NAME)' $(Y)successfully]$(END)\n"

.PHONY: all clean fclean re bonus Norme Debug

$(V).SILENT:


# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 22:12:25 by jcarrete          #+#    #+#              #
#    Updated: 2021/11/09 16:42:38 by jcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex
BONUS = pipex_bonus

CC = gcc
CFLAGS = -Wall -Wextra -Werror

AR = ar rcs
RM = rm -rf

INFILE_NAME = infile
INPUT_NAME = input
INFILE = 'Bonuses will be evaluated only if your mandatory part is PERFECT.\nBy PERFECT we naturally mean that it needs to be complete, that it\ncannot fail, even in cases of nasty mistakes like wrong uses, etc.\nIt means that if your mandatory part does not obtain ALL the points\nduring the grading, your bonuses will be entirely IGNORED.'
OUTPUT_NAME = output
OUTFILE_NAME = outfile

#################### Directories ####################

LDIR = lib
LIBFT = libft
LIBFT_A = libft.a
HDIR = include
HEAD = pipex.h
SDIR = src
ODIR = obj

#################### Files for Pipex ####################

FILES = mandatory/main \
		mandatory/exit \
		mandatory/parser \
		mandatory/pipex

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

FILES_B = bonus/main_bonus \
		bonus/exit_bonus \
		bonus/parser_bonus \
		bonus/pipex_bonus \
		bonus/here_doc_bonus

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

$(ODIR)/%.o: $(SDIR)/%.c $(HDIR)/$(HEAD) | $(ODIR)
	$(CC) $(CFLAGS) -I $(HDIR) -o $@ -c $<

$(ODIR):
	mkdir -p $(ODIR)
	mkdir -p $(ODIR)/mandatory
	mkdir -p $(ODIR)/bonus


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
	$(RM) $(NAME) $(BONUS) $(INFILE_NAME) $(OUTFILE_NAME) $(OUTPUT_NAME) $(INPUT_NAME)
	@echo "$(R)[Removed $(B)'$(NAME)' $(R) and $(B)'files' $(R)successfully]$(END)\n"

re: fclean all

re_bonus: fclean bonus

norme:
	norminette $(LIB)/ $(SDIR)/ $(HDIR)
	@echo "\n$(Y)[Checked norminette in $(B)'$(NAME)' $(Y)successfully]$(END)\n"
	norminette $(SBDIR)/ $(HBDIR)
	@echo "\n$(Y)[Checked norminette in $(B)'$(NAME) BONUS' $(Y)successfully]$(END)\n"

debug: CFLAGS += -g3 -fsanitize=address
debug: fclean $(OBJS)
	@echo "\n$(GR)[Compiling $(B)'$(NAME)'$(GR). Please, wait a few seconds...]${END}\n"
	make Debug -C $(LDIR)/$(LIBFT)
	cp $(LDIR)/$(LIBFT)/$(LIBFT_A) ./$(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS) -I/$(HDIR) ./$(LIBFT_A) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A)
	@echo "\n$(G)[Compiled $(B)'$(NAME)' $(G)successfully]${END}\n"
	@make files
	@echo "\n$(Y)[Mode debug activated for $(B)'$(NAME)']$(END)\n"

debug_bonus: CFLAGS += -g3 -fsanitize=address
debug_bonus: fclean $(OBJS_B)
	@echo "\n$(GR)[Compiling $(B)'$(BONUS)'$(GR). Please, wait a few seconds...]${END}\n"
	make Debug -C $(LDIR)/$(LIBFT)
	cp $(LDIR)/$(LIBFT)/$(LIBFT_A) ./$(LIBFT_A)
	$(CC) $(CFLAGS) $(OBJS_B) -I/$(HDIR) ./$(LIBFT_A) $(LIBS) -o ${BONUS}
	$(RM) ./$(LIBFT_A)
	@echo "\n$(G)[Compiled $(B)'$(BONUS)' $(G)successfully]${END}\n"
	@make files
	@echo "\n$(Y)[Mode debug activated for $(B)'$(BONUS)']$(END)\n"

files:
ifeq (,$(wildcard input))
	@echo "\n$(GR)[Creating $(B)'files'$(GR). Please, wait a few seconds...]${END}\n"
	@touch $(INFILE_NAME)
	@touch $(INPUT_NAME)
	@echo $(INFILE) > $(INFILE_NAME)
	@echo $(INFILE) > $(INPUT_NAME)
	@touch $(OUTFILE_NAME)
	@touch $(OUTPUT_NAME)
	@echo "\n$(G)[Created $(B)'files' $(G)successfully]${END}\n"
else
	@echo "\n$(Y)[$(B)'files' $(Y)already exist]${END}\n"
endif

.PHONY: all clean fclean re bonus Norme debug files

$(V).SILENT:

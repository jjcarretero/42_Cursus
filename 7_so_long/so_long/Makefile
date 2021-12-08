# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/17 22:12:25 by jcarrete          #+#    #+#              #
#    Updated: 2021/11/21 17:04:13 by jcarrete         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

UNAME = $(shell uname -s)
AR = ar rcs
RM = rm -rf

#################### Directories ####################

LDIR = lib
LMLXDIR = libmlx
LIBMLX_A = libmlx.a
LIBFT = libft
LIBFT_A = libft.a
HDIR = include
SDIR = src
ODIR = obj

SBDIR = src_bonus
OBDIR = obj_bonus

ifeq ($(UNAME), Linux)
	LIBS = -lXext -lX11 -lm
	MLXDIR = minilibx-linux
endif
ifeq ($(UNAME), Darwin)
	LIBS = -lz -framework OpenGL -framework AppKit -lm
	MLXDIR = minilibx-darwin
	DLIBMLX = libmlx.dylib
endif

#################### Files for cub3D ####################

FILES =	so_long \
		exit \
		textures \
		utils \
		configuration/i_init_struct \
		configuration/ii_load_scene \
		configuration/iii_set_map \
		configuration/iv_check_map_info \
		configuration/v_floodfill_check \
		configuration/utils_floodfill \
		configuration/utils_floodfill_sides \
		game_loop/i_game_loop \
		game_loop/ii_key_use \
		game_loop/iii_render

SRCS = $(addsuffix .c, $(FILES))

OBJS = $(addprefix $(ODIR)/,$(SRCS:.c=.o))

FILES_B = so_long_bonus \
		exit_bonus \
		free_bonus \
		textures_bonus \
		time \
		utils_bonus \
		animation_bonus/animate_characters \
		animation_bonus/animate_enemy \
		animation_bonus/enemy_movement \
		configuration_bonus/i_init_struct_bonus \
		configuration_bonus/ii_load_scene_bonus \
		configuration_bonus/iii_set_map_bonus \
		configuration_bonus/iv_check_map_info_bonus \
		configuration_bonus/v_floodfill_check_bonus \
		configuration_bonus/utils_floodfill_bonus \
		configuration_bonus/utils_floodfill_sides_bonus \
		configuration_bonus/vi_start_enemies_bonus \
		game_loop_bonus/i_game_loop_bonus \
		game_loop_bonus/ii_key_use_bonus \
		game_loop_bonus/iii_render_bonus \
		game_loop_bonus/iv_render_moves \
		game_loop_bonus/v_render_end

SRCS_B = $(addsuffix .c, $(FILES_B))

OBJS_B = $(addprefix $(OBDIR)/,$(SRCS_B:.c=.o))

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
	@echo "\n$(GR)[Compiling $(B)'minilibx'$(GR). Please, wait a few seconds...]${END}\n"
	make -sC $(LDIR)/$(LMLXDIR)/$(MLXDIR)
ifeq ($(UNAME), Linux)
	cp $(LDIR)/$(LMLXDIR)/$(MLXDIR)/$(LIBMLX_A) ./$(LIBMLX_A)
	@echo "\n$(G)[Compiled $(B)'minilibx' $(G)successfully]${END}\n"
	$(CC) $(CFLAGS) $(OBJS) -I/$(HDIR) ./$(LIBFT_A) ./$(LIBMLX_A) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A) ./$(LIBMLX_A)
endif
ifeq ($(UNAME), Darwin)
	cp $(LDIR)/$(LMLXDIR)/$(MLXDIR)/$(DLIBMLX) ./
	@echo "\n$(G)[Compiled $(B)'minilibx' $(G)successfully]${END}\n"
	$(CC) $(CFLAGS) $(OBJS) -I/$(HDIR) ./$(LIBFT_A) ./$(DLIBMLX) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A)
endif
	@echo "\n$(G)[Compiled $(B)'$(NAME)' $(G)successfully]${END}\n"

$(ODIR)/%.o: $(SDIR)/%.c $(HDIR)/$(NAME).h | $(ODIR)
	$(CC) $(CFLAGS) -I $(HDIR) -o $@ -c $<

$(ODIR):
	mkdir -p $(ODIR)
	mkdir -p $(ODIR)/configuration
	mkdir -p $(ODIR)/game_loop


bonus: $(OBJS_B)
	@echo "\n$(GR)[Compiling $(B)'$(NAME) BONUS'$(GR). Please, wait a few seconds...]${END}\n"
	make -C $(LDIR)/$(LIBFT)
	cp $(LDIR)/$(LIBFT)/$(LIBFT_A) ./$(LIBFT_A)
	@echo "\n$(GR)[Compiling $(B)'minilibx'$(GR). Please, wait a few seconds...]${END}\n"
	make -sC $(LDIR)/$(LMLXDIR)/$(MLXDIR)
ifeq ($(UNAME), Linux)
	cp $(LDIR)/$(LMLXDIR)/$(MLXDIR)/$(LIBMLX_A) ./$(LIBMLX_A)
	@echo "\n$(G)[Compiled $(B)'minilibx' $(G)successfully]${END}\n"
	$(CC) $(CFLAGS) $(OBJS_B) -I/$(HDIR) ./$(LIBFT_A) ./$(LIBMLX_A) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A) ./$(LIBMLX_A)
endif
ifeq ($(UNAME), Darwin)
	cp $(LDIR)/$(LMLXDIR)/$(MLXDIR)/$(DLIBMLX) ./
	@echo "\n$(G)[Compiled $(B)'minilibx' $(G)successfully]${END}\n"
	$(CC) $(CFLAGS) $(OBJS_B) -I/$(HDIR) ./$(LIBFT_A) ./$(DLIBMLX) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A)
endif
	@echo "\n$(G)[Compiled $(B)'$(NAME) BONUS' $(G)successfully]${END}\n"

$(OBDIR)/%.o: $(SBDIR)/%.c $(HDIR)/$(NAME)_bonus.h | $(OBDIR)
	$(CC) $(CFLAGS) -I $(HDIR) -o $@ -c $<

$(OBDIR):
	mkdir -p $(OBDIR)
	mkdir -p $(OBDIR)/animation_bonus
	mkdir -p $(OBDIR)/configuration_bonus
	mkdir -p $(OBDIR)/game_loop_bonus

clean:
	$(RM) $(OBJS) $(ODIR) $(OBDIR)
	make fclean -C $(LDIR)/$(LIBFT)
	make clean -C $(LDIR)/$(LMLXDIR)/$(MLXDIR)
	@echo "\n$(R)[Cleaned $(B) $(NAME) objects $(R)successfully]$(END)\n"

fclean: clean
	$(RM) $(NAME)
ifeq ($(UNAME),Darwin)
	$(RM) $(DLIBMLX)
endif
	@echo "$(R)[Removed $(B)'$(NAME)' $(R)successfully]$(END)\n"

re: fclean all

re_bonus: fclean bonus

Norme:
	norminette $(LIB)/ $(SDIR)/ $(HDIR)
	@echo "\n$(Y)[Checked norminette in $(B)'$(NAME)' $(Y)successfully]$(END)\n"
	norminette -R CheckForbiddenSourceHeader $(SBDIR)/ $(HBDIR)
	@echo "\n$(Y)[Checked norminette in $(B)'$(NAME) BONUS' $(Y)successfully]$(END)\n"

Debug: CFLAGS += -O0 -g3 -fsanitize=address
Debug: fclean $(OBJS)
	@echo "\n$(GR)[Compiling $(B)'$(NAME)'$(GR). Please, wait a few seconds...]${END}\n"
	make Debug -C $(LDIR)/$(LIBFT)
	cp $(LDIR)/$(LIBFT)/$(LIBFT_A) ./$(LIBFT_A)
		@echo "\n$(GR)[Compiling $(B)'minilibx'$(GR). Please, wait a few seconds...]${END}\n"
	make -sC $(LDIR)/$(LMLXDIR)/$(MLXDIR)
ifeq ($(UNAME), Linux)
	cp $(LDIR)/$(LMLXDIR)/$(MLXDIR)/$(LIBMLX_A) ./$(LIBMLX_A)
	@echo "\n$(G)[Compiled $(B)'minilibx' $(G)successfully]${END}\n"
	$(CC) $(CFLAGS) $(OBJS) -I/$(HDIR) ./$(LIBFT_A) ./$(LIBMLX_A) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A) ./$(LIBMLX_A)
endif
ifeq ($(UNAME), Darwin)
	cp $(LDIR)/$(LMLXDIR)/$(MLXDIR)/$(DLIBMLX) ./$(DLIBMLX)
	@echo "\n$(G)[Compiled $(B)'minilibx' $(G)successfully]${END}\n"
	$(CC) $(CFLAGS) $(OBJS) -I/$(HDIR) ./$(LIBFT_A) ./$(DLIBMLX) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A)
endif
	@echo "\n$(G)[Compiled $(B)'$(NAME)' $(G)successfully]${END}\n"
	@echo "\n$(Y)[Mode debug activated for $(B)'$(NAME)']$(END)\n"

Bdebug: CFLAGS += -O0 -g3 -fsanitize=address
Bdebug: fclean $(OBJS_B)
	@echo "\n$(GR)[Compiling $(B)'$(NAME) BONUS'$(GR). Please, wait a few seconds...]${END}\n"
	make Debug -C $(LDIR)/$(LIBFT)
	cp $(LDIR)/$(LIBFT)/$(LIBFT_A) ./$(LIBFT_A)
		@echo "\n$(GR)[Compiling $(B)'minilibx'$(GR). Please, wait a few seconds...]${END}\n"
	make -sC $(LDIR)/$(LMLXDIR)/$(MLXDIR)
ifeq ($(UNAME), Linux)
	cp $(LDIR)/$(LMLXDIR)/$(MLXDIR)/$(LIBMLX_A) ./$(LIBMLX_A)
	@echo "\n$(G)[Compiled $(B)'minilibx' $(G)successfully]${END}\n"
	$(CC) $(CFLAGS) $(OBJS_B) -I/$(HDIR) ./$(LIBFT_A) ./$(LIBMLX_A) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A) ./$(LIBMLX_A)
endif
ifeq ($(UNAME), Darwin)
	cp $(LDIR)/$(LMLXDIR)/$(MLXDIR)/$(DLIBMLX) ./$(DLIBMLX)
	@echo "\n$(G)[Compiled $(B)'minilibx' $(G)successfully]${END}\n"
	$(CC) $(CFLAGS) $(OBJS_B) -I/$(HDIR) ./$(LIBFT_A) ./$(DLIBMLX) $(LIBS) -o ${NAME}
	$(RM) ./$(LIBFT_A)
endif
	@echo "\n$(G)[Compiled $(B)'$(NAME) BONUS' $(G)successfully]${END}\n"
	@echo "\n$(Y)[Mode debug activated for $(B)'$(NAME) BONUS']$(END)\n"

.PHONY: all clean fclean re bonus Norme Debug

$(V).SILENT:

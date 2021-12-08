/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcarrete <jcarrete@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 11:26:00 by jcarrete          #+#    #+#             */
/*   Updated: 2021/11/21 17:24:42 by jcarrete         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

/*
**	------------ LIBRARIES ------------
*/

# include "libft.h"
# include "ft_printf.h"
# include "keycodes.h"
# include "events.h"
# include "colors.h"
# include <fcntl.h>
# include <errno.h>
# include <time.h>
# ifdef __APPLE__
#  include "../lib/libmlx/minilibx-darwin/mlx.h"
# elif defined __unix__
#  include "../lib/libmlx/minilibx-linux/mlx.h"
# endif

/*
**	------------ CONSTANTS ------------
*/

# ifdef __APPLE__
#  define LINUX FALSE
# elif defined __unix__
#  define LINUX TRUE
#  define MLX_SYNC_WIN_CMD_COMPLETED FALSE
# endif

# define MAP_OBJECTS			"01CEPM"
# define TILE_SIZE				64
# define WINDOW_TITLE			"so_long"

# define NUMTEXTURESPLAYER		20
# define NUMTEXTURESMONSTERS	20
# define NUMTEXTURESCOIN		1
# define NUMTEXTURESEXIT		2
# define NUMTEXTURESWALL		1
# define NUMTEXTURESFLOOR		1
# define NUMTEXTURESEND			2

# define ARROWKEYS				4
# define WAITTIME				25

# define FONT	"-misc-fixed-bold-r-normal--0-125-60-80-c-110-iso8859-1"

/*
**	----------- ENUMERATORS -----------
*/

enum	e_key_states
{
	KEY_RELEASED,
	KEY_PRESSED
};

enum	e_directions
{
	D_SOUTH = 0,
	D_NORTH = 5,
	D_EAST = 10,
	D_WEST = 15
};

enum	e_game_state
{
	S_START,
	S_RENDER_START,
	S_RUNNING,
	S_WIN,
	S_LOSE,
	S_EXIT
};

enum e_free
{
	F_NONE,
	F_GAME,
	F_MLX,
	F_MAP,
	F_WIN,
	F_SUCCESS
};

enum e_errors
{
	E_NONE,
	E_MEM,
	E_ARGS,
	E_MAP,
	E_MLX,
	E_FILE_O,
	E_FILE_C,
	E_READ,
	E_EMPTY,
	E_LIST,
	E_IMG,
	E_WIN,
	E_SUCCESS
};

enum	e_textures
{
	T_NONE,
	T_WALL,
	T_FLOOR,
	T_EXIT,
	T_COLLECTABLE,
	T_PLAYER,
	T_MONSTER,
	T_END,
};

enum e_keycode
{
	K_KEY_S,
	K_KEY_W,
	K_KEY_D,
	K_KEY_A,
	K_KEY_UP,
	K_KEY_RIGHT,
	K_KEY_LEFT,
	K_KEY_DOWN,
	K_KEY_NONE
};

/*
**	------------- STRUCTS -------------
*/

typedef struct s_point
{
	int			x;
	int			y;
	int			extra;
}				t_point;

typedef struct s_mlx_image
{
	int			width;
	int			height;

	int			bits_per_pixel;
	int			line_length;
	int			endian;
	void		*img;
	char		*addr;
}				t_mlx_image;

typedef struct s_monster
{
	int			dir;
	int			pos_x;
	int			pos_y;
	int			frame;
	int			wait;
	t_mlx_image	img_monster;
}				t_monster;

typedef struct s_textures
{
	char		player_path[NUMTEXTURESPLAYER][128];
	char		wall_path[NUMTEXTURESWALL][128];
	char		floor_path[NUMTEXTURESFLOOR][128];
	char		coin_path[NUMTEXTURESCOIN][128];
	char		exit_path[NUMTEXTURESEXIT][128];
	char		monsters_path[NUMTEXTURESMONSTERS][128];
	char		end_path[NUMTEXTURESEND][128];
	t_mlx_image	img_background;
	t_mlx_image	img_collectable;
	t_mlx_image	img_end;
	t_mlx_image	img_exit;
	t_mlx_image	img_player;
	t_mlx_image	img_wall;
}				t_textures;

typedef struct s_map_data
{
	int			width;
	int			height;
	char		**map;
	int			ones;
	int			collectables;
	int			exit;
	int			num_monsters;
	int			monsters_init;
	t_monster	*monsters;
	t_textures	textures;
}				t_map_data;

typedef struct s_mlx_data
{
	int			width;
	int			height;

	void		*mlx;
	char		*win;
	t_mlx_image	image;

}				t_mlx_data;

typedef struct s_player_data
{
	int			map_x;
	int			map_y;
	int			pos_x;
	int			pos_y;
	int			moves;
	int			last;
	int			dir;
}				t_player_data;

typedef struct s_so_long_game
{
	int					game_state;
	int					keycode_state;
	t_mlx_data			mlx_data;
	t_player_data		player_data;
	t_map_data			map_data;
}				t_so_long_game;

/*
**	------------ PROTOTYPES ------------
*/

int		animate_characters(t_so_long_game *game);
void	animate_enemy(t_so_long_game *game);
void	check_map_info(t_so_long_game *game);
void	enemy_movement(t_so_long_game *game, int i);
void	exit_program(t_so_long_game *game, int status, int err, char *extra);
int		exit_success(t_so_long_game *game);
void	floodfilling_check(t_so_long_game *game);
void	ff_change_value(int old, int *new, int v);
int		ff_check_corner_l(t_so_long_game *game, int **hash, \
							t_point *pos, int v);
int		ff_check_corner_r(t_so_long_game *game, int **hash, \
							t_point *pos, int v);
int		ff_check_position(int cell, int val, t_point *pos, int d);
int		ff_check_side_l(t_so_long_game *game, int **hash, t_point *pos, int v);
int		ff_check_side_r(t_so_long_game *game, int **hash, t_point *pos, int v);
int		ff_copy_coords(int x, int y, int *new_x, int *new_y);
void	ff_print_map(t_so_long_game *game, int **hash);
void	free_hash(t_so_long_game *game, int **hash);
void	free_program(t_so_long_game *game, int status);
void	ft_delay(int milliseconds);
void	game_loop(t_so_long_game *game);
void	initialize_game_struct(t_so_long_game *game);
int		key_press_use(int key, t_so_long_game *game);
void	load_scene_description(t_so_long_game *game, char *file);
void	load_textures(t_so_long_game *game);
void	print_map(t_so_long_game *game);
void	process_input(t_so_long_game *game);
int		check_if_end(t_so_long_game *game);
int		render_map(t_so_long_game *game);
void	render_moves(t_so_long_game *game);
void	render_texture(int type, t_so_long_game *game, int y, int x);
char	**set_map(t_so_long_game *game, t_list *list, t_map_data *data);
void	start_enemies(t_so_long_game *game);
#endif

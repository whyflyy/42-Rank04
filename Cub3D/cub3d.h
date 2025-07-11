/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcavadas <jcavadas@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:27:31 by jcavadas          #+#    #+#             */
/*   Updated: 2025/07/10 17:31:51 by jcavadas         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

//HEADER FILES
# include "./libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
//# include </opt/X11/include/X11/X.h>
//# include </opt/X11/include/X11/keysym.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <stdbool.h>
# include <math.h>

//COLOURS
# define RESET		"\033[0m"
# define RED		"\033[38;5;160m"
# define DARK_RED	"\033[38;5;124m"
# define GREEN		"\033[38;5;76m"
# define BLUE		"\033[38;5;111m"
# define YELLOW		"\033[38;5;220m"
# define MAGENTA	"\033[38;5;183m"
# define CYAN    	"\033[38;5;87m"

//MAP COLOURS
# define MAP_SKYBLUE	0x87CEEB
# define MAP_FLOORGREY	0xA1AEB1
# define MAP_BLUE		0x2e8bc0
# define MAP_GREY		0x808080
# define MAP_GREEN		0x008000
# define MAP_RED		0xFF0000
# define MAP_YELLOW		0xFFFF00

//SIZES
# define WIN_WIDTH	1280 //1280
# define WIN_HEIGHT	720 //720
# define CUBE_SIZE	64
# define MINI_SIZE	8

# define MOVESPEED 0.05
# define ROTATESPEED 0.04

//KEYS
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define ESC_KEY 65307

//STRUCTURES
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_mov
{
	int		forward;
	int		back;
	int		left;
	int		right;
	int		rotate_left;
	int		rotate_right;
}				t_mov;

typedef struct s_game
{
	//Coisas que vai ter do parsing
	char	**map;
	char	**map_copy;
	int		map_height;
	int		map_width;
	int		valid_map;
	char	*no_texture; //Textura North
	char	*so_texture; //Textura South
	char	*ea_texture; //Textura East
	char	*we_texture; //Textura West
	int		floor_clr[3]; //Cor chao
	int		ceiling_clr[3]; //Cor teto
	char	*filename;
	int		file;

	//Coisas novas do merge
	float	pos[2]; //0 -> x 1 -> y
	float	dir[2]; //0 -> x 1 -> y
	double	ray_dir[2]; //0 -> x 1 -> y
	float	plane[2]; //0 -> x 1 -> y
	int		map_pos[2];
	float	side_dist[2]; //0 -> x 1 -> y
	float	delta_dist[2]; //0 -> x 1 -> y
	int		step[2];
	char	hit_side;
	double	wall_x;
	void	*mlx;
	void	*win;
	t_img	screen;
	t_img	textures[4]; //0->N 1->S 2->E 3->W
	t_mov	mov;
}	t_game;

//FUNCTIONS

//MAIN
bool	check_type(char *filename, char *extension);

//INIT
void	init_vars(t_game *game);
void	init_ray_vars(t_game *game);
void	init_mlx(t_game *game);

//Error
void	error_msg(char *msg, t_game *game);

//FREES
void	quit_game(t_game *game, int exit_code);
int		x_quit_game(t_game *game);

//MAP_UTILS
void	get_map(t_game *game, int fd, char *line);
void	free_map(char **map);
void	copy_map(t_game *game);

//MAP_PARSING
void	get_player_pos(t_game *game);
void	flood_fill(char **map_copy, int y, int x, t_game *game);
void	flood_fill_check_chars(char **map_copy, int y, int x, t_game *game);

//FILE_EXTRACT_INFO
void	extract(t_game *game);

//EXTRACT_UTILS
void	get_colour(char *line, int *dest, t_game *game);
char	*get_texture(char *line, t_game *game);
void	process_line(t_game *game, char *temp, int i);
int		has_all(t_game *game);
int		colour_is_set(int colour[3]);

//UTILS
int		is_empty_line(char *line);
int		is_whitespace(char c);
void	strip_trailing_whitespace(char *s);
int		get_max_width(char **map);
int		has_all(t_game *game);

//GAME RENDER
int		game_render(t_game *game);
void	camera_render(t_game *game);

//MLX_PRINT
void	ft_put_pixel(t_img *img, int x, int y, int color);
void	render_wall_column(t_game *game, int x, int line_height, int side);
void	mlx_loop_and_hooks(t_game *game);

//RAYCAST
void	delta_dist_calc(t_game *game, double ray_dir_x, double ray_dir_y);
void	side_dist_calc(t_game *game, double ray_dir_x, double ray_dir_y);
double	dda(t_game *game, double ray_dir_x, double ray_dir_y);
void	render_vertical_line(t_game *game, int x, double perp_dist);

//MOVEMENT
int		collision(t_game *game, int x, int y);
void	press_forward(t_game *game);
void	press_back(t_game *game);
void	press_left(t_game *game);
void	press_right(t_game *game);
void	rotate_right(t_game *game);
void	rotate_left(t_game *game);
int		on_keypress(int keysym, t_game *game);
int		on_keyrealease(int keysym, t_game *game);
int		update_moves(t_game *game);
void	movement(t_game *game, float move_x, float move_y);
void	ft_dda(t_game *game, int x, double ray_dir_x, double ray_dir_y);
int		update_moves(t_game *game);

//TEXTURES
void	load_texture(t_game *game, t_img *tex, char *path);
int		get_tex_color(t_img *tex, int x, int y);
#endif

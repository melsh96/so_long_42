/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:02:15 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/09 22:40:34 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/get_next_line/get_next_line_bonus.h"
# include "../libft/includes_libft/libft.h"

# define MLX_ERROR				1

# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	03

# define KEY_ESC				65307
# define KEY_W					119
# define KEY_A					97
# define KEY_S					115
# define KEY_D					100

// # define NULL NULL

typedef enum e_bool
{
	true = 0,
	false = 1
}					t_bool;

typedef struct s_mlx
{
	void			*ptr;
	void			*window;
}					t_mlx;

typedef struct s_map
{
	char			**path;
	char			**visited_path;
	int				width;
	int				height;
	char			*last_wall;
	char			*first_wall;
}					t_map;

typedef struct s_img
{
	void			*ptr;
	int				width;
	int				height;
}					t_img;

typedef struct s_textures
{
	t_img			floor;
	t_img			obstacle;
	t_img			eleven_front;
	t_img			demogorgon_exp;
	t_img			demogorgon_insp;
	t_img			eggo;
	t_img			eggo_left;
	t_img			eggo_side;
	t_img			eggo_right;
	t_img			exit;
}					t_textures;

typedef struct s_count
{
	int				total_collectibles;
	int				collectibles;
	int				c_cpy;
	int				e_cpy;
	int				steps;
	int				exit;
	int				player;
}					t_count;

typedef struct s_player_pos
{
	int	pos_x;
	int	pos_y;
}	t_player_pos;

typedef struct s_param
{
	int				x;
	int				y;
	int				i;
	int				j;
	int				frame;
	t_mlx			mlx;
	t_map			map;
	t_img			img;
	t_textures		textures;
	t_count			count;
	t_player_pos	p_pos;
}					t_param;

void		check_params(t_param *param);
int			is_map_rectangular(t_param *param);
char		*top_walls(t_param *param);
char		*down_walls(t_param *param);
int			are_right_left_walls(t_param *param);
int			are_top_last_walls(t_param *param);
int			is_content_valid(t_param *param);
void		check_map(t_param *param, char *map_path);

void		param_init(t_param *param);
void		initialize_img(t_textures *textures, t_mlx *mlx, t_param *param);
void		init_player_pos(t_param *param);
void		initialize_game(t_param	*param, char *map_path);

void		texture_freezer(t_param *param, t_textures *tex);
int			quit(t_param *param);
int			read_lines(char *map_path);
char		**read_map(char *file, t_param *param);
void		get_map(char *file, t_param *param);

void		images_to_map(t_param *param);
int			check_arguments(char *av, char *c);
int			render(t_param *param);
int			main(int ac, char **av);

void		exit_win(t_param *param);
void		exit_lost(t_param *param);
void		find_player(t_param *param, char *map_path);
void		move_up(t_param *param);
void		move_down(t_param *param);
void		move_right(t_param *param);
void		move_left(t_param *param);
void		display_steps_on_screen(t_param *param);
int			key_press(int key_code, t_param *param);

void		free_walls(t_param *param);
void		read_free_all_gnl(char *tmp, int fd);
char		**read_visited_path(char *file, t_param *param);
void		get_visited_path(char *file, t_param *param);

void		freezer(char **tab);
void		print_map(t_param *param);
int			check_path(t_param *param, char *map_path);

void		which_textures_2(t_param *param, int i, int j);
void		which_textures_1(t_param *param, int i, int j);
void		print_visited_map(t_param *param);

#endif

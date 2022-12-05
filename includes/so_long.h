/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 18:02:15 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/06 00:20:21 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

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

typedef enum e_bool
{
	true = 0,
	false = 1
}			t_bool;

typedef struct	s_mlx
{
	void	*ptr;
	void	*window;
}			t_mlx;

typedef struct	s_map
{
	// int		col;
	// int		line;
	// char	*path;
	char	**path;
	int 	width;
	int 	height;
}			t_map;

typedef struct s_img
{
	void	*ptr;
	// int		*data;
	int 	width;
	int 	height;
}			t_img;

typedef struct	s_textures
{
	t_img	floor;
	t_img	obstacle;
	t_img	eleven_front;
	t_img	eleven_left;
	t_img	eleven_right;
	t_img	eleven_back;
	t_img	demogorgon_exp;
	t_img	demogorgon_insp;
	t_img	eggo;
	t_img	eggo_left;
	t_img	eggo_side;
	t_img	eggo_right;
	t_img	exit_2;
	t_img	exit;
}			t_textures;

typedef struct	s_count
{
	int		total_collectibles;
	int		collectibles;
	int		steps;
}				t_count;

typedef struct	s_param
{
	int			x;
	int			y;
	int			frame;
	t_mlx		mlx;
	t_map		map;
	t_img		img;
	t_textures	textures;
	t_count		count;
}				t_param;

int		main(int ac, char **av);
void	initialize_img(t_textures *textures, t_mlx *mlx);
char	*alloc_without_new_line(const char *s1);
char	*join_without_new_line(char *s1, char *s2);
int		press_key(int key_code, t_param *param);
void	move_left(t_param *param);
void	move_right(t_param *param);
void	move_down(t_param *param);
// void	move_up(t_map *map, t_count *count, t_mlx *mlx, t_textures *textures);
void	move_up(t_param *param);
void	initialize_game(t_param	*param, char *map_path);
int		quit(t_param *param);
void	param_init(t_param *param);
void	read_map(char *map_path, t_map *map);
// void	images_to_map(t_mlx *mlx, t_map *map, t_textures *textures);
void	images_to_map(t_param *param);
void	check_walls(t_map *map);
// void	check_params(t_map *map, t_count *count);
void	check_params(t_param *param);
void	check_map(t_param *param);
void	ft_my_mlx_string_put(t_param *param);
#endif

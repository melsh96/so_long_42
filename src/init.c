/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:04:23 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/09 22:39:43 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->i = 0;
	param->j = 0;
	param->frame = 0;
	param->count.steps = 0;
	param->count.collectibles = 0;
	param->count.exit = 0;
	param->count.player = 0;
	param->mlx.ptr = NULL;
	param->img.ptr = NULL;
	param->map.path = NULL;
	param->mlx.window = NULL;
	param->map.visited_path = NULL;
	param->textures.demogorgon_exp.ptr = NULL;
	param->textures.demogorgon_insp.ptr = NULL;
	param->textures.eggo.ptr = NULL;
	param->textures.eggo_left.ptr = NULL;
	param->textures.eggo_right.ptr = NULL;
	param->textures.eggo_side.ptr = NULL;
	param->textures.eleven_front.ptr = NULL;
	param->textures.exit.ptr = NULL;
	param->textures.floor.ptr = NULL;
	param->textures.obstacle.ptr = NULL;
}

void	initialize_img(t_textures *textures, t_mlx *mlx, t_param *param)
{
	int			i;
	int			fd;
	t_img		*image;
	static char	*files[] = {
		"./img/floor.xpm", "./img/obstacle.xpm", "./img/eleven_front.xpm",
		"./img/demo_exp.xpm", "./img/demo_insp.xpm", "./img/eggo.xpm",
		"./img/eggo_left.xpm", "./img/eggo_side.xpm", "./img/eggo_right.xpm",
		"./img/exit.xpm", NULL
	};

	fd = 0;
	i = -1;
	while (files[++i] != NULL)
	{
		fd = open(files[i], O_RDONLY);
		if (fd < 0 || check_arguments(files[i], ".xpm") != 0)
		{
			ft_putstr_fd("Error\nImage Problem\n", 2);
			quit(param);
		}
		close(fd);
		image = &((t_img *)textures)[i];
		image->ptr = mlx_xpm_file_to_image(mlx->ptr, files[i],
				&image->width, &image->height);
	}
}

// void	which_textures_2(t_param *param, int i, int j)
// {
// 	if (param->map.path[i][j] == 'P')
// 		mlx_put_image_to_window(param->mlx.ptr, param->mlx.window,
// 			param->textures.eleven_front.ptr, j * 64, i * 64);
// 	else if (param->map.path[i][j] == 'E')
// 		mlx_put_image_to_window(param->mlx.ptr,
// 			param->mlx.window, param->textures.exit.ptr, j * 64, i * 64);
// 	else if (param->map.path[i][j] == 'X' && param->frame < 200)
// 		mlx_put_image_to_window(param->mlx.ptr, param->mlx.window,
// 			param->textures.demogorgon_exp.ptr, j * 64, i * 64);
// 	else if (param->map.path[i][j] == 'X' && param->frame >= 200)
// 		mlx_put_image_to_window(param->mlx.ptr, param->mlx.window,
// 			param->textures.demogorgon_insp.ptr, j * 64, i * 64);
// 	else
// 		mlx_put_image_to_window(param->mlx.ptr, param->mlx.window,
// 			param->textures.floor.ptr, j * 64, i * 64);
// }

// void	which_textures_1(t_param *param, int i, int j)
// {
// 	if (param->map.path[i][j] == '1')
// 		mlx_put_image_to_window(param->mlx.ptr, param->mlx.window,
// 			param->textures.obstacle.ptr, j * 64, i * 64);
// 	else if (param->map.path[i][j] == 'C' && param->frame < 100)
// 		mlx_put_image_to_window(param->mlx.ptr,
// 			param->mlx.window, param->textures.eggo.ptr, j * 64, i * 64);
// 	else if (param->map.path[i][j] == 'C' && param->frame >= 100
// 		&& param->frame < 200)
// 		mlx_put_image_to_window(param->mlx.ptr,
// 			param->mlx.window, param->textures.eggo_right.ptr, j * 64, i * 64);
// 	else if (param->map.path[i][j] == 'C'
// 		&& param->frame >= 200 && param->frame < 300)
// 		mlx_put_image_to_window(param->mlx.ptr,
// 			param->mlx.window, param->textures.eggo_side.ptr, j * 64, i * 64);
// 	else if (param->map.path[i][j] == 'C'
// 		&& param->frame >= 300 && param->frame < 400)
// 		mlx_put_image_to_window(param->mlx.ptr,
// 			param->mlx.window, param->textures.eggo_left.ptr, j * 64, i * 64);
// 	else
// 		which_textures_2(param, i, j);
// }

void	images_to_map(t_param *param)
{
	int	i;
	int	j;

	i = -1;
	while (param->map.path[++i])
	{
		j = -1;
		while (param->map.path[i][++j])
			which_textures_1(param, i, j);
	}
}

void	init_player_pos(t_param *param)
{
	int	i_index;
	int	j_index;

	i_index = 0;
	while (param->map.path[i_index] != NULL)
	{
		j_index = 0;
		while (param->map.path[i_index][j_index])
		{
			if (param->map.path[i_index][j_index] == 'P')
				break ;
			j_index++;
		}
		if (j_index != param->map.width + 1)
			break ;
		i_index++;
	}
	param->p_pos.pos_x = i_index;
	param->p_pos.pos_y = j_index;
}

void	initialize_game(t_param	*param, char *file_path)
{
	param->mlx.ptr = mlx_init();
	if (!param->mlx.ptr)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	initialize_img(&param->textures, &param->mlx, param);
	get_map(file_path, param);
	init_player_pos(param);
	check_map(param, file_path);
	param->mlx.window = mlx_new_window(param->mlx.ptr, param->map.width * 64,
			param->map.height * 64, "so_long");
	images_to_map(param);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:04:23 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/08 18:31:23 by meshahrv         ###   ########.fr       */
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
	param->mlx.ptr = NULL;
	param->img.ptr = NULL;
	param->map.path = NULL;
	param->mlx.window = NULL;
}

void	initialize_img(t_textures *textures, t_mlx *mlx)
{
	int			i;
	int			fd;
	t_img		*image;
	static char	*files[] = {
		"./img/floor.xpm",
		"./img/obstacle.xpm",
		"./img/eleven_front.xpm",
		"./img/eleven_left.xpm",
		"./img/eleven_right.xpm",
		"./img/eleven_back.xpm",
		"./img/demo_exp.xpm",
		"./img/demo_insp.xpm",
		"./img/eggo.xpm",
		"./img/eggo_left.xpm",
		"./img/eggo_side.xpm",
		"./img/eggo_right.xpm",
		"./img/exit_2.xpm",
		"./img/exit.xpm",
		NULL
	};

	fd = 0;
	i = 0;
	while (files[i] != NULL)
	{
		fd = open(files[i], O_RDONLY);
		if (fd < 0 || check_arguments(files[i], ".xpm") != 0)
		{
			ft_putstr_fd("Error\nImage Problem\n", 2);
			exit(0);
		}
		close(fd);
		image = &((t_img *)textures)[i];
		image->ptr = mlx_xpm_file_to_image(mlx->ptr, files[i],
				&image->width, &image->height);
		i++;
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
				break;
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
	// t_map	map;

	// map.path = NULL;
	param->mlx.ptr = mlx_init();
	if (!param->mlx.ptr)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	initialize_img(&param->textures, &param->mlx);
	get_map(file_path, param);
	// if (map.path == NULL)
	// 	quit(param);
	init_player_pos(param);
	check_map(param, file_path);
	param->mlx.window = mlx_new_window(param->mlx.ptr, param->map.width * 64, param->map.height * 64, "so_long");
	images_to_map(param);
}

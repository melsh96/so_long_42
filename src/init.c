/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:04:23 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/05 22:47:52 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	param_init(t_param *param)
{
	param->x = 3;
	param->y = 4;
	param->count.steps = 0;
	param->mlx.ptr = NULL;
	param->mlx.window = NULL;
	param->map.path = NULL;
	param->img.ptr = NULL;
}

void	initialize_img(t_textures *textures, t_mlx *mlx)
{
	int			i;
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

	i = 0;
	while (files[i] != NULL)
	{
		image = &((t_img *)textures)[i];
		image->ptr = mlx_xpm_file_to_image(mlx->ptr, files[i],
				&image->width, &image->height);
		i++;
	}
}

void	initialize_game(t_param	*param, char *map_path)
{
	param->mlx.ptr = mlx_init();
	if (!param->mlx.ptr)
	{
		exit(0);
	}
	initialize_img(&param->textures, &param->mlx);
	read_map(map_path, &param->map);
	check_map(param);
	param->mlx.window = mlx_new_window(param->mlx.ptr, param->map.width * 64, param->map.height * 64, "so_long");
	images_to_map(param);
}

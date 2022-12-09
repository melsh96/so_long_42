/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:39:36 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/09 22:40:40 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	which_textures_2(t_param *param, int i, int j)
{
	if (param->map.path[i][j] == 'P')
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.window,
			param->textures.eleven_front.ptr, j * 64, i * 64);
	else if (param->map.path[i][j] == 'E')
		mlx_put_image_to_window(param->mlx.ptr,
			param->mlx.window, param->textures.exit.ptr, j * 64, i * 64);
	else if (param->map.path[i][j] == 'X' && param->frame < 200)
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.window,
			param->textures.demogorgon_exp.ptr, j * 64, i * 64);
	else if (param->map.path[i][j] == 'X' && param->frame >= 200)
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.window,
			param->textures.demogorgon_insp.ptr, j * 64, i * 64);
	else
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.window,
			param->textures.floor.ptr, j * 64, i * 64);
}

void	which_textures_1(t_param *param, int i, int j)
{
	if (param->map.path[i][j] == '1')
		mlx_put_image_to_window(param->mlx.ptr, param->mlx.window,
			param->textures.obstacle.ptr, j * 64, i * 64);
	else if (param->map.path[i][j] == 'C' && param->frame < 100)
		mlx_put_image_to_window(param->mlx.ptr,
			param->mlx.window, param->textures.eggo.ptr, j * 64, i * 64);
	else if (param->map.path[i][j] == 'C' && param->frame >= 100
		&& param->frame < 200)
		mlx_put_image_to_window(param->mlx.ptr,
			param->mlx.window, param->textures.eggo_right.ptr, j * 64, i * 64);
	else if (param->map.path[i][j] == 'C'
		&& param->frame >= 200 && param->frame < 300)
		mlx_put_image_to_window(param->mlx.ptr,
			param->mlx.window, param->textures.eggo_side.ptr, j * 64, i * 64);
	else if (param->map.path[i][j] == 'C'
		&& param->frame >= 300 && param->frame < 400)
		mlx_put_image_to_window(param->mlx.ptr,
			param->mlx.window, param->textures.eggo_left.ptr, j * 64, i * 64);
	else
		which_textures_2(param, i, j);
}

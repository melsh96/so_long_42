/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:32:11 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/08 19:42:31 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	freezer(char **tab)
{
	size_t	idx;

	idx = 0;
	while (tab[idx] != NULL)
	{
		free(tab[idx]);
		idx++;
	}
	free(tab);
}

void	texture_freezer(t_param *param, t_textures *tex)
{
	mlx_destroy_image(param->mlx.ptr, tex->floor.ptr);
	mlx_destroy_image(param->mlx.ptr, tex->obstacle.ptr);
	mlx_destroy_image(param->mlx.ptr, tex->eleven_front.ptr);
	mlx_destroy_image(param->mlx.ptr, tex->demogorgon_insp.ptr);
	mlx_destroy_image(param->mlx.ptr, tex->demogorgon_exp.ptr);
	mlx_destroy_image(param->mlx.ptr, tex->eggo.ptr);
	mlx_destroy_image(param->mlx.ptr, tex->eggo_left.ptr);
	mlx_destroy_image(param->mlx.ptr, tex->eggo_right.ptr);
	mlx_destroy_image(param->mlx.ptr, tex->eggo_side.ptr);
	mlx_destroy_image(param->mlx.ptr, tex->exit.ptr);
}

int	quit(t_param *param)
{
	if (param->map.path)
		freezer(param->map.path);
	texture_freezer(param, &param->textures);
	// if (param->img.ptr)
	// 	free(param->img.ptr);
	if (param->mlx.window && param->mlx.ptr)
		mlx_destroy_window(param->mlx.ptr, param->mlx.window);
	if (param->mlx.ptr)
	{
		mlx_destroy_display(param->mlx.ptr);
		free(param->mlx.ptr);
	}
	param->mlx.ptr = NULL;
	exit(0);
	return (0);
}

void	free_walls(t_param *param)
{
	if (param->map.first_wall != NULL)
		free(param->map.first_wall);
	if (param->map.last_wall != NULL)
		free(param->map.last_wall);
}

void	read_free_all_gnl(char *tmp, int fd)
{
	while (tmp != NULL)
	{
		free(tmp);
		tmp = get_next_line(fd);
	}
}

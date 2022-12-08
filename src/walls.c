/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:05:46 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/08 19:38:55 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_map_rectangular(t_param *param)
{
	int		i;
	char	*trimed;

	i = 0;
	while (i < param->map.height && param->map.path)
	{
		trimed = ft_strtrim((param->map.path)[i], "\n");
		if (param->map.width != (int)ft_strlen(trimed))
		{
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("Your map is not rectangular\n", 2);
			free(trimed);
			return (0);
		}
		free(trimed);
		i++;
	}
	return (1);
}

char	*top_walls(t_param *param)
{
	return (ft_strtrim((param->map.path)[0], "\n"));
}

char	*down_walls(t_param *param)
{
	int		total_lines;
	char	*last_wall;

	total_lines = param->map.height;
	if (param->map.path[total_lines] == NULL)
		total_lines = param->map.height - 1;
	last_wall = ft_strtrim((param->map.path)[total_lines], "\n");
	return (last_wall);
}

int	are_right_left_walls(t_param *param)
{
	int		i;
	int		j;

	i = 1;
	while (param->map.path[i])
	{
		j = 0;
		while (param->map.path[i][j])
		{
			if (param->map.path[i][0] != '1'
				|| param->map.path[i][param->map.width - 1] != '1')
			{
				ft_putstr_fd("Error\nYour map is not surrounded by walls\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	are_top_last_walls(t_param *param)
{
	int		i;
	int		j;

	i = 0;
	while (param->map.path[i])
	{
		j = 0;
		param->map.first_wall = top_walls(param);
		param->map.last_wall = down_walls(param);
		while (param->map.first_wall[j] && param->map.last_wall[j])
		{
			if ((param->map.first_wall[j] != '1')
				|| (param->map.last_wall[j] != '1'))
			{
				ft_putstr_fd("Error\nYour map is not surrounded by walls\n", 2);
				free_walls(param);
				return (0);
			}
			j++;
		}
		free_walls(param);
		i++;
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:55:21 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/08 19:50:51 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (map->path[i])
	{
		ft_putstr_fd(map->path[i], 2);
		i++;
	}
	ft_putchar_fd('\n', 2);
}

void	display_steps_on_screen(t_param *param)
{
	char	*str;

	str = ft_itoa(param->count.steps);
	mlx_string_put(param->mlx.ptr, param->mlx.window, 40, 50, 0xFFFFFF, str);
	free(str);
}

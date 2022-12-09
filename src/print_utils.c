/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:55:21 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/09 18:49:47 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_param *param)
{
	int	i;

	i = 0;
	while (param->map.path[i])
	{
		ft_putstr_fd(param->map.path[i], 2);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void	print_visited_map(t_param *param)
{
	int	i;

	i = 0;
	while (param->map.visited_path[i])
	{
		ft_putstr_fd(param->map.visited_path[i], 2);
		i++;
	}
	ft_putchar_fd('\n', 1);
}

void	display_steps_on_screen(t_param *param)
{
	char	*str;

	str = ft_itoa(param->count.steps);
	mlx_string_put(param->mlx.ptr, param->mlx.window, 40, 50, 0xFFFFFF, str);
	free(str);
}

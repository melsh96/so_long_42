/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:06:25 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/08 19:49:07 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	exit_win(t_param *param)
{
	param->count.steps++;
	ft_putstr_fd("Yeah ! You collected all collectible in ", 1);
	ft_putnbr_fd(param->count.steps, 1);
	ft_putstr_fd(" steps !\n", 1);
	quit(param);
}

void	exit_lost(t_param *param)
{
	param->count.steps++;
	ft_putstr_fd("You have been eaten by a Demogorgon !\n", 1);
	quit(param);
}

void	find_player(t_param *param, char *map_path)
{
	int	i_index;
	int	j_index;

	i_index = 0;
	(void)map_path;
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
}

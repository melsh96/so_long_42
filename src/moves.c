/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:09:00 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/08 19:49:03 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_up(t_param *param)
{
	int	i;
	int	j;

	i = param->p_pos.pos_x;
	j = param->p_pos.pos_y;
	if (param->map.path[i - 1][j] == 'C')
		param->count.collectibles++;
	if (param->map.path[i - 1][j] == 'E'
		&& param->count.total_collectibles == param->count.collectibles)
		exit_win(param);
	if (param->map.path[i - 1][j] == 'X')
		exit_lost(param);
	else if (param->map.path[i - 1][j] != '1'
		&& param->map.path[i - 1][j] != 'E' && param->map.path[i - 1][j] != 'X')
	{
		param->map.path[i][j] = '0';
		param->map.path[i - 1][j] = 'P';
		param->p_pos.pos_x = i - 1;
		param->p_pos.pos_y = j;
		param->count.steps++;
	}
}

void	move_down(t_param *param)
{
	int	i;
	int	j;

	i = param->p_pos.pos_x;
	j = param->p_pos.pos_y;
	if (param->map.path[i + 1][j] == 'C')
		param->count.collectibles++;
	if (param->map.path[i + 1][j] == 'E'
		&& param->count.total_collectibles == param->count.collectibles)
		exit_win(param);
	if (param->map.path[i + 1][j] == 'X')
		exit_lost(param);
	else if (param->map.path[i + 1][j] != '1'
		&& param->map.path[i + 1][j] != 'E' && param->map.path[i + 1][j] != 'X')
	{
		param->map.path[i][j] = '0';
		param->map.path[i + 1][j] = 'P';
		param->p_pos.pos_x = i + 1;
		param->p_pos.pos_y = j;
		param->count.steps++;
	}
}

void	move_right(t_param *param)
{
	int	i;
	int	j;

	i = param->p_pos.pos_x;
	j = param->p_pos.pos_y;
	if (param->map.path[i][j + 1] == 'C')
		param->count.collectibles++;
	if (param->map.path[i][j + 1] == 'E'
		&& param->count.total_collectibles == param->count.collectibles)
		exit_win(param);
	if (param->map.path[i][j + 1] == 'X')
		exit_lost(param);
	else if (param->map.path[i][j + 1] != '1'
		&& param->map.path[i][j + 1] != 'E' && param->map.path[i][j + 1] != 'X')
	{
		param->map.path[i][j] = '0';
		param->map.path[i][j + 1] = 'P';
		param->p_pos.pos_x = i;
		param->p_pos.pos_y = j + 1;
		param->count.steps++;
	}
}

void	move_left(t_param *param)
{
	int	i;
	int	j;

	i = param->p_pos.pos_x;
	j = param->p_pos.pos_y;
	if (param->map.path[i][j - 1] == 'C')
		param->count.collectibles++;
	if (param->map.path[i][j - 1] == 'E'
		&& param->count.total_collectibles == param->count.collectibles)
		exit_win(param);
	if (param->map.path[i][j - 1] == 'X')
		exit_lost(param);
	else if (param->map.path[i][j - 1] != '1'
		&& param->map.path[i][j - 1] != 'E' && param->map.path[i][j - 1] != 'X')
	{
		param->map.path[i][j] = '0';
		param->map.path[i][j - 1] = 'P';
		param->p_pos.pos_x = i;
		param->p_pos.pos_y = j - 1;
		param->count.steps++;
	}
}

int	key_press(int key_code, t_param *param)
{
	if (key_code == KEY_ESC)
		quit(param);
	else if (key_code == KEY_W)
		move_up(param);
	else if (key_code == KEY_A)
		move_left(param);
	else if (key_code == KEY_S)
		move_down(param);
	else if (key_code == KEY_D)
		move_right(param);
	return (0);
}

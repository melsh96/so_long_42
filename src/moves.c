/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:09:00 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/06 00:19:53 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	print_map(t_map *map)
{
	int i;
	
	i = 0;
	while (map->path[i])
	{
		ft_putstr_fd(map->path[i], 2);
		i++;
	}
	ft_putchar_fd('\n', 2);
}

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
	ft_putstr_fd("You have been eaten by a Demongorgon !\n", 1);
	quit(param);
}

void	move_up(t_param *param)
{
	int	i;
	int	j;
	
	i = 0;
	while (param->map.path[i])
	{
		j = 0;
		while (param->map.path[i][j])
		{
			if (param->map.path[i][j] == 'P')
				break;
			j++;
		}
		if (j != param->map.width + 1)
			break ;
		i++;
	}
	if (param->map.path[i - 1][j] == 'C')
		param->count.collectibles++;
	if (param->map.path[i - 1][j] == 'E' && param->count.total_collectibles == param->count.collectibles)
		exit_win(param);
	if (param->map.path[i - 1][j] == 'X')
		exit_lost(param);
	else if (param->map.path[i - 1][j] != '1' && param->map.path[i - 1][j] != 'E' && param->map.path[i - 1][j] != 'X')
	{
		param->map.path[i][j] = '0';
		param->map.path[i - 1][j] = 'P';
		param->count.steps++;
		ft_putnbr_fd(param->count.steps, 1);
		ft_putchar_fd('\n', 1);
		
		// images_to_map(param->mlx, param->map, param->textures);
		// images_to_map(param);
	}
	
}

void	move_down(t_param *param)
{
	int	i;
	int	j;
	
	i = 0;
	while (param->map.path[i])
	{
		j = 0;
		while (param->map.path[i][j])
		{
			if (param->map.path[i][j] == 'P')
				break;
			j++;
		}
		if (j != param->map.width + 1)
			break ;
		i++;
	}
	if (param->map.path[i + 1][j] == 'C')
		param->count.collectibles++;
	if (param->map.path[i + 1][j] == 'E' && param->count.total_collectibles == param->count.collectibles)
		exit_win(param);
	if (param->map.path[i + 1][j] == 'X')
		exit_lost(param);
	else if (param->map.path[i + 1][j] != '1' && param->map.path[i + 1][j] != 'E' && param->map.path[i + 1][j] != 'X')
	{
		param->map.path[i][j] = '0';
		param->map.path[i + 1][j] = 'P';
		param->count.steps++;
		ft_putnbr_fd(param->count.steps, 1);
		ft_putchar_fd('\n', 1);
		// images_to_map(param);
	}
}

void	move_right(t_param *param)
{
	int	i;
	int	j;
	
	i = 0;
	while (param->map.path[i])
	{
		j = 0;
		while (param->map.path[i][j])
		{
			if (param->map.path[i][j] == 'P')
				break;
			j++;
		}
		if (j != param->map.width + 1)
			break ;
		i++;
	}
	if (param->map.path[i][j + 1] == 'C')
		param->count.collectibles++;
	if (param->map.path[i][j + 1] == 'E' && param->count.total_collectibles == param->count.collectibles)
		exit_win(param);
	if (param->map.path[i][j + 1] == 'X')
		exit_lost(param);
	else if (param->map.path[i][j + 1] != '1' && param->map.path[i][j + 1] != 'E' && param->map.path[i][j + 1] != 'X')
	{
		param->map.path[i][j] = '0';
		param->map.path[i][j + 1] = 'P';
		param->count.steps++;
		ft_putnbr_fd(param->count.steps, 1);
		ft_putchar_fd('\n', 1);
		// images_to_map(param);
	}
}

void	move_left(t_param *param)
{
	int	i;
	int	j;
	
	i = 0;
	while (param->map.path[i])
	{
		j = 0;
		while (param->map.path[i][j])
		{
			if (param->map.path[i][j] == 'P')
				break ;
			j++;
		}
		if (j != param->map.width + 1)
			break ;
		i++;
	}
	if (param->map.path[i][j - 1] == 'C')
		param->count.collectibles++;
	if (param->map.path[i][j - 1] == 'E' && param->count.total_collectibles == param->count.collectibles)
		exit_win(param);
	if (param->map.path[i][j - 1] == 'X')
		exit_lost(param);
	else if (param->map.path[i][j - 1] != '1' && param->map.path[i][j - 1] != 'E' && param->map.path[i][j - 1] != 'X')
	{
		param->map.path[i][j] = '0';
		param->map.path[i][j- 1] = 'P';
		param->count.steps++;
		ft_putnbr_fd(param->count.steps, 1);
		ft_putchar_fd('\n', 1);
		// images_to_map(param);
	}
}

void	ft_my_mlx_string_put(t_param *param)
{
	char	*str;

	str = ft_itoa(param->count.steps);
	mlx_string_put(param->mlx.ptr, param->mlx.window, 40, 50, 0xFFFFFF, str);
	free(str);
}

int	press_key(int key_code, t_param *param)
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
	print_map(&param->map);
	return (0);
}

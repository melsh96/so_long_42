/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:35:37 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/09 22:38:55 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_player_stuck(t_param *param, int pos_x, int pos_y)
{
	if (param->map.visited_path[pos_x][pos_y - 1] == '1' &&
		param->map.visited_path[pos_x - 1][pos_y] == '1' &&
		param->map.visited_path[pos_x][pos_y + 1] == '1' &&
		param->map.visited_path[pos_x + 1][pos_y] == '1')
	{
		return (0);
	}
	return (1);
}

int	player_is_not_stuck(t_param *param, int pos_x, int pos_y)
{
	if (param->map.visited_path[pos_x][pos_y] == 'E'
		|| param->map.visited_path[pos_x][pos_y] == 'X'
		|| param->map.visited_path[pos_x][pos_y] == '1')
	{
		if (param->map.visited_path[pos_x][pos_y] == 'E')
			param->count.e_cpy--;
		return (1);
	}
	if (param->map.visited_path[pos_x][pos_y] == 'C')
		param->count.c_cpy--;
	return (0);
}

void	check_move(t_param *param, int pos_x, int pos_y)
{
	param->map.visited_path[pos_x][pos_y] = '1';
	if (!is_player_stuck(param, pos_x, pos_y))
		return ;
	if (player_is_not_stuck(param, pos_x, pos_y - 1) == 0)
		check_move(param, pos_x, pos_y - 1);
	if (player_is_not_stuck(param, pos_x - 1, pos_y) == 0)
		check_move(param, pos_x - 1, pos_y);
	if (player_is_not_stuck(param, pos_x, pos_y + 1) == 0)
		check_move(param, pos_x, pos_y + 1);
	if (player_is_not_stuck(param, pos_x + 1, pos_y) == 0)
		check_move(param, pos_x + 1, pos_y);
}

int	check_path(t_param *param, char *map_path)
{
	param->map.visited_path = read_visited_path(map_path, param);
	if (param->map.visited_path == NULL)
		return (0);
	param->count.c_cpy = param->count.total_collectibles;
	param->count.e_cpy = param->count.exit;
	check_move(param, param->p_pos.pos_x, param->p_pos.pos_y);
	if (param->count.c_cpy != 0)
	{
		ft_putstr_fd("Error\nCan't reach every collectibles\n", 2);
		quit(param);
	}
	if (param->count.e_cpy > 0)
	{
		ft_putstr_fd("Error\nCan't exit\n", 2);
		quit(param);
	}
	return (1);
}

char	**read_visited_path(char *file, t_param *param)
{
	char	**visited_path;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr_fd("Error\nFail to open file\n", 2);
		quit(param);
	}
	visited_path = (char **)malloc(sizeof(char *) * (param->map.height + 1));
	if (visited_path == NULL || fd == -1)
		exit (0);
	while (1)
	{
		visited_path[i] = get_next_line(fd);
		if (visited_path[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	return (visited_path);
}

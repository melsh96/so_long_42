/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:01:44 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/08 19:54:38 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	count_textures(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	param->count.exit = 0;
	param->count.player = 0;
	param->count.collectibles = 0;
	while (param->map.path[i])
	{
		j = 0;
		while (param->map.path[i][j])
		{
			if (param->map.path[i][j] == 'E')
				param->count.exit++;
			else if (param->map.path[i][j] == 'P')
				param->count.player++;
			else if (param->map.path[i][j] == 'C')
				param->count.collectibles++;
			j++;
		}
		i++;
	}
	param->count.total_collectibles = param->count.collectibles;
	param->count.collectibles = 0;
}

void	check_params(t_param *param)
{
	count_textures(param);
	if (param->count.exit == 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("This map has no exit, put only one !\n", 2);
		exit(0);
	}
	else if (param->count.exit != 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("Ther is too many exits !\n", 2);
		exit(0);
	}
	else if (param->count.total_collectibles == 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("This map has no collectibles, put at least one !\n", 2);
		exit(0);
	}
	else if (param->count.player != 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("No or too much player has been detected ...\n", 2);
		exit(0);
	}
}

int	is_content_valid(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	while (param->map.path[i])
	{
		j = 0;
		while (param->map.path[i][j] && j < param->map.width - 1)
		{
			if ((param->map.path[i][j] != '1') && (param->map.path[i][j] != '0')
					&& (param->map.path[i][j] != 'E')
					&& (param->map.path[i][j] != 'P')
					&& (param->map.path[i][j] != 'C')
					&& (param->map.path[i][j] != 'X'))
			{
				ft_putstr_fd("Error\nInvalid caracter\n", 2);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

void	check_map(t_param *param, char *map_path)
{
	if (!is_map_rectangular(param))
		quit(param);
	if (!are_top_last_walls(param))
		quit(param);
	if (!are_right_left_walls(param))
		quit(param);
	if (!is_content_valid(param))
		quit(param);
	find_player(param, map_path);
	check_params(param);
}

	// if (!path_finding(param, map_path))
	// 	quit(param);

int	check_arguments(char *av, char *c)
{
	int		fd;
	int		len;
	char	*tmp;

	tmp = NULL;
	len = ft_strlen(av) - 1;
	if (len < 4)
		return (1);
	if (ft_strncmp(av + (len - 3), c, 5) != 0)
		return (1);
	fd = open(av, __O_DIRECTORY);
	if (fd >= 0)
		return (close(fd), 1);
	fd = open(av, O_RDONLY);
	if (fd < 0)
		return (1);
	tmp = get_next_line(fd);
	if (tmp == NULL)
		return (close(fd), 1);
	else
		read_free_all_gnl(tmp, fd);
	tmp = NULL;
	close(fd);
	return (0);
}

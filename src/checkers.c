/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:01:44 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/08 19:50:22 by meshahrv         ###   ########.fr       */
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

// int	check_path(t_param *param, char *map_path)
// {
// 	param->map.path = NULL;
// 	param->map.visited_path = NULL;
// 	get_map(map_path, param);
// 	get_visited_path(map_path, param);
// 	path.map = get_map(argv, path.map, vars.map.nb_ligne);
// 	path.visited = get_map(argv, path.visited, vars.map.nb_ligne);
// 	if (path.map == NULL || path.visited == NULL)
// 		return (1);
// 	path.count_c = vars.map.count_c;
// 	path.count_e = vars.map.count_e;
// 	path.nb_ligne = vars.map.nb_ligne;
// 	path.size_line = vars.map.size_line;
// 	find_player(&path);
// 	if (try_find_paths(&path) == 1)
// 		return (clean_map(path.map), clean_map(path.visited), 1);
// 	return (clean_map(path.map), clean_map(path.visited), 0);
// }

// int	try_find_paths(t_path *path)
// {
// 	while (path->count_c > 0)
// 	{
// 		erase_map(&path->visited);
// 		if (find_path_c(path, path->start.y, path->start.x) == 0)
// 			path->count_c--;
// 		else
// 			return (1);
// 	}
// 	while (path->count_e > 0)
// 	{
// 		erase_map(&path->visited);
// 		if (find_path_e(path, path->start.y, path->start.x) == 0)
// 			path->count_e--;
// 		else
// 			return (1);
// 	}
// 	return (0);
// }

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

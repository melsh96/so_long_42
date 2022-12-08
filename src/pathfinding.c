/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:35:37 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/08 20:49:32 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_path(t_param *param, char *map_path)
{
	t_map	*map;

	map->path = NULL;
	map->visited_path = NULL;
	map->path = read_map(map_path, param);
	map->visited_path = read_visited_path(map_path, param);
	if (map->path == NULL || map->visited_path == NULL)
		return (1);
	find_player(map, map_path);
	if (try_find_paths(map) == 1)
	{
		freezer(map->path);
		freezer(map->visited_path);
		return (1);
	}
	freezer(map->path);
	freezer(map->visited_path);
	return (0);
}

void	free_map(char ***map_fill)
{
	int	i;
	int	j;

	i = 0;
	while ((*map_fill)[i])
	{
		j = 1;
		while ((*map_fill)[i][j])
		{
			if ((*map_fill)[i][j] != '1' && (*map_fill)[i][j] != '\n')
				(*map_fill)[i][j] = '0';
			j++;
		}
		i++;
	}
}

// int	try_find_paths(t_param *param)
// {
// 	while (param->count.collectibles > 0)
// 	{
// 		free_map(path->visited);
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

void	get_visited_path(char *file, t_param *param)
{
	char	**visited_path;

	param->map.height = read_lines(file);
	if (param->map.height == -1)
	{
		ft_putstr_fd("Error\n", 2);
		quit(param);
	}
	visited_path = read_map(file, param);
	param->map.width = (int)ft_strlen((visited_path)[0]) - 1;
	param->map.visited_path = visited_path;
}

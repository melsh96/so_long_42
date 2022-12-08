/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:57:09 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/08 20:01:02 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	read_lines(char *map_path)
{
	int		fd;
	char	*line;
	int		count_line;

	count_line = 0;
	fd = open(map_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("Error\nFail to open file\n", 2);
		exit(0);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (line == 0)
			break ;
		count_line++;
		free(line);
	}
	close(fd);
	free(line);
	return (count_line);
}

char	**read_map(char *file, t_param *param)
{
	char	**map_path;
	int		fd;
	int		i;

	i = 0;
	fd = open(file, O_RDONLY);
	if (fd <= 0)
	{
		ft_putstr_fd("Error\nFail to open file\n", 2);
		quit(param);
	}
	map_path = (char **)malloc(sizeof(char *) * (param->map.height + 1));
	if (map_path == NULL || fd == -1)
		exit (0);
	while (1)
	{
		map_path[i] = get_next_line(fd);
		if (map_path[i] == NULL)
			break ;
		i++;
	}
	close(fd);
	return (map_path);
}

void	get_map(char *file, t_param *param)
{
	char	**map_path;

	param->map.height = read_lines(file);
	if (param->map.height == -1)
	{
		ft_putstr_fd("Error\n", 2);
		quit(param);
	}
	map_path = read_map(file, param);
	param->map.width = (int)ft_strlen((map_path)[0]) - 1;
	param->map.path = map_path;
}

	// visiter verifier
	//free map
	//si le check il est bon bah on recree
	//sinon renvoie une erreur

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
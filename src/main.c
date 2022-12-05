/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:58:41 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/05 22:52:42 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// int		mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y, int color, char *string);

static void	freezer(char **tab)
{
	size_t	idx;

	idx = 0;
	while (tab[idx] != NULL)
	{
		free(tab[idx]);
		idx++;
	}
	free(tab);
}

void	texture_freezer(t_param *param, t_textures *tex)
{
	if (tex->floor.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->floor.ptr);
	if (tex->obstacle.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->obstacle.ptr);
	if (tex->eleven_front.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->eleven_front.ptr);
	if (tex->eleven_right.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->eleven_right.ptr);
	if (tex->eleven_left.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->eleven_left.ptr);
	if (tex->eleven_back.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->eleven_back.ptr);
	if (tex->demogorgon_insp.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->demogorgon_insp.ptr);
	if (tex->demogorgon_exp.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->demogorgon_exp.ptr);
	if (tex->eggo.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->eggo.ptr);
	if (tex->eggo_left.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->eggo_left.ptr);
	if (tex->eggo_right.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->eggo_right.ptr);
	if (tex->eggo_side.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->eggo_side.ptr);
	if (tex->exit.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->exit.ptr);
	if (tex->exit_2.ptr)
		mlx_destroy_image(param->mlx.ptr, tex->exit_2.ptr);
}

int	quit(t_param *param)
{
	// mlx_loop_end(param->mlx.ptr);
	if (param->mlx.window && param->mlx.ptr)
		mlx_destroy_window(param->mlx.ptr, param->mlx.window);
	if (param->map.path)
		freezer(param->map.path);
	if (param->img.ptr)
	{
		free(param->img.ptr);
	}
	texture_freezer(param, &param->textures);
	mlx_destroy_display(param->mlx.ptr);
	free(param->mlx.ptr);
	exit(EXIT_SUCCESS);
	return (EXIT_SUCCESS);
}



void	read_map(char *map_path, t_map *map)
{
	int		fd;
	char	*line;
	int		count_line;
	int		i;

	i = 0;
	count_line = 0;
	fd = open(map_path, O_RDONLY);
	if (fd <= 0)
		exit(0);
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
	fd = open(map_path, O_RDONLY);
	if (fd <= 0)
		ft_putstr_fd("Fail to open file\n", 2);
	map->path = malloc(sizeof(char *) * (count_line + 1));
	while (1)
	{
		map->path[i] = get_next_line(fd);
		if (map->path[i] == NULL)
			break;
		i++;
	}
	// map->path[count_line] = ft_strjoin(map->path[count_line], "\n");
	close(fd);

	map->height = count_line;
	if (map->height == -1)
	{
		ft_putstr_fd("Error\n", 2);
		exit(0);
	}
	map->width = (int)ft_strlen((map->path)[0]) - 1;
}

void	images_to_map(t_param *param)
{
	int	i;
	int	j;

	i = 0;
	while (param->map.path[i])
	{
		j = 0;
		while (param->map.path[i][j])
		{
			if (param->map.path[i][j] == '1')
				mlx_put_image_to_window(param->mlx.ptr, param->mlx.window, param->textures.obstacle.ptr, j * 64, i * 64);
			else if (param->map.path[i][j] == 'C')
				mlx_put_image_to_window(param->mlx.ptr, param->mlx.window, param->textures.eggo.ptr, j * 64, i * 64);
			else if (param->map.path[i][j] == 'P')
				mlx_put_image_to_window(param->mlx.ptr, param->mlx.window, param->textures.eleven_front.ptr, j * 64, i * 64);
			else if (param->map.path[i][j] == 'E')
				mlx_put_image_to_window(param->mlx.ptr, param->mlx.window, param->textures.exit.ptr, j * 64, i * 64);
			else if (param->map.path[i][j] == 'X' && param->frame < 200)
				mlx_put_image_to_window(param->mlx.ptr, param->mlx.window, param->textures.demogorgon_exp.ptr, j * 64, i * 64);
			else if (param->map.path[i][j] == 'X' && param->frame >= 200)
				mlx_put_image_to_window(param->mlx.ptr, param->mlx.window, param->textures.demogorgon_insp.ptr, j * 64, i * 64);
			else
				mlx_put_image_to_window(param->mlx.ptr, param->mlx.window, param->textures.floor.ptr, j * 64, i * 64);
			j++;
		}
		i++;
	}
}

// t_bool	blabla(t_param *param)
// {
// 	// t_bool test;

// 	// test = true;
// 	return (true);
// }

int	check_arguments(char *av)
{
	char	*map_file;

	map_file = ft_strrchr(av, '.');
	if (map_file == NULL || ft_strncmp(map_file, ".ber", 5) != 0 || *map_file == *av)
		return (1);
	return (0);
}

int	render(t_param *param)
{
	param->frame++;
	if ((param->frame % 500 / 400) == 1)
		param->frame = 0;
	images_to_map(param);
	return (0);
}

int	main(int ac, char **av)
{
	t_param		param;

	param.frame = 0;
	if (ac != 2 || !av[1] || check_arguments(av[1]) != 0)
	{
		ft_putstr_fd("Error :\nMissing Map !\n", 2);
		exit(0);
	}
	param_init(&param);
	initialize_game(&param, av[1]);

	if (param.mlx.window == NULL)
	{
		free(param.mlx.window);
		return (MLX_ERROR);
	}
	mlx_hook(param.mlx.window, X_EVENT_KEY_PRESS, 1L << 0, &press_key, &param);
	mlx_loop_hook(param.mlx.ptr, &render, &param);
	mlx_hook(param.mlx.window, 17, 1L << 17, &quit, &param);
	mlx_loop(param.mlx.ptr);
	return (0);
}

// TODO : is a valid parameter
/*
1. ac != 2 etc.. // *[OK]* //
2. file extension // *[OK]* //
3. check map is not a directory // *[OK]* //
*/

// TODO : is valid map
/*
1. map_is rectangular // *[OK]* //
2. map is surrounded by walls // *[OK]* //
3. check caracters is valid // *[OK]* //
*/

// TODO : pathfinding
/*
1. create path structure + initialize NULL
2. create a visited array + init NULL
3. map->path = read_map(map_file(av[1]), map->path);
4. map->visited = read_map(map_file, map->visited_path);
5. itterate throught all map to find the amout of exits and collectibles
6. find players location
7. if number of collectible is more than 0, 
find a path to get them all using directions ups down left right
without touching X or 1, ervery collectibles will become floors (0);
8. do the same process for exits.
*/

// TODO : LEAKS  
// ![NOT DONE]! //

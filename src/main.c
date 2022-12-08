/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:58:41 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/08 18:38:52 by meshahrv         ###   ########.fr       */
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
	char **map_path;
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

// void	get_visited_path(char **visited_path, t_param *param){
	
// }

// void	get_visited_path(char *map_path, char **visited_path,t_param *param)
// {
// 	param->map.height = read_lines(map_path);
// 	if (param->map.height == -1)
// 	{
// 		ft_putstr_fd("Error\n", 2);
// 		quit(param);
// 	}
// 	read_map(map_path, param);
// 	param->map.width = (int)ft_strlen((param->map.path)[0]) - 1;
// }

void	get_map(char *file, t_param *param)
{
	char **map_path;

	param->map.height = read_lines(file);
	if (param->map.height == -1)
	{
		ft_putstr_fd("Error\n", 2);
		quit(param);
	}
	map_path = read_map(file, param);
	// visiter verifier
	//free map
	//si le check il est bon bah on recree
	//sinon renvoie une erreur
	param->map.width = (int)ft_strlen((map_path)[0]) - 1;
	param->map.path = map_path;
	// param->map.width = (int)ft_strlen((param->map.path)[0]) - 1;
	// return (map_path);
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
			else if (param->map.path[i][j] == 'C' && param->frame < 100)
				mlx_put_image_to_window(param->mlx.ptr, param->mlx.window, param->textures.eggo.ptr, j * 64, i * 64);
			else if (param->map.path[i][j] == 'C' && param->frame >= 100 && param->frame < 200)
				mlx_put_image_to_window(param->mlx.ptr, param->mlx.window, param->textures.eggo_right.ptr, j * 64, i * 64);
			else if (param->map.path[i][j] == 'C' && param->frame >= 200 && param->frame < 300)
				mlx_put_image_to_window(param->mlx.ptr, param->mlx.window, param->textures.eggo_side.ptr, j * 64, i * 64);
			else if (param->map.path[i][j] == 'C' && param->frame >= 300 && param->frame < 400)
				mlx_put_image_to_window(param->mlx.ptr, param->mlx.window, param->textures.eggo_left.ptr, j * 64, i * 64);
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
	// display_steps_on_screen(param);
}

// t_bool	blabla(t_param *param)
// {
// 	// t_bool test;

// 	// test = true;
// 	return (true);
// }



int	render(t_param *param)
{
	param->frame++;
	if ((param->frame % 500 / 400) == 1)
		param->frame = 0;
	images_to_map(param);
	display_steps_on_screen(param);
	return (0);
}

int	main(int ac, char **av)
{
	t_param		param;

	param_init(&param);
	if (ac != 2 || !av[1] || check_arguments(av[1], ".ber") != 0)
	{
		ft_putstr_fd("Error :\nMissing Map !\n", 2);
		exit(0);
	}
	initialize_game(&param, av[1]);
	if (param.mlx.window == NULL)
	{
		free(param.mlx.window);
		return (MLX_ERROR);
	}
	mlx_hook(param.mlx.window, X_EVENT_KEY_PRESS, 1L << 0, &key_press, &param);
	mlx_loop_hook(param.mlx.ptr, &render, &param);
	mlx_hook(param.mlx.window, 17, 1L << 17, &quit, &param);
	mlx_loop(param.mlx.ptr);
	return (0);
}





// TODO : is a valid parameter
/*
1. ac != 2 etc.. 				// *[OK]* //
2. file extension 				// *[OK]* //
3. check map is not a directory // *[OK]* //
*/

// TODO : is valid map
/*
1. map_is rectangular 			// *[OK]* //
2. map is surrounded by walls 	// *[OK]* //
3. check caracters is valid 	// *[OK]* //
*/

// TODO : LEAKS  
/* 
1. quand exit : 4 leaks 		// *[OK]* //
*/

// TODO : pathfinding
/*
1. create path structure + initialize NULL
2. create a visited array + init NULL
3. map->path = read_map(map_file(av[1]), map->path);
4. map->visited = read_map(map_file, map->visited_path);
5. itterate throught all map to find the amount of exits and collectibles
6. find players location
7. if number of collectible is more than 0, 
find a path to get them all using directions ups down left right
without touching X or 1, ervery collectibles will become floors (0);
8. do the same process for exits.
*/

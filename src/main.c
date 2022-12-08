/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 17:58:41 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/08 19:20:48 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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

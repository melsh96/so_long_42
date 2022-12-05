/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: meshahrv <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 15:01:44 by meshahrv          #+#    #+#             */
/*   Updated: 2022/12/05 20:36:49 by meshahrv         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_params(t_param *param)
{
	int	i;
	int	j;
	int	n_exit;
	int	n_player;
	
	i = 0;
	n_exit = 0;
	n_player = 0;
	param->count.collectibles = 0;
	while (param->map.path[i])
	{
		j = 0;
		while (param->map.path[i][j])
		{
			if (param->map.path[i][j] == 'E')
				n_exit++;
			else if (param->map.path[i][j] == 'P')
				n_player++;
			else if (param->map.path[i][j] == 'C')
				param->count.collectibles++;
			j++;
		}
		i++;
	}
	// printf("total: %d\n", param->count.collectibles);
	param->count.total_collectibles = param->count.collectibles;
	param->count.collectibles = 0;

	if (n_exit == 0)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("This map has no exit, put only one !\n", 2);
		exit(0);
	}
	else if (n_exit != 1)
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
	else if (n_player != 1)
	{
		ft_putstr_fd("Error\n", 2);
		ft_putstr_fd("No or too much player has been detected ...\n", 2);
		exit(0);
	}
}

int	is_map_rectangular(t_param *param)
{
	int i;
	char *trimed;

	i = 0;
	while (i < param->map.height && param->map.path)
	{
		trimed = ft_strtrim((param->map.path)[i], "\n");
		if (param->map.width != (int)ft_strlen(trimed))
		{
			// printf("%d", param->map.width);
			ft_putstr_fd("Error\n", 2);
			ft_putstr_fd("Your map is not rectangular\n", 2);
			free(trimed);
			return(0);
		}
		free(trimed);
		i++;
	}
	return (1);
}

char *top_walls(t_param *param)
{
	return (ft_strtrim((param->map.path)[0], "\n"));
}

char *down_walls(t_param *param)
{
	int		total_lines;
	char 	*last_wall;

	total_lines = param->map.height;
	if (param->map.path[total_lines] == NULL)
		total_lines = param->map.height - 1;
	last_wall = ft_strtrim((param->map.path)[total_lines], "\n");
	return (last_wall);
}

int	are_right_left_walls(t_param *param)
{
	int		i;
	int		j;
	// char 	*last_wall;
	
	i = 1;
	while (param->map.path[i])
	{
		j = 0;
		while (param->map.path[i][j])
		{
			// last_wall = down_walls(param);
			if (param->map.path[i][0] != '1' || param->map.path[i][param->map.width - 1] != '1')
			{
				ft_putstr_fd("Error\nYour map is not surrounded by walls\n", 2);
				return(0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int are_top_last_walls(t_param *param)
{
	int		i;
	int		j;
	char 	*last_wall;
	char 	*first_wall;
	
	i = 0;
	while (param->map.path[i])
	{
		j = 0;
		first_wall = top_walls(param);
		last_wall = down_walls(param);
		while(first_wall[j] && last_wall[j])
		{
			if ((first_wall[j] != '1') || (last_wall[j] != '1'))
			{
				ft_putstr_fd("Error\nYour map is not surrounded by walls\n", 2);
				if (first_wall != NULL)
					free(first_wall);
				if (last_wall != NULL)
					free(last_wall);
				return(0);
			}
			j++;
		}
		if (first_wall != NULL)
			free(first_wall);
		if (last_wall != NULL)
			free(last_wall);
		i++;
	}
	return (1);
}

int is_content_valid(t_param *param)
{
	int i;
	int j;

	i = 0;
	while (param->map.path[i])
	{
		j = 0;
		while (param->map.path[i][j] && j < param->map.width - 1)
		{
			if ((param->map.path[i][j] != '1') && (param->map.path[i][j] != '0') && (param->map.path[i][j] != 'E') && (param->map.path[i][j] != 'P') && (param->map.path[i][j] != 'C') && (param->map.path[i][j] != 'X'))
			{
				ft_putstr_fd("Error\nInvalid caracter\n", 2);
				return (0);
			}
			j++;
		}
			printf("Here\n");
		i++;
	}
	return (1);
}

void	check_map(t_param *param)
{
	if (!is_map_rectangular(param))
		quit(param);
	if (!are_top_last_walls(param))
		quit(param);
	if (!are_right_left_walls(param))
		quit(param);
	if (!is_content_valid(param))
		quit(param);
	// check_walls(&param->map);
	check_params(param);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 09:55:33 by nmohd-ed          #+#    #+#             */
/*   Updated: 2025/03/17 11:07:03 by nmohd-ed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void	validate_arguments(int argc, char *argv[])
{
	int		len;

	if (argc != 2)
		error_exit("Invalid argument count");
	len = ft_strlen(argv[1]);
	if (len < 4 || ft_strncmp((argv[1] + (len - 4)), ".fdf", 4))
		error_exit("Invalid file format");
}

void	parse_line(char *line, t_data *map, int y)
{
	char	**split;
	int		x;

	split = ft_split(line, ' ');
	if (!split || !*split)
		handle_split_error(line, split, map);
	x = -1;
	while (++x < map->width)
	{
		map->z_matrix[y][x] = ft_atoi(split[x]); 
		// map->colour[y][x] = parse_colour(split[x], map);
		// printf("z_matrix[%d][%d] = %d\n", y, x, map->z_matrix[y][x]);
	}
	free_argument(split);
	free(line);
}

void	map_mem_alloc(t_data *map)
{
	int	i;

	map->z_matrix = (int **)ft_calloc(map->height, sizeof(int *));
	//map->colour = (int **)ft_calloc(map->height, sizeof(int *));
	if (!map->z_matrix) //|| !map->colour)
	{
		free(map);
		error_exit("Memory allocation for array failed");
	}
	i = -1;
	while (++i < map->height)
	{
		map->z_matrix[i] = (int *)ft_calloc(map->width, sizeof(int));
		//map->colour[i] = (int *)ft_calloc(map->width, sizeof(int));
		if (!map->z_matrix[i])// || !map->colour[i])
		{
			free(map);
			error_exit("Memory allocation for index failed");
		}
	}
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 13:16:59 by nmohd-ed          #+#    #+#             */
/*   Updated: 2025/03/17 11:05:53 by nmohd-ed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

t_data	*init_map(char *file_name)
{
	int		fd;
	t_data	*map;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit("Cannot open file");
	map = (t_data *)ft_calloc(1, sizeof(t_data));
	if (!map)
		error_exit("Map allocation failed");
	get_map_dimensions(fd, map);
	close(fd);
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		error_exit("Cannot open file for parsing");
	pars_val_map(fd, map);
	close(fd);
	return (map);
}

void	process_line(char *line, t_data *map)
{
	char	**split;
	int		i;

	split = ft_split(line, ' ');
	if(!split || !*split)
		handle_split_error(line, split, map);
	if (map->height == 0)
	{
		i = 0;
		while (split[i])
			i++;
		map->width = i;
	}
	map->height++;
	free(line);
	free_argument(split);
}

void	get_map_dimensions(int fd, t_data *map)
{
	char	*line;
	
	map->height = 0;
	map->width = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		process_line(line, map);
		line = get_next_line(fd);
	}
	if (map->height == 0 || map-> width == 0)
		error_exit("Empty file or invalid map dimensions");
}

void	pars_val_map(int fd, t_data *map)
{
	int		y;
	char	*line;

	y = -1;
	map_mem_alloc(map);
	while (++y < map->height)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free_map(map);
			error_exit("Failed to read line");
		}
		parse_line(line, map, y);
	}
}


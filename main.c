/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:13:17 by nmohd-ed          #+#    #+#             */
/*   Updated: 2025/03/14 13:32:27 by nmohd-ed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>
#include <stdio.h>

int		deal_key(int key, t_map *map)
{
	if (key == 65307)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	else if (key == 65451 || key == 61)
	{
		map->zoom +=2;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
	}
	else if (key == 65453 || key == 45)
	{
		if (map->zoom > 2)
			map->zoom -= 2;
		mlx_clear_window(map->mlx_ptr, map->win_ptr);
		draw_map(map);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map	*map;

	validate_arguments(argc, argv);
	map = init_map(argv[1]);
	if (!map)
		error_exit("Failed to initialized map");
	// printf("Map dimensions: width=%d, height=%d\n", map->width, map->height);
	map->mlx_ptr = mlx_init();
	// printf("Initializing window...\n");//debugging
	map->win_ptr = mlx_new_window(map->mlx_ptr, 1000, 1000, "FDF");
	if (!map->win_ptr)
		error_exit("Failed to create window");
	printf("Window created successfully.\n");
	map->img.img = mlx_new_image(map->mlx_ptr,1000, 1000);
	map->img.addr = mlx_get_data_addr(map->img.img, &map->img.bbp, 
			&map->img.line_size, &map->img.endian);
	map->zoom = 100;
	// map->zoom = (1000 / map->width) / 2;
	draw_map(map);
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img, 0, 0);
	mlx_key_hook(map->win_ptr, deal_key, map);
	mlx_loop(map->mlx_ptr);
	free_map(map);
	return (0);
}

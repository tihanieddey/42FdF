/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:13:17 by nmohd-ed          #+#    #+#             */
/*   Updated: 2025/03/17 14:18:42 by nmohd-ed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <fcntl.h>
#include <stdio.h>

int		deal_key(int key, t_data *map)
{
	if (key == 65307)
	{
		mlx_destroy_window(map->mlx_ptr, map->win_ptr);
		exit(0);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	*data;

	validate_arguments(argc, argv);
	data = init_map(argv[1]);
	if (!data)
		error_exit("Failed to initialized map");
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, 1000, 1000, "FDF");
	if (!data->win_ptr)
		error_exit("Failed to create window");
	printf("Window created successfully.\n");
	data->img.img = mlx_new_image(data->mlx_ptr,1000, 1000);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bbp, 
			&data->img.line_size, &data->img.endian);
	data->zoom = 30;
	draw_map(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.img, 0, 0);
	mlx_key_hook(data->win_ptr, deal_key, data);
	mlx_loop(data->mlx_ptr);
	free_map(data);
	return (0);
}

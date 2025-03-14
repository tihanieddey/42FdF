/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:06:12 by nmohd-ed          #+#    #+#             */
/*   Updated: 2025/03/14 13:32:02 by nmohd-ed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void	ft_slope_x(t_map *map, t_diff diff, float x0, float y0, float x1)
{
	float	slope;
	float	y;
	int		x;

	slope = diff.dy / diff.dx;
	if (x0 < x1)
	{
		x = x0;
		while (x <= x1)
		{
			y = y0 + (x - x0) * slope;
			my_mlx_pixel_put(&map->img, x, (int)y, 0xFFFFFF);
			x++;
		}
	}
	else
	{
		x = x0;
		while (x >= x1)
		{
			y = y0 + (x -x0) * slope;
			my_mlx_pixel_put(&map->img, x, (int)y, 0xFFFFFF);
			x--;
		}
	}
}

void	ft_slope_y(t_map *map, t_diff diff, float x0, float y0, float y1)
{
	float	slope;
	float	x;
	int		y;

	slope = diff.dx / diff.dy;
	if (y0 < y1)
	{
		y = y0;
		while (y <= y1)
		{
			x = x0 + (y - y0) * slope;
			my_mlx_pixel_put(&map->img, (int)x, y, 0xFFFFFF);
			y++;
		}
	}
	else
	{
		y = y0;
		while (y >= y1)
		{
			x = x0 + (y - y0) * slope;
			my_mlx_pixel_put(&map->img, (int)x, y, 0xFFFFFF);
			y--;
		}
	}
}

void	bresenham(float x0, float y0, float x1, float y1, t_map *map)
{
	t_diff	diff;

	// printf("Drawing line from (%.2f,%.2f) to (%.2f,%.2f)\n", x0, y0, x1, y1);
	diff.dx = x1 - x0;
	diff.dy = y1 - y0;
	if (ft_abs(diff.dx) > ft_abs(diff.dy))
		ft_slope_x(map, diff, x0, y0, x1);
	else
		ft_slope_y(map, diff, x0, y0, y1);
}

int	ft_abs(int a)
{
	if (a < 0)
		return (-1 * a);
	return (a);
}

void	draw_map(t_map *map)
{
	int	x;
	int	y;

	// printf("Starting to draw the map...\n"); // Debugging
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			// printf("Drawing point at x=%d, y=%d, z=%d\n", x, y, map->z_matrix[y][x]);
			if (x < map->width - 1)
				bresenham(x, y, x + 1, y, map);
			if (y < map->height - 1)
				bresenham(x, y, x, y + 1, map);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(map->mlx_ptr, map->win_ptr, map->img.img, 0, 0);
	// printf("Finished drawing the map.\n"); // Debugging
}

void my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char *dst;

    dst = data->addr + (y * data->line_size + x * (data->bbp / 8));
    *(unsigned int*)dst = color;
}

// void    bresenham(float x0, float y0, float x1, float y1, t_map *map)
// {
// 	float   x_step;
// 	float   y_step;
// 	int     max;
// 	int     z;
// 	int     z1;

// 	if (y0 < 0 || y0 >= map->height || x0 < 0 || x0 >= map->width ||
// 		y1 < 0 || y1 >= map->height || x1 < 0 || x1 >= map->width)
// 		return;
// 	z = map->z_matrix[(int)y0][(int)x0];
// 	z1 = map->z_matrix[(int)y1][(int)x1];

// 	 // Apply z-coordinate effect before zoom
// 	y0 -= z;
// 	y1 -= z1;

// 	 // Apply zoom after z-coordinate adjustment
// 	 x0 *= map->zoom;
// 	 y0 *= map->zoom;
// 	 x1 *= map->zoom;
// 	 y1 *= map->zoom;

// 	 // Center the drawing
// 	 x0 += map->width * map->zoom / 2;
// 	 y0 += map->height * map->zoom / 2;
// 	 x1 += map->width * map->zoom / 2;
// 	 y1 += map->height * map->zoom / 2;

// 	if (z || z1)
// 		map->colour = 0xe80c0c;
// 	else
// 		map->colour = 0xffffff;
		
// 	x_step = x1 - x0;
// 	y_step = y1 - y0;
// 	max = ft_max(ft_abs(x_step), ft_abs(y_step));
// 	if (max == 0)
// 		return;
// 	x_step /= max;
// 	y_step /= max;
	
// 	while (max >= 0)
// 	{
// 		mlx_pixel_put(map->mlx_ptr, map->win_ptr, (int)x0, (int)y0, map->colour);
// 		x0 += x_step;
// 		y0 += y_step;
// 		max--;
// 	}
// }
// int	ft_max(int a, int b)
// {
// 	if (a > b)
// 		return (a);
// 	return (b);
// }
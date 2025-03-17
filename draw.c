/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 13:06:12 by nmohd-ed          #+#    #+#             */
/*   Updated: 2025/03/17 15:25:44 by nmohd-ed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

void	draw_map(t_data *fdf)
{
	int		i;
	int		j;

	mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	j = 0;
	while (j < fdf->height)
	{
		i = 0;
		while (i < fdf->width)
		{
			if (i < fdf->width - 1)
				bresenham_x(fdf, i, j, i + 1, j);
			if (j < fdf->height - 1)
				bresenham_y(fdf, i, j, i, j + 1);
			i++;
		}
		j++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img.img, 0, 0);
}

START TOMORROW

// void	bresenham_x(t_data *fdf, int x0, int y0, int x1, int y1)
// {
// 	t_line	line;

// 	line.dx = x1 - x0;
// 	line.dy = y1 - y0;
// 	line.p = 2 * ft_abs(line.dy) - ft_abs(line.dx);
// 	line.x = x0;
// 	line.y = y0;
// 	while (line.x != x1 || line.y != y1)
// 	{
// 		my_mlx_pixel_put(fdf, line.x * fdf->zoom + 500,
// 			line.y * fdf->zoom + 500, 0xFFFFFF);
// 		if (line.x == x1)
// 			break ;
// 		if (line.p < 0)
// 		{
// 			line.x += sign_func(x0, x1);
// 			line.p += 2 * ft_abs(line.dy);
// 		}
// 		else
// 		{
// 			line.x += sign_func(x0, x1);
// 			line.y += sign_func(y0, y1);
// 			line.p += 2 * ft_abs(line.dy) - 2 * ft_abs(line.dx);
// 		}
// 	}
// }

// void	bresenham_y(t_data *fdf, int x0, int y0, int x1, int y1)
// {
// 	t_line	line;

// 	line.dx = x1 - x0;
// 	line.dy = y1 - y0;
// 	line.p = 2 * ft_abs(line.dx) - ft_abs(line.dy);
// 	line.x = x0;
// 	line.y = y0;
// 	while (line.x != x1 || line.y != y1)
// 	{
// 		my_mlx_pixel_put(fdf, line.x * fdf->zoom + 500, 
// 			line.y * fdf->zoom + 500, 0xFFFFFF);
// 		if (line.y == y1)
// 			break ;
// 		if (line.p < 0)
// 		{
// 			line.y += sign_func(y0, y1);
// 			line.p += 2 * ft_abs(line.dx);
// 		}
// 		else
// 		{
// 			line.y += sign_func(y0, y1);
// 			line.x += sign_func(x0, x1);
// 			line.p += 2 * ft_abs(line.dx) - 2 * ft_abs(line.dy);
// 		}
// 	}
// }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x >= 0 && x < 1000 && y >= 0 && y < 1000)
// 	{
// 		dst = data->img.addr + (y * data->img.line_size 
// 			+ x * (data->img.bbp / 8));
// 		*(unsigned int*)dst = color;
// 	}
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:01:05 by nmohd-ed          #+#    #+#             */
/*   Updated: 2025/03/14 15:01:00 by nmohd-ed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../lib/libft/libft.h"
# include "../lib/minilibx-linux/mlx.h"
# include "../lib/libft/gnl/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

#define	EXIT_FAILURE	1

/*struct for map initialization
Functions used:
-	map.c
-	map_utils.c
-	read_files.c
-	free_error.c
*/

// for difference of slope
typedef struct s_diff
{
	float	dx;
	float	dy;
} t_diff;

// for the coordinate in start and end point
typedef struct s_point
{
	int		x;
	int		y;
	int		z;
} t_point;

// for the printing image into window
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_size;
	int		endian;
}	t_data;

// for matrix
typedef	struct s_map
{
	int		width;
	int		height;
	t_data	img;
	int		**z_matrix;
	int		zoom;
	int		colour;
	
	void	*mlx_ptr;
	void	*win_ptr;
}	t_map;

/*map_utils.c*/
void	validate_arguments(int argc, char *argv[]);
void	parse_line(char *line, t_map *map, int y);
void	map_mem_alloc(t_map *map);

/*free_error.c*/
void	error_exit(char *exerrmsg);
void	free_argument(char **array_string);
void	handle_split_error(char *line, char **split, t_map *map);
void	free_map(t_map *map);

/*map.c*/
t_map	*init_map(char *file_name);
void	process_line(char *line, t_map *map);
void	get_map_dimensions(int fd, t_map *map);
void	pars_val_map(int fd, t_map *map);

/*draw.c*/
void	ft_slope_x(t_map *map, t_diff diff, float x0, float y0, float x1);
void	ft_slope_y(t_map *map, t_diff diff, float x0, float y0, float y1);
void	bresenham(float x0, float y0, float x1, float y1, t_map *map);
int		ft_abs(int a);
void	draw_map(t_map *map);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
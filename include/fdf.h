/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 13:01:05 by nmohd-ed          #+#    #+#             */
/*   Updated: 2025/03/17 14:38:39 by nmohd-ed         ###   ########.fr       */
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

// for the coordinate in start and end point
typedef struct s_line
{
	int		dx;
	int		dy;
	int		p;
	int		x;
	int		y;
	int		z;
	int		colour;
} t_line;

// for the printing image into window
typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bbp;
	int		line_size;
	int		endian;
}	t_img;

// for matrix
typedef	struct s_data
{
	int		width;
	int		height;
	int		**z_matrix;
	int		**color;
	int		iscolour;
	int		max_z;
	int		min_z;
	int		zoom;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}	t_data;

/*map_utils.c*/
void		validate_arguments(int argc, char *argv[]);
void		parse_line(char *line, t_data *map, int y);
void		map_mem_alloc(t_data *map);

/*free_error.c*/
void		error_exit(char *exerrmsg);
void		free_argument(char **array_string);
void		handle_split_error(char *line, char **split, t_data *map);
void		free_map(t_data *map);

/*map.c*/
t_data		*init_map(char *file_name);
void		process_line(char *line, t_data *map);
void		get_map_dimensions(int fd, t_data *map);
void		pars_val_map(int fd, t_data *map);

/*draw.c*/
void		draw_map(t_data *fdf);
void		bresenham_x(t_data *fdf, int x0, int y0, int x1, int y1);
void		bresenham_y(t_data *fdf, int x0, int y0, int x1, int y1);
void		my_mlx_pixel_put(t_data *data, int x, int y, int color);

/*draw_utils.c*/
int			ft_abs(int a);
int			sign_func(int a, int b);

#endif
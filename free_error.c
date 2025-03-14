/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 12:44:32 by nmohd-ed          #+#    #+#             */
/*   Updated: 2025/03/03 13:36:42 by nmohd-ed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	error_exit(char *exerrmsg)
{
	ft_putendl_fd(exerrmsg, 2);
	exit(EXIT_FAILURE);
}

void	free_argument(char **array_string)
{
	int	index;

	index = 0;
	if (!array_string)
		return ;
	while (array_string[index])
	{
		free(array_string[index]);
		index++;
	}
	free(array_string);
}

void	handle_split_error(char *line, char **split, t_map *map)
{
	free(line);
	free_argument(split);
	free(map);
	error_exit("Split failed");
}

void	free_map(t_map *map)
{
	int		i;

	if (!map)
		return ;
	if (map->z_matrix)
	{
		i = -1;
		while (++i < map->height)
			free(map->z_matrix[i]);
		free(map->z_matrix);
	}
	free(map);
}
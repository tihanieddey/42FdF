/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmohd-ed <nurhidayahtihani@gmail.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:13:04 by nmohd-ed          #+#    #+#             */
/*   Updated: 2025/03/17 14:13:46 by nmohd-ed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	ft_abs(int a)
{
	if (a < 0)
		return (-(a));
	return (a);
}

int	sign_func(int a, int b)
{
	if (a < b)
		return (1);
	return (-1);
}
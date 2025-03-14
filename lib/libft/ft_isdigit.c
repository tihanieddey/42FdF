/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihanieddey <nurhidayahtihani@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 11:06:46 by tihanieddey       #+#    #+#             */
/*   Updated: 2024/11/12 11:20:25 by tihanieddey      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The isdigit() function tests for a decimal digit character.
 * The value of the argument must be representable as an unsigned char or 
 * the value of EOF.
 * 
 * @return The isdigit() function return zero if the character tests false 
 * and return non-zero if the character tests true.
 */
int	ft_isdigit(int num)
{
	return (num >= '0' && num <= '9');
}

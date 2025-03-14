/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihanieddey <nurhidayahtihani@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 08:06:59 by tihanieddey       #+#    #+#             */
/*   Updated: 2024/11/13 08:59:22 by tihanieddey      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strncmp() function lexicographically compare the 
 * null-terminated strings s1 and s2. 
 * The strncmp() function compares not more than n characters. 
 * Because it is designed for comparing strings rather than binary data,
 * characters that appear after a '\0' character are not compared.
 * 
 * @param s1 - string to be compared
 * @param s2 - string to be compared
 * @param n - maximum numbers to be compared
 * 
 * @return an integer greater than, equal to, or less than 0, 
 * according as the string s1 is >, =, or < the string s2.
 */
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*s1 == *s2 && --n && *s1)
	{
		s1++;
		s2++;
	}
	return ((unsigned char)*s1 - (unsigned char)*s2);
}

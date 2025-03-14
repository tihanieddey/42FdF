/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihanieddey <nurhidayahtihani@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:53:10 by tihanieddey       #+#    #+#             */
/*   Updated: 2024/11/13 07:18:13 by tihanieddey      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strchr() function locates the first occurence of c 
 * (converted to a char) in the string pointed to by s. The terminating null
 *  character is considered to be part of the string; therefor if c is '\0',
 *  the function locate the terminating '\0'.
 * 
 * @return The function strchr() return a pointer to the located character,
 *  or NULL if the character does not appear in the string.
 */
char	*ft_strchr(const char *str, int ch)
{
	while (*str)
	{
		if (*str == (char)ch)
			return ((char *)str);
		str++;
	}
	if (ch == '\0')
	{
		return ((char *)str);
	}
	return (NULL);
}

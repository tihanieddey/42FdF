/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihanieddey <nurhidayahtihani@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:46:27 by tihanieddey       #+#    #+#             */
/*   Updated: 2024/11/12 10:46:27 by tihanieddey      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The bzero() function writes n zeroed bytes to the string s.  If n 
 * is zero, bzero() does nothing.
 */
void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}
// #include <stdio.h>
// #include <strings.h>

// int main()
// {
// 	char buffer[10];
// 	for (int i = 0; i < 10; i++)
// 	{
// 		buffer[i] = 'A';
// 	}

// 	printf("Buffer before bzero:");
// 	for (int i = 0; i < 10; i++)
// 	{
// 		printf("%c", buffer[i]);
// 	}
// 	printf("\n");

// 	ft_bzero(buffer, sizeof(buffer));

// 	printf("Buffer after bzero:");
// 	for (int i = 0; i < 10; i++)
// 	{
// 		printf("%d", buffer[i]);
// 	}
// 	printf("\n");

// 	return (0);
// }
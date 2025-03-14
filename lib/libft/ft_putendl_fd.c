/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihanieddey <nurhidayahtihani@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:45:45 by tihanieddey       #+#    #+#             */
/*   Updated: 2024/11/13 09:16:00 by tihanieddey      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief ft_putendl_fd outputs the string to the given file descriptor
 * followed by a newline.
 * 
 * @param s - string to output
 * @param fd - the file descriptor on which to write
 */
void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}
// int main()
// {
// 	ft_putendl_fd("Hello, world", 1);
// 	ft_putendl_fd("This is the error message", 2);
// 	return (0);
// }
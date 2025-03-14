/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihanieddey <nurhidayahtihani@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:19:17 by tihanieddey       #+#    #+#             */
/*   Updated: 2024/11/13 09:17:10 by tihanieddey      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief ft_putstr_fd function outputs the string 's' to the given file 
 * descriptor.
 * 
 * @param s - the string that you want to output
 * @param fd - the file descriptor on which to write
 */
void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int main()
// {
//     ft_putstr_fd("Hello, world\n", 1);
//     ft_putstr_fd("This is the error message.\n", 2);
//     return (0);
// }
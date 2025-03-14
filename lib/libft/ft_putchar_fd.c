/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihanieddey <nurhidayahtihani@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 14:00:21 by tihanieddey       #+#    #+#             */
/*   Updated: 2024/11/07 15:55:24 by tihanieddey      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief outputs the character 'c' to the given file descriptor
 * 
 * @param c - the character output
 * @param fd = the file descriptor on which to write
 */
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
// int main(void)
// {
// 	ft_putchar_fd('H', 1);
// 	ft_putchar_fd('e', 1);
// 	ft_putchar_fd('l', 1);
// 	ft_putchar_fd('l', 1);
// 	ft_putchar_fd('o', 1);
// 	ft_putchar_fd('\n', 1);

// 	ft_putchar_fd('E', 2);
// 	ft_putchar_fd('r', 2);
// 	ft_putchar_fd('r', 2);
// 	ft_putchar_fd('o', 2);
// 	ft_putchar_fd('r', 2);
// 	ft_putchar_fd('\n', 2);

// 	return (0);
// }
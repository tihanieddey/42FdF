/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihanieddey <nurhidayahtihani@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 12:44:46 by tihanieddey       #+#    #+#             */
/*   Updated: 2024/11/12 10:58:27 by tihanieddey      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The atoi() function converts the initial portion of the string 
 * pointed to by str to int representation.
 */
int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		sign *= -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * sign);
}
// #include <stdio.h>
// int main(int ac, char **av)
// {
// 	int tester;
// 	int original;
// 	if (ac == 2)
// 	{
// 		tester = ft_atoi(av[1]);
// 		original = atoi(av[1]);
// 		printf("tester: %d | original: %d\n", tester, original);
// 	}
// 	return (0);
// }
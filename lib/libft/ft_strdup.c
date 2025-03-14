/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihanieddey <nurhidayahtihani@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 10:27:42 by tihanieddey       #+#    #+#             */
/*   Updated: 2024/11/07 12:29:26 by tihanieddey      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The strdup() function allocates sufficient memory for a copy of 
 * the string s1, does the copy, and returns a pointer to it. 
 * 
 * @return If insufficient memory is available, NULL is returned.
 */
char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * ft_strlen(s1) + 1);
	if (!ptr)
		return (NULL);
	while (*s1)
		ptr[i++] = *s1++;
	ptr[i] = '\0';
	return (ptr);
}
// #include <stdio.h>
// #include <string.h>
// int main(int ac, char **av)
// {
//     char    *myfunc;
//     char    *builtin;

//     if (ac == 2)
//     {
//         myfunc = ft_strdup(av[1]);
//         builtin = strdup(av[1]);
//         printf(":%s:\n:%s:\n", myfunc, builtin);
//     }
//     return (0);
// }
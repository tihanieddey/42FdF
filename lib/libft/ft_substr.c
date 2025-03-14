/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihanieddey <nurhidayahtihani@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 07:41:25 by tihanieddey       #+#    #+#             */
/*   Updated: 2024/11/13 09:25:38 by tihanieddey      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	mystrlen(const char *str)
{
	size_t	c;

	c = 0;
	while (str[c] != '\0')
		c++;
	return (c);
}

static char	*mystrdup(const char *s1)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(sizeof(char) * (mystrlen(s1) + 1));
	if (!ptr)
		return (NULL);
	while (*s1)
		ptr[i++] = *s1++;
	ptr[i] = '\0';
	return (ptr);
}

/**
 * @brief Allocates with malloc(3) and returns a substring from the string
 * 's'. The substring begins at index 'start' and is maximum size of 'len'.
 * 
 * @param s - string from which to create substring.
 * @param start - start index of the substring in the string 's'.
 * @param len - the maximum length of the substring.
 * 
 * @return the substring. NULL if allocation fails.
 */
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	if (!s || start >= mystrlen(s))
		return (mystrdup(""));
	if (mystrlen(s + start) < len)
		len = mystrlen(s + start);
	ptr = malloc(sizeof(char) * (len + 1));
	if (!ptr)
		return (NULL);
	while (i < len && s[start])
		ptr[i++] = s[start++];
	ptr[i] = '\0';
	return (ptr);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char *str = "Hello, world!";
// 	char *substr;
// 	substr = ft_substr(str, 7, 5);  // Should extract "world"
// 	if (substr)
// 	{
// 		printf("Substring: %s\n", substr);
// 		free(substr);  // Free the allocated memory
// 	}
// 	return (0);
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihanieddey <nurhidayahtihani@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:16:55 by tihanieddey       #+#    #+#             */
/*   Updated: 2024/11/13 10:48:33 by tihanieddey      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Allocates with malloc and returns an array of strings obtained by 
 * splitting 's' using the character 'c' as a delimiter. The array must end 
 * with a NULL pointer.
 * 
 * @param s - the string to be split
 * @param c - the delimiter character
 * 
 * @return The array of new strings resulting from the split.
 * NULL if allocation fails.
 */
static size_t	copy_string(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (size == 0)
		return (0);
	while (src[i] != '\0')
		i++;
	while ((j < size - 1) && (src[j] != '\0'))
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

static int	allocate_memory_for_string(char **ptr, int pos, size_t buffer)
{
	int	i;

	i = 0;
	ptr[pos] = malloc(buffer);
	if (!ptr[pos])
	{
		while (i < pos)
			free(ptr[--pos]);
		free(ptr);
		return (1);
	}
	return (0);
}

static int	split_and_copy_words(char **ptr, char const *s, char c)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == c && *s)
			++s;
		while (*s != c && *s)
		{
			++len;
			++s;
		}
		if (len)
		{
			if (allocate_memory_for_string(ptr, i, len + 1))
				return (1);
			copy_string(ptr[i], s - len, len + 1);
		}
		++i;
	}
	return (0);
}

static size_t	count_words(char const *s, char c)
{
	size_t	num_words;
	int		in_word;

	num_words = 0;
	while (*s)
	{
		in_word = 0;
		while (*s == c && *s)
			++s;
		while (!(*s == c) && *s)
		{
			if (!in_word)
			{
				++num_words;
				in_word = 1;
			}
			s++;
		}
	}
	return (num_words);
}

char	**ft_split(char const *s, char c)
{
	size_t	num_tokens;
	size_t	i;
	char	**ptr;

	if (!s)
		return (NULL);
	num_tokens = count_words(s, c);
	ptr = malloc(sizeof(char *) * (num_tokens + 1));
	if (!ptr)
		return (NULL);
	ptr[num_tokens] = NULL;
	if (split_and_copy_words(ptr, s, c))
	{
		while (num_tokens--)
			i = num_tokens;
		while (i--)
			free(ptr[i]);
		return (NULL);
	}
	return (ptr);
}

// #include <stdio.h>

// int	main()
// {
// 	char	*s = "     Hello there, dude!!";
// 	char	**v = ft_split(s, ' ');

// 	while (*v)
// 		printf("%s\n", *v++);
// }
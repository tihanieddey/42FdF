/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tihanieddey <nurhidayahtihani@gmail.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 08:21:11 by tihanieddey       #+#    #+#             */
/*   Updated: 2024/11/13 10:42:25 by tihanieddey      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief The calloc() function contiguously allocates enough space for 
 * count objects that are size bytes of memory each and returns a pointer to
 * the allocated memory.  The allocated memory is filled with bytes of 
 * value zero.
 * 
 * @return If successful, calloc() functions return a pointer to allocated 
 * memory. If there is an error, they return a NULL pointer.
 * 
 * @param count_n − It represents the number of element to be allocated.
 * @param size − It represents the size of each element.
 */
static void	mybzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count_n, size_t size)
{
	void	*ptr;

	if (count_n != 0 && size > UINT_MAX / count_n)
		return (NULL);
	if (count_n == 0 || size == 0)
		return (malloc(1));
	ptr = malloc(count_n * size);
	if (!ptr)
		return (NULL);
	mybzero(ptr, count_n * size);
	return (ptr);
}
// #include <stdio.h>
// int main()
// {
//     int *arr;
//     size_t count = 5;  // Number of elements
//     size_t size = sizeof(int);  // Size of each element (int)
//     arr = ft_calloc(count, size);
//     if (arr == NULL)
//     {
//         printf("Memory allocation failed.\n");
//         return 1;
//     }
//     // Check if the memory is initialized to zero
//     for (size_t i = 0; i < count; i++)
//     {
//         printf("arr[%zu] = %d\n", i, arr[i]);
//     }
//     // Free the allocated memory
//     free(arr);
//     return 0;
// }
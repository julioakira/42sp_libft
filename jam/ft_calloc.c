/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akira <akira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 01:51:07 by akira             #+#    #+#             */
/*   Updated: 2021/08/01 02:40:22 by akira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>

// Malloc -> Memory allocation
// Calloc -> Contiguous allocation

// Malloc -> Allocates --size-- bytes
// Calloc allocates --nmemb-- bytes of size --size--

// Malloc -> Unintialized memory
// Calloc -> Zero initialized memory

// nmemb = number of blocks
// size = size of each block

void *ft_memset(void *b, int c, size_t len)
{
	char *ptr;
	size_t idx;

	idx = 0;
	ptr = b;
	while (idx < len)
	{
		ptr[idx] = (unsigned char)c;
		idx++;
	}
	return (b);
}

void *ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;
	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	ft_memset(ptr, 0, size);
	return (ptr);
}

void malloc_test(void)
{
	int *ptr;
	ptr = malloc(10 * sizeof(*ptr));
	if (ptr)
	{
		*(ptr + 5) = 25;
		printf("The 5th element of ptr array is: %d\n", *(ptr + 5));
	}
}

void calloc_test(void)
{
	int *ptr;
	ptr = calloc(10, sizeof(*ptr));
	*(ptr + 5) = 25;
	if (ptr)
	{
		printf("The 5th element of the ptr array is: %d\n", *(ptr + 5));
		printf("The 4th element of the ptr array is: %d\n", *(ptr + 4));
	}
}

void my_calloc_test(void)
{
	int *ptr;
	ptr = calloc(10, sizeof(*ptr));
	if (ptr)
	{
		*(ptr + 5) = 25;
		printf("The 5th element of ptr array is: %d\n", *(ptr + 5));
		printf("The 4th element of ptr array is: %d\n", *(ptr + 4));
	}
}

int main(void)
{
	malloc_test();
	calloc_test();
	my_calloc_test();
}

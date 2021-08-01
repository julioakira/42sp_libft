/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akira <akira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/01 02:48:53 by akira             #+#    #+#             */
/*   Updated: 2021/08/01 03:35:54 by akira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

size_t ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t idx;
	char *c_dst;

	idx = 0;
	c_dst = dst;
	if (dstsize > 0)
	{
		while (idx < dstsize - 1)
		{
			if (src[idx] == '\0')
				break;
			c_dst[idx] = src[idx];
			idx++;
		}
		c_dst[idx] = '\0';
	}
	return ft_strlen(src);
}

size_t ft_strlen(const char *s)
{
	size_t idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

char *ft_strdup(const char *s)
{
	char *dup;
	char *ptr;
	size_t s_len;

	s_len = ft_strlen(s);
	dup = malloc(s_len + 1);
	ptr = dup;
	while (*s)
		*dup++ = *s++;
	*dup = '\0';
	return (ptr);
}

int main(void)
{
	char *str1 = "Hello, i am a string lalala!";
	char *str2 = ft_strdup(str1);
	printf("Str1: %s\n", str1);
	printf("Str2: %s\n", str2);
	return (0);
}

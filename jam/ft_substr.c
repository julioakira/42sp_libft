/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 03:19:17 by akira             #+#    #+#             */
/*   Updated: 2021/08/09 22:08:17 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

static size_t	get_smaller(size_t a, size_t b);

static size_t	get_smaller(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}


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

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void *ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;
	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	ft_bzero(ptr, size);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_piece_len;
	char	*substr;
	size_t	idx;
	size_t	smaller;

	if (!s || !len)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	idx = 0;
	s_piece_len = ft_strlen(&s[start]);
	smaller = get_smaller(len, s_piece_len);
	substr = ft_calloc(smaller + 1, sizeof (char));
	while (idx < len && s[start + idx])
	{
		substr[idx] = s[start + idx];
		idx++;
	}
	substr[idx] = '\0';
	return (substr);
}

int main(void)
{
	char *s2 = ft_substr("tripouille", 1, 1);
	char *s = ft_substr("tripouille", 100, 1);
	char *s3 = ft_substr("42", 0, 0);
	printf("Substr %s\n", s);
	printf("Substr %s\n", s2);
	printf("Substr %s\n", s3);
}

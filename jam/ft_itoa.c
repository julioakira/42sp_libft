/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:02:23 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/13 01:19:16 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static int digit_counter(int n);

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

void ft_bzero(void *s, size_t n)
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

size_t ft_strlen(const char *s)
{
	size_t idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

static int	digit_counter(int n);
static char	*to_str(char *str, unsigned int n, int len);

static int	digit_counter(int n)
{
	int	r;
	int	counter;

	r = n;
	counter = !n;
	if (n < 0)
	{
		r *= (-1);
		counter++;
	}
	if (n > 0 && n < 10)
		return (1);
	while (r)
	{
		r /= 10;
		counter++;
	}
	return (counter);
}

static char	*to_str(char *str, unsigned int n, int len)
{
	while (n > 0)
	{
		str[len--] = '0' + (n % 10);
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	char			*result;
	int				idx;
	unsigned int	nbr;
	int				n_digits;

	n_digits = digit_counter(n);
	result = (char *)ft_calloc(n_digits + 1, sizeof(char));
	idx = 0;
	if (!result)
		return (NULL);
	result[n_digits--] = '\0';
	if (n == 0)
	{
		result[idx++] = '0';
		return (result);
	}
	else if (n < 0)
	{
		nbr = -n;
		result[idx++] = '-';
	}
	else
		nbr = n;
	result = to_str(result, nbr, n_digits);
	return (result);
}

int main(void)
{
	int n_int1 = 2147483647;
	int n_int2 = -2147483648;
	int n_int3 = 0;
	int n_int4 = 10;
	int n_int5 = -245;
	printf("FT Itoa test 1: %s\n", ft_itoa(n_int1));
	printf("FT Itoa test 2: %s\n", ft_itoa(n_int2));
	printf("FT Itoa test 3: %s\n", ft_itoa(n_int3));
	printf("FT Itoa test 4: %s\n", ft_itoa(n_int4));
	printf("FT Itoa test 5: %s\n", ft_itoa(n_int5));
	return (0);
}

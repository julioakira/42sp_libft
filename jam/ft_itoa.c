/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 00:02:23 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/09 23:52:48 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdlib.h>
#include <stdio.h>

static	int digit_counter(int n);
static	int power(int base, int exponent);
static	char	get_digit(int num, int pos);

// Positives and negatives
static int	digit_counter(int n)
{
	int r;
	int counter;

	r = n;
	counter = !n;
	if (n == -2147483648)
		return (11);
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

static	int power(int base, int exponent)
{
	int result;

	result = 1;
	while (exponent > 0)
		{
			result = result * base;
			exponent--;
		}
	return result;
}

// Reverses Position
static char	get_digit(int num, int pos)
{
	int		result;

	result = num / power(10, pos);
	result = result % 10;
	result = result + '0';
    return (result);
}


char	*ft_itoa(int n)
{
	char	*result;
	int		n_digits;
	int		idx;

	n_digits = digit_counter(n);
	result = calloc(n_digits + 1, 1);
	if (!result)
		return (NULL);
	idx = 1;
	while (idx < n_digits)
	{
		if (n < 0)
		{
			result[idx - 1] = '-';
			n *= (-1);
			idx++;
		}
		result[idx - 1] = get_digit(n, n_digits - idx);
		idx++;
	}
	result[n_digits + 1] = '\0';
	return (result);
}

int main(void)
{
	int n_int2 = -2147483648;
	printf("FT Itoa test 2: %s\n", ft_itoa(n_int2));
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/08 04:48:06 by jakira-p          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2021/08/13 01:19:34 by jakira-p         ###   ########.fr       */
=======
/*   Updated: 2021/08/09 23:55:59 by jakira-p         ###   ########.fr       */
>>>>>>> fb3111c765990fd530310e4013db46fe39b84b0e
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
<<<<<<< HEAD
	result = (char *)ft_calloc(n_digits + 1, sizeof(char));
	idx = 0;
	if (!result)
		return (NULL);
	result[n_digits--] = '\0';
	if (n == 0)
=======
	result = calloc(n_digits + 1, sizeof(char));
	if (!result)
		return (NULL);
	idx = 1;
	if (n == -2147483648)
>>>>>>> fb3111c765990fd530310e4013db46fe39b84b0e
	{
		result[idx++] = '0';
		return (result);
	}
	else if (n < 0)
	{
		nbr = -n;
		result[idx++] = '-';
	}
<<<<<<< HEAD
	else
		nbr = n;
	result = to_str(result, nbr, n_digits);
=======
>>>>>>> fb3111c765990fd530310e4013db46fe39b84b0e
	return (result);
}

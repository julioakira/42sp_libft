/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 02:21:07 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/08 04:42:02 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		ft_get_length(int n);
int		power(int base, int exponent);
void	get_digit(int num, int n, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_min_int(int fd);

int	ft_get_length(int n)
{
	int		length;

	length = !n;
	while (n)
	{
		length++;
		n = n / 10;
	}
	return (length);
}

int	power(int base, int exponent)
{
	int	result;

	result = 1;
	while (exponent > 0)
	{
		result = result * base;
		exponent--;
	}
	return (result);
}

void	get_digit(int num, int pos, int fd)
{
	int		result;

	result = num / power(10, pos);
	result = result % 10;
	result = result + '0';
	write(fd, &result, 1);
}

void	ft_min_int(int fd)
{
	write(fd, "-", 1);
	write(fd, "2", 1);
	write(fd, "1", 1);
	write(fd, "4", 1);
	write(fd, "7", 1);
	write(fd, "4", 1);
	write(fd, "8", 1);
	write(fd, "3", 1);
	write(fd, "6", 1);
	write(fd, "4", 1);
	write(fd, "8", 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int	length;
	int	counter;

	counter = 1;
	length = ft_get_length(n);
	if (n == -2147483648)
		ft_min_int(fd);
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		while (counter <= length)
		{
			get_digit(n, length - counter, fd);
			counter++;
		}
	}
	else if (n >= 0)
	{
		while (counter <= length)
		{
			get_digit(n, length - counter, fd);
			counter++;
		}
	}
}

int main(void)
{
	int n = +0;
	ft_putnbr_fd(n, 1);
}

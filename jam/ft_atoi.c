/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 02:51:27 by jakira-p          #+#    #+#             */
/*   Updated: 2021/07/30 04:38:01 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_check_spaces(char *str, int idx)
{
	if (str[idx] == ' '
	|| str[idx] == '\f'
	|| str[idx] == '\n'
	|| str[idx] == '\r'
	|| str[idx] == '\t'
	|| str[idx] == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		idx;
	int		sign;
	char	*c_str;

	idx = 0;
	result = 0;
	sign = 1;
	c_str = (char *) str;
	while (ft_check_spaces(c_str, idx))
		idx++;
	if (c_str[idx] == '-' || c_str[idx] == '+')
	{
		if (c_str[idx] == '-')
			sign *= (-1);
		idx++;
	}
	while (c_str[idx] != '\0')
	{
		if (c_str[idx] >= '0' && c_str[idx] <= '9')
		{
			result *= 10;
			result += (c_str[idx] - '0');
			idx++;
		}
		else
			break ;
	}
	result *= sign;
	return (result);
}

int main(void)
{
	char *n_str = "1234567";
	char *n_str2 = "-1234567";
	char *n_str3 = "   1234567";
	char *n_str4 = "123 4567";
	char *n_str5 = "12345fff67";
	printf("Atoi test: %d\n", atoi(n_str));
	printf("Atoi test: %d\n", atoi(n_str2));
	printf("Atoi test: %d\n", atoi(n_str3));
	printf("Atoi test: %d\n", atoi(n_str4));
	printf("Atoi test: %d\n", atoi(n_str5));
	printf("FT Atoi test: %d\n", ft_atoi(n_str));
	printf("FT Atoi test: %d\n", ft_atoi(n_str2));
	printf("FT Atoi test: %d\n", ft_atoi(n_str3));
	printf("FT Atoi test: %d\n", ft_atoi(n_str4));
	printf("FT Atoi test: %d\n", ft_atoi(n_str5));
	return (0);
}

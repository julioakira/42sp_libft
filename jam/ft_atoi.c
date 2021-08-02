/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 02:51:27 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/02 04:07:56 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_check_spaces(char c)
{
	if (c == ' '
	|| c == '\f'
	|| c == '\n'
	|| c == '\r'
	|| c == '\t'
	|| c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_check_spaces(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= (-1);
		str++;
	}
	while (*str)
	{
		if (ft_isdigit(*str))
		{
			result *= 10;
			result += (*str++ - '0');
		}
		else
			break ;
	}
	return (result * sign);
}

int main(void)
{
	char *n_str = "1234567";
	char *n_str2 = "-1234567";
	char *n_str3 = "   1234567";
	char *n_str4 = "123 4567";
	char *n_str5 = "12345fff67";
	char *n_str6 = "";
	char *n_str7 = "+123456";
	char *n_str8 = "123-456";
	printf("Atoi test 1: %d\n", atoi(n_str));
	printf("Atoi test 2: %d\n", atoi(n_str2));
	printf("Atoi test 3: %d\n", atoi(n_str3));
	printf("Atoi test 4: %d\n", atoi(n_str4));
	printf("Atoi test 5: %d\n", atoi(n_str5));
	printf("Atoi test 6: %d\n", atoi(n_str6));
	printf("Atoi test 7: %d\n", atoi(n_str7));
	printf("Atoi test 8: %d\n", atoi(n_str8));
	printf("FT Atoi test 1: %d\n", ft_atoi(n_str));
	printf("FT Atoi test 2: %d\n", ft_atoi(n_str2));
	printf("FT Atoi test 3: %d\n", ft_atoi(n_str3));
	printf("FT Atoi test 4: %d\n", ft_atoi(n_str4));
	printf("FT Atoi test 5: %d\n", ft_atoi(n_str5));
	printf("FT Atoi test 6: %d\n", ft_atoi(n_str6));
	printf("FT Atoi test 7: %d\n", ft_atoi(n_str7));
	printf("FT Atoi test 8: %d\n", ft_atoi(n_str8));
	return (0);
}

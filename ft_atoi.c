/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akira <akira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 02:49:48 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/04 01:34:44 by akira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_check_spaces(const char *str)
{
	if (*str == ' '
		|| *str == '\f'
		|| *str == '\n'
		|| *str == '\r'
		|| *str == '\t'
		|| *str == '\v')
		return (1);
	return (0);
}

int	ft_atoi(const char *str)
{
	int		result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_check_spaces(str))
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

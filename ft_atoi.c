/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 02:49:48 by jakira-p          #+#    #+#             */
/*   Updated: 2021/07/30 04:38:08 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

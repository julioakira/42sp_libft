/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akira <akira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 03:00:55 by akira             #+#    #+#             */
/*   Updated: 2021/08/03 03:49:01 by akira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #1. The string from which to create the substring.
// #2. The start index of the substring in the string ’s’.
// #3. The maximum length of the substring.
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	idx;

	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (start < len)
	{
		result[idx] = s[start];
		idx++;
		start++;
	}
	result[idx] = '\0';
	return result;
}

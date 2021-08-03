/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akira <akira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 03:19:17 by akira             #+#    #+#             */
/*   Updated: 2021/08/03 03:30:26 by akira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft.h"

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

int main(void)
{
	char *str = "A relatively short string";
	unsigned int start = 4;
	size_t len = 9;
	printf("Substr %s\n", ft_substr(str, start, len));
}

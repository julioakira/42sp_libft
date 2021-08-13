/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 03:32:37 by akira             #+#    #+#             */
/*   Updated: 2021/08/12 01:25:11 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

// #1. The prefix string.
// #2. The suffix string.
// #Ret -> The new string. NULL if the allocation fails.
char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	size_t	idx;
	size_t	s_idx;

	result = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	idx = 0;
	s_idx = 0;
	if (result == NULL)
		return (NULL);
	while (s1[idx])
	{
		result[idx] = s1[idx];
		idx++;
	}
	while (s2[s_idx])
	{
		result[idx] = s2[s_idx];
		idx++;
		s_idx++;
	}
	result[idx] = '\0';
	return (result);
}


int main(void)
{
	char * s = ft_strjoin("tripouille", "42");
	printf("Result: %s\n", s);
	return (0);
}

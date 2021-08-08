/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 01:12:45 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/07 01:52:07 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <stdlib.h>

size_t ft_strlen(const char *s)
{
	size_t idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*s_cpy;
	unsigned int	idx;
	if (!s || !f)
		return (NULL);
	s_cpy = malloc(ft_strlen(s) + 1);
	idx = 0;
	while (s)
	{
		s_cpy[idx] = f(idx, s_cpy[idx]);
		idx++;
	}
	s_cpy[idx + 1] = '\0';
	return (s_cpy);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 04:01:07 by akira             #+#    #+#             */
/*   Updated: 2021/08/04 02:11:12 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #1. The string to be trimmed.
// #2. The reference set of characters to trim

static int	is_in_char_set(char const *set, char a)
{
	while (*set)
	{
		if (*set == a)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int i;
	int p[3];
	char *ret;

	i = 0;
	p[2] = ft_strlen(s1);
	while (is_in_char_set(set, s1[i]))
	{
		i++;
	}
	p[0] = i;
	i = p[2] - 1;
	while(is_in_char_set(set, s1[i]))
	{
		i--;
	}
	p[1] = i;
	ret = ft_substr(s1, p[0], p[1] + 1);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:21:24 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/08 04:55:55 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_char_set(char const *set, char a);

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
	int		idx;
	int		ptr[3];
	char	*ret;

	idx = 0;
	ptr[2] = ft_strlen(s1);
	while (is_in_char_set(set, s1[idx]))
	{
		idx++;
	}
	ptr[0] = idx;
	idx = ptr[2] - 1;
	while (is_in_char_set(set, s1[idx]))
	{
		idx--;
	}
	ptr[1] = idx;
	ret = ft_substr(s1, ptr[0], ptr[1] + 1);
	return (ret);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 01:47:52 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/05 02:48:49 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_char_at_pos(const char *str, char c);

static int	ft_char_at_pos(const char *str, char c)
{
	int	idx;

	idx = 0;
	while (str[idx])
	{
		if (str[idx] == c)
			return (idx);
		idx++;
	}
	return (0);
}

// Return null if malloc fails
char	**ft_split(char const *s, char c)
{
	char	**result;
	char	*s_cpy;
	char	*s1;
	size_t	idx;

	s_cpy = (char *) s;
	if (!ft_char_at_pos(s, c))
		return (NULL);
	idx = 0;
	result = malloc(ft_strlen(s));
	s1 = malloc(ft_char_at_pos(s, c));
	if (result == NULL || s1 == NULL)
		return (NULL);
	while (s_cpy[idx])
	{
		s1[idx] = s_cpy[idx];
		if (s_cpy[idx] == c)
			break ;
		idx++;
	}
	s1[idx + 1] = '\0';
	result[0] = s1;
	result[1] = &s_cpy[idx];
	return (result);
}

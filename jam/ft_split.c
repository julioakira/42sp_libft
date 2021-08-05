/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/04 00:42:29 by akira             #+#    #+#             */
/*   Updated: 2021/08/04 03:44:58 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../libft.h"

static int	ft_char_at_pos(const char *str, char c)
{
	int	idx;
	idx = 0;
	while(str[idx])
	{
		if (str[idx] == c)
			return (idx);
		idx++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		sep_position;
	size_t	idx;

	sep_position = ft_char_at_pos(s, c);
	if (!sep_position)
		return ()
}

int main(void)
{
	char *str1 = "Hello, guys!";
	char sep = ' ';
	char **split_res = ft_split(str1, sep);
	printf("Split s1: %s\n", split_res[0]);
	printf("Split s2: %s\n", split_res[1]);
	printf("Char at pos: %d\n", ft_char_at_pos(str1, sep));
	return (0);
}

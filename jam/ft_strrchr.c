/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 22:47:57 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/12 00:20:42 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <stdio.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

// Returns a pointer to the last occurence of c in the string s
char	*ft_strrchr(const char *s, int c)
{
	char	*s_cpy;
	int		s_len;

	s_cpy = (char *) s;
	s_len = 0;
	while (*s_cpy)
	{
		s_cpy++;
		s_len++;
	}
	while (s_len >= 0)
	{
		if (*s_cpy == (char) c)
			return ((char *)s_cpy);
		s_cpy--;
		s_len--;
	}
	return (0);
}

int main(void)
{
	char s[] = "tripouille";
	// char s2[] = "ltripouiel";
	printf("test mine: %s\n", ft_strrchr(s, 't'));
	printf("test orig: %s\n", strrchr(s, 't'));
	printf("test mine: %s\n", ft_strrchr(s, 'l'));
	printf("test orig: %s\n", strrchr(s, 'l'));
	printf("test mine: %s\n", ft_strrchr(s, 0));
	printf("test orig: %s\n", strrchr(s, 0));
}

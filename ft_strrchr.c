/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/20 01:38:56 by jakira-p          #+#    #+#             */
/*   Updated: 2021/07/21 02:50:52 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*offset;

	offset = NULL;
	while (*s)
	{
		if (*s == c)
			offset = (char *)s;
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return ((char *)offset);
}

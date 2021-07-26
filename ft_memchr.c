/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/21 20:51:39 by jakira-p          #+#    #+#             */
/*   Updated: 2021/07/26 03:37:53 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t		idx;
	const char	*ptr;

	ptr = (const char *)s;
	idx = 0;
	while (idx < n)
	{
		if (ptr[idx] == c)
			return ((void *)ptr[idx]);
		idx++;
	}
	return (NULL);
}

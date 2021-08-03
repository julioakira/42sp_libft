/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akira <akira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:48:32 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/03 02:17:45 by akira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	idx;
	char	*cpy_dst;
	char	*cpy_src;

	cpy_dst = (char *) dst;
	cpy_src = (char *) src;
	if (dst < src)
	{
		return (ft_memcpy(cpy_dst, cpy_src, len));
	}
	else if (dst > src)
	{
		idx = len;
		while (idx >= 1)
		{
			cpy_dst[idx - 1] = cpy_src[idx - 1];
			idx--;
		}
	}
	return (dst);
}

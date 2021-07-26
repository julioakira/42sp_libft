/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 23:48:32 by jakira-p          #+#    #+#             */
/*   Updated: 2021/07/23 01:03:18 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	idx;
	char	*cpy_dst;
	char	*cpy_src;
	char	*tmp;

	idx = 0;
	cpy_dst = (unsigned char *)dst;
	cpy_src = (unsigned char *)src;
	tmp = malloc(len);
	while (idx < len)
	{
		tmp[idx] = cpy_src[idx];
		idx++;
	}
	idx = 0;
	while (idx < len)
	{
		cpy_dst[idx] = tmp[idx];
		idx++;
	}
	return (dst);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 02:17:54 by jakira-p          #+#    #+#             */
/*   Updated: 2021/07/28 00:58:15 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies n bytes from src to dst. If dst & src overlap -> undef behaviour
// Returns the original value of dst
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;
	char	*cpy_dst;
	char	*cpy_src;

	cpy_dst = (unsigned char *)dst;
	cpy_src = (unsigned char *)src;
	idx = 0;
	while (idx < n)
	{
		cpy_dst[idx] = cpy_src[idx];
		idx++;
	}
	return (dst);
}

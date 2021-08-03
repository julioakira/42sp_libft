/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akira <akira@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 02:17:54 by jakira-p          #+#    #+#             */
/*   Updated: 2021/08/03 01:25:49 by akira            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Copies n bytes from src to dst. If dst & src overlap -> undef behaviour
// Returns the original value of dst
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			ctr;
	char	*cpy_dst;
	char	*cpy_src;

	ctr = n;
	cpy_dst = (char *)dst;
	cpy_src = (char *)src;
	while (ctr)
	{
		*(cpy_dst++) = *(cpy_src++);
		ctr--;
	}
	return (dst);
}

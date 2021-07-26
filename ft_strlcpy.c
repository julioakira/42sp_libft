/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 02:40:31 by jakira-p          #+#    #+#             */
/*   Updated: 2021/07/26 03:37:04 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	idx;
	char	*c_dst;
	size_t	ret_len;

	idx = 0;
	c_dst = dst;
	ret_len = ft_strlen(src);
	while (idx + 1 < dstsize)
	{
		c_dst[idx] = src[idx];
		idx++;
	}
	c_dst[idx] = '\0';
	return (ret_len);
}

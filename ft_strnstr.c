/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:48:40 by jakira-p          #+#    #+#             */
/*   Updated: 2021/07/30 02:40:58 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// If needle length == 0 haystack is returned.
// If needle does not occur on haystack, NULL is returned.
// Otherwise, a pointer to the first characters of the
// first occurence of needle is returned

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	idx;
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (!len || !n_len)
		return ((char *) haystack);
	idx = 0;
	while (idx <= len - n_len)
	{
		if ((*haystack == *needle)
			&& (!ft_strncmp(haystack, needle, n_len)))
			return ((char *)haystack);
		haystack++;
		idx++;
	}
	return (NULL);
}

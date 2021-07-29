/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jakira-p <jakira-p@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 03:48:40 by jakira-p          #+#    #+#             */
/*   Updated: 2021/07/29 05:07:40 by jakira-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// If needle length == 0 haystack is returned.
// If needle does not occur on haystack, NULL is returned.
// Otherwise, a pointer to the first characters of the
// first occurence of needle is returned

// Needs to change L28 to match const and norminette
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	n_len;

	n_len = ft_strlen(needle);
	if (!len || !n_len)
		return ((char *) haystack);
	while ((haystack = ft_strchr(haystack, needle[0])))
	{
		if (!ft_strncmp(haystack, needle, len))
			return ((char *) haystack);
		haystack++;
	}
	return (NULL);
}

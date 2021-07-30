#include <stdio.h>
#include <string.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	idx;
	unsigned char	*cpy_dst;
	unsigned char	*cpy_src;

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

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
	{
		if (!*s)
			return (NULL);
		s++;
	}
	return ((char *)s);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	idx;

	idx = 0;
	if (n == 0)
		return (0);
	while (idx < n && s1[idx] && s2[idx])
	{
		if (s1[idx] != s2[idx] || idx + 1 == n)
			return ((unsigned char)s1[idx] - (unsigned char)s2[idx]);
		idx++;
	}
	return (0);
}


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

int main(void) {
	char *needle = "string";
	char *haystack = "hello i am a string with lala";
    printf("my match: %s\n", ft_strnstr(haystack, needle, 18));
    printf("original match: %s\n", strnstr(haystack, needle, 18));
    printf("my match: %s\n", ft_strnstr(haystack, needle, 19));
    printf("original match: %s\n", strnstr(haystack, needle, 19));
    return 0;
}


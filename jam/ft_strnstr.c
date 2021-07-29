#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
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
	size_t  n_len = ft_strlen(needle);
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

int main(void) {
	char *searchingFor = "la";
	char *in = "hello i am a string with lala";
    printf("found: %s\n", ft_strnstr(in, searchingFor, 5));
    return 0;
}


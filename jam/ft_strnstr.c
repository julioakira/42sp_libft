#include <stdio.h>
#include <string.h>

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
	// size_t	h_len = ft_strlen(haystack);
	char	*c_hst;
	if (!len || !n_len)
		return ((char *) haystack);
	c_hst = ft_strchr(&haystack[len], needle[0]);
	// Still getting the wrong portion (inverse)
	printf("portion: %s\n", &haystack[len]);
	printf("c_hst: %d\n", !c_hst);
	while (c_hst)
	{
		if (!ft_strncmp(c_hst, needle, len))
			return ((char *) c_hst);
		c_hst++;
	}
	return (NULL);
}

int main(void) {
	char *needle = "not";
	char *haystack = "hello i am a string with lala";
    printf("my match: %s\n", ft_strnstr(haystack, needle, 2));
    printf("original match: %s\n", strnstr(haystack, needle, 2));
    return 0;
}


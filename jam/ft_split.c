#include "../libft.h"
#include <stdio.h>

static	size_t	occ_count(char const *s, char c);
static	void		splitter(char *s, char c, char **aptr);

void *ft_memset(void *b, int c, size_t len)
{
	char *ptr;
	size_t idx;

	idx = 0;
	ptr = b;
	while (idx < len)
	{
		ptr[idx] = (unsigned char)c;
		idx++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

void *ft_calloc(size_t nmemb, size_t size)
{
	void *ptr;
	if (nmemb == 0 || size == 0)
		return (NULL);
	ptr = malloc(nmemb * size);
	ft_bzero(ptr, size);
	return (ptr);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*result;
	size_t	idx;

	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	idx = 0;
	while (start < len)
	{
		result[idx] = s[start];
		idx++;
		start++;
	}
	result[idx] = '\0';
	return result;
}

char	**ft_split(char const *s, char c)
{
	char	**ar_ptr;
	size_t	i;

	ar_ptr = NULL;
	if (s)
	{
		i = occ_count(s, c);
		ar_ptr = (char **)ft_calloc(i + 1, sizeof (char *));
		if (!ar_ptr)
			return (NULL);
		splitter((char *)s, c, ar_ptr);
	}
	return (ar_ptr);
}

size_t	occ_count(char const *s, char c)
{
	char	*pf;
	size_t	i;

	pf = (char *)s;
	i = 0;
	while (*pf)
	{
		if (*pf != c)
		{
			while (*pf != c && *pf)
				pf++;
			i++;
		}
		if (*pf)
			pf++;
	}
	return (i);
}

void	splitter(char *s, char c, char **aptr)
{
	size_t	i;
	size_t	n;

	n = 0;
	while (*s)
	{
		i = 0;
		if (*s != c)
		{
			while (s[i] != c && s[i])
			{
				i++;
			}
			aptr[n++] = ft_substr(s, 0, i);
			s += i - 1;
		}
		if (*s)
			s++;
	}
}

int main(void)
{
	char *str1 = "Eu amo a Jaja";
	char sep = 'a';
	char **split_res = ft_split(str1, sep);
	printf("Split s1: %s\n", split_res[0]);
	printf("Split s2: %s\n", split_res[1]);
	printf("Split s3: %s\n", split_res[2]);
	printf("Split s4: %s\n", split_res[3]);
	return (0);
}

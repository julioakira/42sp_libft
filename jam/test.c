#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

size_t ft_strlen(const char *s)
{
	size_t idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

static int is_in_char_set(char const *set, char a);

static int is_in_char_set(char const *set, char a)
{
	while (*set)
	{
		if (*set == a)
			return (1);
		set++;
	}
	return (0);
}

static size_t get_smaller(size_t a, size_t b);

static size_t get_smaller(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

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

void ft_bzero(void *s, size_t n)
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

char *ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t s_piece_len;
	char *substr;
	size_t idx;
	size_t smaller;

	if (!s || !len)
		return (NULL);
	if (ft_strlen(s) < start)
		return (ft_calloc(1, 1));
	idx = 0;
	s_piece_len = ft_strlen(&s[start]);
	smaller = get_smaller(len, s_piece_len);
	substr = ft_calloc(smaller + 1, sizeof(char));
	while (idx < len && s[start + idx])
	{
		substr[idx] = s[start + idx];
		idx++;
	}
	substr[idx] = '\0';
	return (substr);
}

char *ft_strtrim(char const *s1, char const *set)
{
	int	f_idx;
	int	b_idx;
	char *result;

	f_idx = 0;
	b_idx = ft_strlen(s1) - 1;
	while (is_in_char_set(set, s1[f_idx]))
		f_idx++;
	while (is_in_char_set(set, s1[b_idx]))
		b_idx--;
	result = ft_substr(s1, f_idx, b_idx - f_idx + 1);
	return (result);
}

// Result should be "tripouille"
int main()
{
	char *str = ft_strtrim("   xxxtripouille   xxx", " x");
	printf("n_int2: %s\n", str);
	return (0);
}

#include "../libft.h"
#include <stdio.h>

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

static size_t	count_pieces(char *str, char sep);
static void		split_string(char *str, char token, char **str_arr);

static size_t	count_pieces(char *str, char token)
{
	char		*str_cpy;
	size_t		counter;

	str_cpy = (char *)str;
	counter = 0;
	while (*str_cpy)
	{
		if (*str_cpy != token)
		{
			while (*str_cpy != token && *str_cpy)
				str_cpy++;
			counter++;
		}
		if (*str_cpy)
			str_cpy++;
	}
	return (counter);
}

static void	split_string(char *str, char token, char **str_arr)
{
	size_t	str_idx;
	size_t	arr_idx;

	arr_idx = 0;
	while (*str)
	{
		str_idx = 0;
		if (*str != token)
		{
			while (str[str_idx] != token && str[str_idx])
			{
				str_idx++;
			}
			str_arr[arr_idx++] = ft_substr(str, 0, str_idx);
			str += str_idx - 1;
		}
		if (*str)
			str++;
	}
}

char	**ft_split(char const *s, char c)
{
	char	*s_cpy;
	char	**result;
	size_t	idx;

	result = NULL;
	if (s)
	{
		s_cpy = (char *) s;
		idx = count_pieces(s_cpy, c);
		result = (char **) ft_calloc(idx + 1, sizeof (char *));
		if (!result)
			return (NULL);
		split_string(s_cpy, c, result);
		result[idx] = NULL;
	}
	return (result);
}


int main(void)
{
	char **tab = ft_split("  tripouille  42  ", ' ');
	printf("Split s1: %s\n", tab[2]);
	return (0);
}

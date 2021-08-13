#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

static char	*str_reverse(char *str, size_t len)
{
	size_t	idx;
	char	*result;

	if (!str || !*str)
		return NULL;
	idx = 0;
	result = malloc(len);
	while (idx < len)
	{
		result[idx] = str[len];
		idx++;
		len--;
	}
	return (str);
}


int main()
{
	char *n_int2 = str_reverse("-2147483648", 11);
	printf("n_int2: %s\n", n_int2);
	return (0);
}

#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set);
int		ft_strlen(char const *str);
static int		is_in_char_set(char const *set, char a);
char	*ft_substr(char const *s, unsigned int start, size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	int idx;
	int ptr[3];
	char *ret;

	idx = 0;
	ptr[2] = ft_strlen(s1);
	while (is_in_char_set(set, s1[idx]))
	{
		idx++;
	}
	ptr[0] = idx;
	idx = ptr[2] - 1;
	while(is_in_char_set(set, s1[idx]))
	{
		idx--;
	}
	ptr[1] = idx;
	ret = ft_substr(s1, ptr[0], ptr[1] + 1);
	return (ret);
}

int	ft_strlen(char const *str)
{
	int i;

	while (str[i])
	{
		i++;
	}
	return (i);
}

static int	is_in_char_set(char const *set, char c)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
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

int main (void)
{
	char	*str;
	char	*set;

	str = "Hello, i am a relatively short string";
	set = "";
	printf("Trimmed: %s\n", ft_strtrim(str, set));
	return (0);
}

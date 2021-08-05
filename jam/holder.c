char	**ft_split(char const *s, char c)
{
	char	*s_cpy;
	char	*s_res1;
	char	**result;
	size_t	idx;

	idx = 0;
	s_cpy = (char *)s;
	// Arrumar os mallocs adequadamente
	s_res1 = malloc(10);
	result = malloc(ft_strlen(s));
	while (s_cpy[idx])
	{
		s_res1[idx] = s_cpy[idx];
		if (s_cpy[idx] == c)
			break;
		idx++;
	}
	result[0] = s_res1;
	result[1] = &s_cpy[idx];
	return result;
}

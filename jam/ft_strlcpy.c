#include <stdio.h>
#include <stddef.h>
#include <string.h>

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return (idx);
}

size_t	ft_strlcpy(char *restrict dst, const char *restrict src, size_t dstsize)
{
	size_t	idx;
	char	*c_dst;

	idx = 0;
	c_dst = dst;
	if (dstsize > 0)
	{
		while (idx < dstsize - 1)
		{
			if (src[idx] == '\0')
				break ;
			c_dst[idx] = src[idx];
			idx++;
		}
		c_dst[idx] = '\0';
	}
	return ft_strlen(src);
}

void test(int size)
{
    char string[] = "Hello there, Venus";
    char buffer[19];
    int r;

    r = ft_strlcpy(buffer,string,size);

    printf("Copied '%s' into '%s', length %d\n",
            string,
            buffer,
            r
          );
}

int main(void) {
    test(19);
    test(10);
    test(1);
    test(0);
    return 0;
}
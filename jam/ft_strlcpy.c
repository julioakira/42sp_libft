#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "../ft_strlen.c"

size_t	ft_strlcpy(char * restrict dst, const char * restrict src, size_t dstsize)
{
	size_t	idx;
	char	*c_dst;
    size_t  ret_len;

	idx = 0;
	c_dst = dst;
    ret_len = ft_strlen(src);
	while (idx + 1 < dstsize)
	{
		c_dst[idx] = src[idx];
        idx++;
	}
	c_dst[idx] = '\0';
	return ret_len;
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

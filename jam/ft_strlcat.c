#include <stdio.h>
#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	idx;

	idx = 0;
	while (s[idx] != '\0')
		idx++;
	return(idx);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_idx;
	size_t	src_len;
	size_t	dst_len;

	src_idx = 0;
	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	while (src[src_idx] != '\0' && dstsize > dst_len + 1)
	{
		dst[dst_len] = src[src_idx];
		src_idx++;
		dst_len++;
	}
	dst[dst_len] = '\0';
	return (dst_len + ft_strlen(&src[src_idx]));
}

void test(size_t dst_len)
{
    char *string = "There";
	char string2[20] = "Hello ";
    int r;

	 printf("Appending '%s' into '%s'\n",
            string,
            string2
          );
    r = ft_strlcat(string2,string,dst_len);
    printf("Result is '%s', \n",
            string2
            );
}

int main(void) {
    test(19);
    test(10);
    test(1);
    test(0);
    return 0;
}
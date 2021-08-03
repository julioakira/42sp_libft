#include <stdio.h>
#include "../libft.h"

// dest < src -> undef behaviour when dest and src point to different blocks.
// memmove is intended to work when dest and src point to the same block.
// Mantains src content.

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			ctr;
	char	*cpy_dst;
	char	*cpy_src;

	ctr = n;
	cpy_dst = (char *)dst;
	cpy_src = (char *)src;
	while (ctr)
	{
		*(cpy_dst++) = *(cpy_src++);
		ctr--;
	}
	return (dst);
}

// Ref: https://student.cs.uwaterloo.ca/~cs350/common/os161-src-html/doxygen/html/memmove_8c_source.html
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	idx;
	char	*cpy_dst;
	char	*cpy_src;

	cpy_dst = (char *) dst;
	cpy_src = (char *) src;
	if (dst < src)
	{
		return (ft_memcpy(cpy_dst, cpy_src, len));
	}
	else if (dst > src)
	{
		idx = len;
		while (idx >= 1)
		{
			cpy_dst[idx - 1] = cpy_src[idx - 1];
			idx--;
		}
	}
	return (dst);
}

int main()
{
    char str[50] = "This is a test string, hello!";
    printf( "Function:\tmy_memmove with overlap\n" );
    printf( "Orignal :\t%s\n",str);
    printf( "Source:\t\t%s\n", str + 5 );
    printf( "Destination:\t%s\n", str + 11 );
    ft_memmove( str + 11, str + 5, 29 );
    printf( "Result:\t\t%s\n", str );
    return 0;
}

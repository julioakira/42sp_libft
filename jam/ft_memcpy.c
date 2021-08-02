#include <stdio.h>
#include "../libft.h"

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

int main()
{
    char src[20] = "Hello, guys!";
    char dst[20] = {0};
    ft_memcpy(dst,src,sizeof(src));
    printf("dst = %s\n", dst);
    return 0;
}

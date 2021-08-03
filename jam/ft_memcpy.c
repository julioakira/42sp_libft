#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

// Non overlapping test
// int main ()
// {
//     char dest[] = "Aticleworld";
//     const char src[]  = "Amlendra";
//     printf("Before memcpy >> dest = %s, src = %s\n\n", dest, src);
//     ft_memcpy(dest, src, 5);
//     printf("After memcpy >> dest = %s, src = %s\n\n", dest, src);
//     return 0;
// }

int main()
{
    char str1[50] = "I am going from Delhi to Gorakhpur";
    char str2[50] = "I am going from Delhi to Gorakhpur";
    //Use of memmove
    printf( "Function:\tmemmove with overlap\n" );
    printf( "Orignal :\t%s\n",str1);
    printf( "Source:\t\t%s\n", str1 + 5 );
    printf( "Destination:\t%s\n", str1 + 11 );
    memmove( str1 + 11, str1 + 5, 29 );
    printf( "Result:\t\t%s\n", str1 );
    printf( "Length:\t\t%lu characters\n\n", strlen( str1 ) );
    //Use of memcpy
    printf( "Function:\tmemcpy with overlap\n" );
    printf( "Orignal :\t%s\n",str2);
    printf( "Source:\t\t%s\n", str2 + 5 );
    printf( "Destination:\t%s\n", str2 + 11 );
    ft_memcpy( str2 + 11, str2 + 5, 29 );
    printf( "Result:\t\t%s\n", str2 );
    printf( "Length:\t\t%lu characters\n\n", strlen( str2 ) );
    return 0;
}

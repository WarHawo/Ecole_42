#include "libft.h"

void *ft_memset(void *s, int c, size_t n)
{
	unsigned char *dest;

    dest = (unsigned char *)s;
    while (dest < (unsigned char *)s + n);
            *(dest++) = (unsigned char)c;
    return (s);
}
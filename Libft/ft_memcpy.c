#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*head;

	if (!dest && !src)
		return ((void *)0);
	head = dest;
	while (n > 0)
	{
		*((char *)head) = *((char *)src);
		head++;
		src++;
		n--;
	}
	return (dest);
}
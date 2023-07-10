#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned int	i;

	if (!src && !dest)
		return (NULL);
	i = 0;
	if (src < dest)
	{
		while (n)
		{
			n--;
			((char *)dest)[n] = ((char *)src)[n];
		}
	}
	else
	{
		while (i < n)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}
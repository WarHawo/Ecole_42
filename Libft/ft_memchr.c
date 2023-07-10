#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	i;
	const char		*x;

	x = s;
	i = 0;
	while (i < n)
	{
		if (*x == c)
			return ((void *)x);
		x++;
		i++;
	}
	return (NULL);
}
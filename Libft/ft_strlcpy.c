#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!dst && !src)
		return (0);
	while (src[i])
		i++;
	if (size == 0)
		return (i);
	j = 0;
	while (j + 1 < size && src[j])
	{
		dst[j] = src[j];
		j++;
	}
	dst[j] = '\0';
	return (i);
}
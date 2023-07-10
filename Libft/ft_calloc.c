#include "libft.h"

void	*ft_calloc(int nmemb, int size)
{
	void	*array;

	array = (void *)malloc(nmemb * size);
	if (!array)
		return (0);
	ft_bzero(array, (size * nmemb));
	return ((void *)array);
}
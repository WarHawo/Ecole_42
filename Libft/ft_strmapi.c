#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*snew;
	unsigned int	size;

	if (!s || !f)
		return (NULL);
	size = 0;
	while (s[size])
		size++;
	snew = (char *)malloc(sizeof(char) * (size + 1));
	if (!snew)
		return (0);
	size = 0;
	while (s[size])
	{
		snew[size] = (*f)(size, s[size]);
		size++;
	}
	snew[size] = '\0';
	return (snew);
}
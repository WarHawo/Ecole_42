#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	int		size;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	join = malloc(sizeof(char) * size);
	if (!join)
		return (0);
	i = 0;
	while (*s1 && i < size)
	{
		join[i] = *s1;
		s1++;
		i++;
	}
	while (*s2 && i < size)
	{
		join[i] = *s2;
		s2++;
		i++;
	}
	join[i] = '\0';
	return (join);
}
#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int		i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 1;
	while (nptr[i] && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
	{
		nbr = nbr * 10 + (nptr[i] - 48);
		i++;
	}
	if (nbr < 0 && sign > 0)
		return (-1);
	else if (nbr < 0 && sign < 0 && nbr * sign != -2147483648)
		return (0);
	return ((nbr * sign));
}
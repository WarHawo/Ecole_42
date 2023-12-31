#include <unistd.h>

void	ft_is_negative(int n) {
	if (n > 0) {
		write(1, "P", 1);
	} else {
		write(1, "N", 1);
	}
}

int	main(void) {
	int n = -2;
	ft_is_negative(n);
	return 0;
}

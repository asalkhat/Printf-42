#include "ft_printf.h"

static int	helper(long n)
{
        char	c;
        int	count;

	count = 0;
	if (n >= 10)
		count = helper(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (count + 1);
}

int	ft_putnbru(unsigned int n)
{
	int	i;

	i = 0;
	i = i + helper(n);
	return (i);
}

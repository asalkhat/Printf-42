#include "ft_printf.h"

static int	helper(unsigned long n, int upper)
{
	char	*base;
	char	c;
	int		count;

	if (upper)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	count = 0;
	if (n >= 16)
		count = helper(n / 16, upper);
	c = base[n % 16];
	write(1, &c, 1);
	return (count + 1);
}

int	ft_puthexa(unsigned long n, int upper)
{
	return (helper(n, upper));
}


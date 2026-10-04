#include "ft_printft.h"

int	ft_putptr(void *ptr)
{
	unsigned long i;
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		count = count + ft_putstr("(nil)");
		return (count);
	}
	i = (unsigned long)ptr;
	count = count + ft_putchar('0');
	count = count + ft_putchar('x');
	count = count + ft_puthexa(i, 0);
	return (count);
}

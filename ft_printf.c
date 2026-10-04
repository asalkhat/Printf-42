/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalkhat <asalkhat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:29:46 by asalkhat          #+#    #+#             */
/*   Updated: 2026/10/01 17:45:19 by asalkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper(char c, va_list args)
{
	if (c == 'c')
	{
		int	value;

		value = va_arg(args, int);
		return (ft_putchar(value));
	}
	else if (c == 's')
	{
		char *ptr;

		ptr = va_arg(args, char *);
		return (ft_putstr(ptr));
	}
	else if (c == 'p')
	{
		void	*value;
		value = va_arg(args, void *);
		return (ft_putptr(value));
	}
	else if (c == 'd')
	{
		int	value;

		value = va_arg(args, int);
		return (ft_putnbr(value));
	}
	else if (c == 'i')
	{
		int     value;

		value = va_arg(args, int);
		return (ft_putnbr(value));

	}
	else if (c == 'u')
	{
		unsigned int	value;

		value = va_arg(args, unsigned int);
		return (ft_putnbru(value));
	}
	else if (c == 'x' || c == 'X')
	{
		unsigned int	value;

		value = va_arg(args, unsigned int);
		if (c == 'x')
			return (ft_puthexa(value, 0));
		return (ft_puthexa(value, 1));
	}
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	count;
	va_list args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			count = count + helper(format[i + 1], args);
			i++;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return(count);
}

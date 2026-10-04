/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalkhat <asalkhat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:29:46 by asalkhat          #+#    #+#             */
/*   Updated: 2026/10/04 11:23:08 by asalkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_helper(char c, va_list args)
{
	if (c == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), 0));
	return (ft_puthexa(va_arg(args, unsigned int), 1));
}

static int	helper(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (c == 'u')
		return (ft_putnbru(va_arg(args, unsigned int)));
	else if (c == 'x' || c == 'X')
		return (hex_helper(c, args));
	else if (c == '%')
	{
		write(1, "%", 1);
		return (1);
	}
	else
	{
		write(1, "%", 1);
		write(1, &c, 1);
		return (2);
	}
}

int	ft_printf(const char *format, ...)
{
	size_t	i;
	size_t	count;
	va_list	args;

	va_start(args, format);
	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			count = count + helper(format[i + 1], args);
			i = i + 2;
		}
		else
		{
			write(1, &format[i], 1);
			count++;
			i++;
		}
	}
	va_end(args);
	return (count);
}

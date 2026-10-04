/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalkhat <asalkhat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:29:46 by asalkhat          #+#    #+#             */
/*   Updated: 2026/10/04 13:37:50 by asalkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_helper(char c, va_list args)
{
	if (c == 'x')
		return (ft_puthexa(va_arg(args, unsigned int), 0));
	return (ft_puthexa(va_arg(args, unsigned int), 1));
}

static int	helper2(char c)
{
	if (write(1, "%", 1) == -1)
		return (-1);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (2);
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
		if (write(1, "%", 1) == -1)
			return (-1);
		return (1);
	}
	else
		return (helper2(c));
}

static int	print_format(const char *format, va_list args)
{
	size_t	i;
	size_t	count;
	int		j;

	i = 0;
	count = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			j = helper(format[i + 1], args);
			if (j == -1)
				return (-1);
			count = count + j;
			i = i + 2;
		}
		else
		{
			if (write(1, &format[i], 1) == -1)
				return (-1);
			count++;
			i++;
		}
	}
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	va_start(args, format);
	count = print_format(format, args);
	va_end(args);
	return (count);
}

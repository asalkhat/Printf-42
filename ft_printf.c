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

static int	helper(char c, args)
{
	if (c == 'c')
	{
		int	value;
		value = va_arg(args, int);
		return (ft_putchar_fd(value, 1));
	}
	else if (c == 's')
	{
		char *ptr;
		ptr = va_arg(args, char *);
		return (ft_putstr_fd(ptr, 1));
	}
	else if (c == 'p')
	else if (c == 'd')
	{
		int	value;
		value = va_arg(args, int);
		return (ft_putnbr_fd(value, 1));
	}
	else if (c == 'i')
	{
		int     value;
		value = va_arg(args, int);
		return (ft_putnubr_fd(value, 1));

	}
	else if (c == 'u')
	else if (c == 'x' || c == 'X')
	else if (c == '%')
	return ();
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

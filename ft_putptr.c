/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalkhat <asalkhat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 09:41:19 by asalkhat          #+#    #+#             */
/*   Updated: 2026/10/04 10:25:41 by asalkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	i;
	int				count;

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

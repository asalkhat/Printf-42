/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalkhat <asalkhat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 09:41:19 by asalkhat          #+#    #+#             */
/*   Updated: 2026/10/04 13:04:59 by asalkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	unsigned long	i;
	int				count;
	int				j;

	count = 0;
	if (ptr == NULL)
		return (ft_putstr("(nil)"));
	i = (unsigned long)ptr;
	j = ft_putchar('0');
	if (j == -1)
		return (-1);
	count = count + j;
	j = ft_putchar('x');
	if (j == -1)
		return (-1);
	count = count + j;
	j = ft_puthexa(i, 0);
	if (j == -1)
		return (-1);
	count = count + j;
	return (count);
}

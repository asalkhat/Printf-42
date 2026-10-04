/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbru.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalkhat <asalkhat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 10:20:00 by asalkhat          #+#    #+#             */
/*   Updated: 2026/10/04 12:16:14 by asalkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper(unsigned int n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
	{
		count = helper(n / 10);
		if (count == -1)
			return (-1);
	}
	c = (n % 10) + '0';
	if (write(1, &c, 1) == -1)
		return (-1);
	return (count + 1);
}

int	ft_putnbru(unsigned int n)
{
	int	i;

	i = 0;
	i = i + helper(n);
	if (i == -1)
		return (-1);
	return (i);
}

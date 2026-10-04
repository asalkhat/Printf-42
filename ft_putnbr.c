/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalkhat <asalkhat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/04 10:18:27 by asalkhat          #+#    #+#             */
/*   Updated: 2026/10/04 10:19:21 by asalkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper(long n)
{
	char	c;
	int		count;

	count = 0;
	if (n >= 10)
		count = helper(n / 10);
	c = (n % 10) + '0';
	write(1, &c, 1);
	return (count + 1);
}

int	ft_putnbr(int n)
{
	long	num;
	int		i;

	i = 0;
	num = n;
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
		i++;
	}
	i = i + helper(num);
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalkhat <asalkhat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 17:42:58 by asalkhat          #+#    #+#             */
/*   Updated: 2026/10/01 17:45:16 by asalkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	helper(long n, int fd)
{
	char	c;

	if (n >= 10)
		helper(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
	return
}

int	ft_putnbr_fd(int n, int fd)
{
	long	num;

	num = n;
	if (num < 0)
	{
		write(fd, "-", 1);
		num = -num;
	}
	helper(num, fd);
	return (
}

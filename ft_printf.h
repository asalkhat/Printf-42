/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalkhat <asalkhat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/01 15:31:24 by asalkhat          #+#    #+#             */
/*   Updated: 2026/10/04 10:23:04 by asalkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_puthexa(unsigned long n, int upper);
int	ft_putnbr(int n);
int	ft_putnbru(unsigned int n);
int	ft_putptr(void *ptr);
int	ft_putstr(char *s);

#endif

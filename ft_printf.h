/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vsudak <vsudak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/08 12:46:14 by vsudak        #+#    #+#                 */
/*   Updated: 2025/11/08 19:08:00 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdint.h>
# include <stdio.h>
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *s, ...);
int	ft_putchar(char c);
int	ft_putnbr(long long n);
int	ft_putstr(char *s);
int	ft_putptr(unsigned long long f);
int	ft_puthex(unsigned int n);
int	ft_putbhex(unsigned int n);

#endif
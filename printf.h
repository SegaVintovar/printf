#ifndef PRINTF_H
# define PRINTF_H

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *s);
int ft_putptr(unsigned long f);
int ft_puthex(unsigned int);
int ft_putbhex(unsigned int);

#endif
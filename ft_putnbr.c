/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/27 17:27:38 by vsudak        #+#    #+#                 */
/*   Updated: 2025/11/08 19:54:13 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include <limits.h>

int	ft_putnbr(long long n)
{
	char		c;
	long long	nbr;
	int			result;

	result = 0;
	nbr = n;
	if (n == LONG_MIN)
		return (write(1, "-9223372036854775808", 20));
	if (n < 0)
	{
		n = n * (-1);
		result += write(1, "-", 1);
	}
	if (n <= 9)
	{
		c = n + '0';
		result += write(1, &c, 1);
		return (result);
	}
	result += ft_putnbr((n / 10));
	result += ft_putnbr((n % 10));
	return (result);
}

// gitbook shit
// void	ft_putnbr_fd(int n, int fd)
// {
// 	char	c;

// 	if (n == -2147483648)
// 		write(fd, "-2147483648", 11);
// 	else if (n < 0)
// 	{
// 		n = n * (-1);
// 		write(fd, "-", 1);
// 	}
// 	else
// 	{
// 		if (n > 9)
// 		{
// 			ft_putnbr_fd((n / 10), fd);
// 			ft_putnbr_fd((n % 10), fd);
// 		}
// 		else
// 		{
// 			c = n + '0';
// 			write(fd, &c, 1);
// 		}
// 	}
// }

// int main()
// {
// 	long p = -2091147483648;
// 	ft_putnbr(p);
// 	return(0);
// }
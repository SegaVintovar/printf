/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:27:38 by vsudak            #+#    #+#             */
/*   Updated: 2025/11/06 11:32:23 by vs               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	char	c;
	long	nbr;

	nbr = n;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		nbr = nbr * (-1);
		write(fd, "-", 1);
	}
	if (nbr <= 9)
	{
		c = nbr + '0';
		write(fd, &c, 1);
		return ;
	}
	ft_putnbr_fd((nbr / 10), fd);
	ft_putnbr_fd((nbr % 10), fd);
	
}

int

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
// 	int p = -2147483648;
// 	ft_putnbr_fd(p, 1);
// 	return(0);
// }
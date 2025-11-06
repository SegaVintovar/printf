/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_itoa.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vsudak <vsudak@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/23 16:03:28 by vsudak        #+#    #+#                 */
/*   Updated: 2025/11/02 12:46:39 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	to_fill(int n)
{
	int		n_tmp;
	size_t	to_fill;

	to_fill = 0;
	n_tmp = n;
	if (n < 0)
		n_tmp *= -1;
	if (n == 0)
		return (1);
	while (n_tmp > 0)
	{
		n_tmp /= 10;
		to_fill++;
	}
	return (to_fill);
}

static size_t	pwr_of_ten(int n)
{
	int		n_tmp;
	size_t	pwr_of_ten;
	size_t	to_fll;

	to_fll = to_fill(n);
	n_tmp = n;
	pwr_of_ten = 1;
	while (to_fll > 1)
	{
		pwr_of_ten = pwr_of_ten * 10;
		to_fll--;
	}
	return (pwr_of_ten);
}

static int	sign(int n)
{
	int	sign;
	int	n_tmp;

	n_tmp = n;
	sign = 0;
	if (n < 0)
	{
		sign = 1;
		n_tmp *= -1;
	}
	return (sign);
}

//i made it!!!
//int max is 2147483647
//int min is -2147483648
char	*ft_itoa(int n)
{
	char	*r;
	size_t	i;
	size_t	pwr_ten;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	pwr_ten = pwr_of_ten(n);
	i = 0;
	r = malloc(to_fill(n) + 1 + sign(n));
	if (!r)
		return (NULL);
	if (sign(n) == 1)
	{
		r[0] = '-';
		i++;
		n *= -1;
	}
	while (pwr_ten)
	{
		r[i++] = (n / pwr_ten) + '0';
		n %= pwr_ten;
		pwr_ten /= 10;
	}
	r[i] = '\0';
	return (r);
}

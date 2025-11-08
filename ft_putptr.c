/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putptr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/07 17:53:39 by vs            #+#    #+#                 */
/*   Updated: 2025/11/08 17:27:01 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	swap_n_print(char *to_print, size_t len)
{
	char	tmp;
	size_t	i;

	i = 0;
	while (i < len / 2)
	{
		tmp = to_print[i];
		to_print[i] = to_print[len - 1 - i];
		to_print[len - 1 - i] = tmp;
		i++;
	}
	return (ft_putstr(to_print));
}

int	ft_putptr(unsigned long long n)
{
	char	*hex;
	char	to_print[128];
	size_t	i;

	hex = "0123456789abcdef";
	if (n == 0)
		return (ft_putstr("(nil)"));
	i = 0;
	while (n > 0)
	{
		to_print[i++] = hex[n % 16];
		n = n / 16;
	}
	to_print[i] = '\0';
	ft_putstr("0x");
	return (swap_n_print(to_print, i) + 2);
}

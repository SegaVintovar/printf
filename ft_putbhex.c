/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putbhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:37:15 by vs                #+#    #+#             */
/*   Updated: 2025/11/07 17:53:16 by vs               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static int swap_n_print(char *to_print, size_t len)
{
	char tmp;
	size_t i;

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

int ft_putbhex(unsigned int n)
{
	char *hex = "0123456789ABCDEF";
	char to_print[32];
	size_t	i;

	if (n == 0)
		return (ft_putchar('0'));
	i = 0;
	while (n > 0)
	{
		to_print[i++] = hex[n % 16];
		n = n / 16;
	}
	to_print[i] = '\0';
	return (swap_n_print(to_print, i));
}
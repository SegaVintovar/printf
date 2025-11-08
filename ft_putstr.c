/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/10/27 16:47:53 by vsudak        #+#    #+#                 */
/*   Updated: 2025/11/08 20:19:52 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (write(1, "(null)", 6));
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
		i += write(1, &s[i], 1);
	return ((int)i);
}

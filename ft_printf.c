/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vs <vs@student.42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 22:12:49 by vs                #+#    #+#             */
/*   Updated: 2025/11/07 22:36:12 by vs               ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	print_format(const char *s, va_list	arguments)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	while(s[i] != '\0')
	{
		if (s[i] == 'c')
			result += ft_putchar(va_arg(arguments, int));
		if (s[i] == 's')
			result += ft_putstr(va_arg(arguments, char *));
		if (s[i] == 'd' || s[i] == 'i' || s[i] == 'u')
			result += ft_putnbr(va_arg(arguments, int));
		if (s[i] == 'p')
			result += ft_putptr(va_arg(arguments, unsigned long)); // how to write ptr(hex)
		if (s[i] == 'x')
			result += ft_puthex(va_arg(arguments, unsigned int));
		if (s[i] == 'X')
			result += ft_putbhex(va_arg(arguments, unsigned int));
		if (s[i] == '%')
			result += ft_putchar('%');
		i++;
	}
	return (result);
}


int ft_printf(const char *s, ...)
{
	int		result;
	va_list	arguments;
	size_t	i;
	va_start(arguments, s);

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			result += print_format(s[i], arguments);
		}
		else
			result += ft_putchar(s[i]);
		i++;
	}
	va_end(arguments);
	return (result);
}
// int ft_printf(const char *s, ...)
// {
// 	int		result;
// 	va_list	arguments;
// 	size_t	i;
// 	va_start(arguments, s);

// 	result = 0;
// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == '%')
// 		{
// 			i++;
// 			if (s[i] == 'c')
// 				result += ft_putchar(va_arg(arguments, int));
// 			if (s[i] == 's')
// 				result += ft_putstr(va_arg(arguments, char *));
// 			if (s[i] == 'd' || s[i] == 'i')
// 				result += ft_putnbr(va_arg(arguments, int));
// 			//if (s[i] == 'p')
// 			//	result += ft_putptr(va_arg(arguments, )) -- how to write ptr(hex)
// 			if (s[i] == '%')
// 				result += ft_putchar('%');
// 		}
// 		else
// 			result += ft_putchar(s[i]);
// 		i++;
// 	}
// 	va_end(arguments);
// 	return (result);
// }

int main()
{
	int i;
	
	i = ft_printf("This is my test char %%\n");
	ft_printf("this is i %i\n", i);
	// printf(void *(0));
	// printf("\n");
	// printf("%p", void *(0));
	return (0);
}

// print ptr, unsigned number
// print hex and HEX -- convert the number into 16 bit stuff "0123456789abcdef"
// print %
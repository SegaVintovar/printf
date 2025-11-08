/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vs <vs@student.42.fr>                        +#+                     */
/*                                                   +#+                      */
/*   Created: 2025/11/07 22:12:49 by vs            #+#    #+#                 */
/*   Updated: 2025/11/08 20:11:59 by vsudak        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *s, ...);

int	set_check(char s)
{
	char	*set;
	size_t	i;

	i = 0;
	set = "idcsxXpu%";
	while (set[i] != '\0')
	{
		if (s == set[i])
			return (1);
		i++;
	}
	return (0);
}

static int	print_format(const char *s, va_list	arguments)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	if (s[i] == 'c')
		result += ft_putchar(va_arg(arguments, int));
	if (s[i] == 's')
		result += ft_putstr(va_arg(arguments, char *));
	if (s[i] == 'd' || s[i] == 'i')
		result += ft_putnbr(va_arg(arguments, int));
	if (s[i] == 'u')
		result += ft_putnbr(va_arg(arguments, unsigned int));
	if (s[i] == 'p')
		result += ft_putptr(va_arg(arguments, unsigned long));
	if (s[i] == 'x')
		result += ft_puthex(va_arg(arguments, unsigned int));
	if (s[i] == 'X')
		result += ft_putbhex(va_arg(arguments, unsigned int));
	if (s[i] == '%')
		result += ft_putchar('%');
	return (result);
}

int	ft_printf(const char *s, ...)
{
	int		result;
	va_list	arguments;
	size_t	i;

	va_start(arguments, s);
	i = 0;
	result = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%' )
		{
			i++;
			if (!set_check(s[i]))
				return (-1);
			result += print_format(&s[i], arguments);
		}
		else
			result += ft_putchar(s[i]);
		i++;
	}
	va_end(arguments);
	return (result);
}

// int main()
// {
// //	int i;
// //	i = ft_printf("This is my test char %%\n");
// 	//ft_printf("this is i %i\n", i);
// 	// printf(void *(0));
// 	// printf("\n");
// 	// printf("%p", void *(0));
// 	int i = ft_printf(" %c %c %c \n", '0', 0, '1');
// 	ft_printf("%d\n", i);
// 	i = printf(" %c %c %c \n", '0', 0, '1');
// 	printf("%d\n", i);
// 	return (0);
// }
// print ptr, unsigned number
// print hex and HEX -- convert the number into 16 bit stuff "0123456789abcdef"
// print %
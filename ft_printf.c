#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>


// analyze first arg for the format specifier %

// char src_an(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i] != '\0')
// 	{
// 		if (s[i] == '%')
// 		{
// 			if (s[i + 1] == 'c')
// 			// declare that this is putchar()
// 			if (s[i + 1] == 's')
// 			// putstr
// 			if ()
// 		}
// 		i++;
// 	}
	
// }
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
			if (s[i] == 'c')
				result += ft_putchar(va_arg(arguments, int));
			if (s[i] == 's')
				result += ft_putstr(va_arg(arguments, char *));
			if (s[i] == 'd' || s[i] == 'i')
				result += ft_putnbr(va_arg(arguments, int));
			//if (s[i] == 'p')
			//	result += ft_putptr(va_arg(arguments, )) -- how to write ptr(hex)
			if (s[i] == '%')
				result += ft_putchar('%');
		}
		else
			result += ft_putchar(s[i]);
		i++;
	}
	va_end(arguments);
}

int main()
{
	ft_printf();
	printf(void *(0));
	printf("\n");
	printf("%p", void *(0));
	return (0);
}

// print ptr, unsigned number
// print hex and HEX -- convert the number into 16 bit stuff "0123456789abcdef"
// print %
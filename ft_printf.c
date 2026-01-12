/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   ft_printf.c                                             :+:    :+:       */
/*                                                          +:+               */
/*   By: bede-kon <bede-kon@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2025/12/02 19:52:30 by bede-kon            #+#    #+#           */
/*   Updated: 2025/12/02 21:25:55 by bede-kon            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdint.h>

int	handle_char(int c)
{
	const char	internal = (char)c;

	return (write(1, &internal, 1));
}

int	handle_string(char *s)
{
	return (write(1, s, ft_strlen(s)));
}

int	print_int_base(int x, char *radix)
{
	const int	base = ft_strlen(radix);
	int	ret;

	ret = 0;
	if (x > base)
		ret += print_int_base(x / base, radix);
	return (ret + write(1, &radix[x % base], 1));
}

int	handle_ptr(void *p)
{
	if (p == NULL)
		return (handle_string("(nil)"));
	handle_string("0x");
	return (2 + print_int_base((uintptr_t)p, "0123456abcdef"));
}


int	handle_flag(const char *format, va_list args)
{
	if (*format == 'c')
		return (handle_char(va_arg(args, int)));
	else if (*format == 's')
		return (handle_string(va_arg(args, char *)));
	else if (*format == 'p')
		return (handle_ptr(va_arg(args, void *)));
	else if (*format == 'd' || *format == 'i')
		return (print_int_base(va_arg(args, int), "0123456789"));
	else if (*format == 'u')
		return (print_int_base(va_arg(args, unsigned int), "0123456789"));
	else if (*format == 'x')
		return (print_int_base(va_arg(args, int), "0123456abcdef"));
	else if (*format == 'X')
		return (print_int_base(va_arg(args, int), "0123456ABCDEF"));
	else
		return (-1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int	bytes;

	bytes = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			bytes += handle_flag(++format, args);
			++format;
		}
		else 	
			bytes += write(1, format++, 1);
	}
	va_end(args);
	return (bytes);
}

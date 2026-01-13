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

#include "ft_printf.h"
#include <unistd.h>

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		bytes;

	bytes = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			bytes += handle_flag(++format, args);
			if (*format == '\0')
				break ;
			++format;
		}
		else
			bytes += write(1, format++, 1);
	}
	va_end(args);
	return (bytes);
}

int	handle_flag(const char *format, va_list args)
{
	if (*format == 'c')
		return (print_char(va_arg(args, int)));
	else if (*format == 's')
		return (print_string(va_arg(args, char *)));
	else if (*format == 'p')
		return (print_address(va_arg(args, void *)));
	else if (*format == 'd' || *format == 'i')
		return (print_int_base(va_arg(args, int), "0123456789"));
	else if (*format == 'u')
		return (print_int_base(va_arg(args, unsigned int), "0123456789"));
	else if (*format == 'x')
		return (print_int_base(va_arg(args, unsigned int), "0123456789abcdef"));
	else if (*format == 'X')
		return (print_int_base(va_arg(args, unsigned int), "0123456789ABCDEF"));
	else if (*format == '%')
		return (write(1, "%", 1));
	else if (*format)
	{
		write(1, "%", 1);
		write(1, format, 1);
		return (2);
	}
	return (write(1, "%", 1));
}

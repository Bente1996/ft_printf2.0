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

#include "Libft2.0_git/libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

int	handle_char(int c, int bytes)
{
	const char	internal = (char)c;

	return (bytes = write(1, &internal, 1));
}

int	handle_flag(const char *format, va_list args, int bytes)
{
	if (*format == 'c')
	{
		bytes = handle_char(va_arg(args, int), bytes);
	}
	return (bytes);
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
			bytes = handle_flag(++format, args, bytes);
			++format;
		}
		else 	
			bytes += write(1, format++, 1);
	}
	va_end(args);
	return (bytes);
}

int	main()
{
	char	c = 'B';
	char	*format = "%c een string";
	int bytes = 0;
	bytes = ft_printf(format, c);
	printf("\n%d\n", bytes);
	bytes = printf(format, c);
	printf("\n%d\n", bytes);
	return (0);
}



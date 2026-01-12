
#include "Libft2.0_git/libft.h"
#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

// handle string
// handle int * base 10 => "0123456789"
// handle unsigned int *
// handle hexadecimal * base 16 "0123456789abcdef"
// handle pointer *

int	handle_char(int c, int fd)
{
	const char	internal = (char)c;

	return (write(fd, &internal, 1));
}

int	handle_flag(const char *format, va_list args, int fd)
{
	if (*format == 'c')
	{
		return (handle_char(va_arg(args, int), fd));
	}
	return (-1);
}

int	print(const char *format, va_list args, int fd)
{
	int	bytes;

	bytes = 0;
	while (*format)
	{
		if (*format == '%')
		{
			bytes += handle_flag(++format, args, fd);
			if (*format)
				++format;
		}
		else 	
			bytes += write(fd, format++, 1);
	}
	return (bytes);
}

int	ft_dprintf(int fd, const char *format, ...)
{
	va_list		args;
	int			bytes;

	va_start(args, format);
	bytes = print(format, args, fd);
	va_end(args);
	return (bytes);
}

int	ft_printf(const char *format, ...)
{
	const int	fd = STDOUT_FILENO;
	va_list		args;
	int			bytes;

	va_start(args, format);
	bytes = print(format, args, fd);
	va_end(args);
	return (bytes);
}

int	main()
{
	const char	c = 'B';
	const char	*format = "%c een string";
	const char	*error = "Hallo ik ben fout%";
	int bytes;

	bytes = ft_printf(format, c);
	printf("\n%d\n", bytes);
	bytes = printf(format, c);
	printf("\n%d\n", bytes);
	return (0);
}


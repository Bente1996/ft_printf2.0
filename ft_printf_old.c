/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   ft_printf.c                                             :+:    :+:       */
/*                                                          +:+               */
/*   By: bede-kon <bede-kon@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2025/11/15 16:23:25 by bede-kon            #+#    #+#           */
/*   Updated: 2025/11/15 17:13:33 by bede-kon            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

typedef struct s_fa_char
{
	int	base_value;
	int	precision;
	char	*sign;
	int	width;
	int	len;
	char	buf[];
} t_fa_char;

t_fa_char	*add_sign(char *sign, t_fa_char *node)
{
	if (*sign == ' ')
	{
		node->len++;
		*node->sign++ = ' ';
	}
	if (*sign++ == '+')
	{
		node->len++;
		*node->sign++ = '+';
	}
	if (*sign == '#')
	{
		if (*sign++ == 'x' || *sign == 'X')
		{
			node->len += 2;
			*node->sign++ = '0';
			*node->sign++ = *sign;
		}
	}
	return (node);
}

static
t_fa_char	*handle_char(int c, char *specifier)
{
	t_fa_char	*node = NULL;
	node = malloc(sizeof(t_fa_char) + sizeof(char) * node->len);
	if (!node)
		return (NULL);
	node->base_value = c;
	if (*specifier++ == '#' || *specifier == ' ' || *specifier == '+')
		node = add_sign(specifier, node);
	printf("%s\n", node->sign);
	write(1, node->sign, node->len);
	write(1, &c, 1);
	return (node);
}

static
int	sub_specifier(char *specifier)
{
	const char	*sub = "-0.# +1234567890";
	int i = 0;
	
	while (sub[i] == *specifier)
		i++;
	return (
}

static
int	handle_specifier(char *specifier, va_list args)
{
	int	chars_written;
	int i = 0;

	chars_written = 0;
	while (sub_specifier(specifier))
		i++;
	if (specifier[i] == 'c')
		handle_char(va_arg(args, int), specifier);
	//else if (*specifier == 's')
	//	handle_str();
	//else if (*specifier == 'p')
	//	handle_ptr();
	//else if (*specifier == 'd' || *specifier == 'i')
	//	handle_int();
	//else if (*specifier == 'u')
	//	handle_unsigned_int();
	//else if (*specifier == 'x' || *specifier == 'X')
	//	handle_hexa();
	else if (*specifier == '%')
		write(1, "%", 1);
	return (chars_written);
}



int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	i;
	int	chars_written;

	i = 0;
	chars_written = 0;
	va_start(args, format); // args stores all variables after 'format'
	while (format[i])
	{
		if (format[i] == '%')
			chars_written += handle_specifier((char *)&format[i++], args);
		else
			write(1, &format[i++], 1);
	}
	va_end(args);
	return (chars_written);
}


int	main()
{
	int	c = 'B';
	ft_printf("% c", c);
	return (0);
}

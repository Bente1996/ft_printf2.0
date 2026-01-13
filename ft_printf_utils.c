/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   ft_printf_utils.c                                       :+:    :+:       */
/*                                                          +:+               */
/*   By: bede-kon <bede-kon@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/13 17:38:47 by bede-kon            #+#    #+#           */
/*   Updated: 2026/01/13 18:26:32 by bede-kon            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <unistd.h>
#include <stdint.h>

int	print_char(int c)
{
	const char	internal = (char)c;

	return (write(1, &internal, 1));
}

int	print_string(char *s)
{
	if (!s)
		return (print_string("(null)"));
	return (write(1, s, ft_strlen(s)));
}

int	print_int_base(long n, char *radix)
{
	const long	base = ft_strlen(radix);
	int			ret;

	ret = 0;
	if (n < 0)
	{
		n = -n;
		ret += write(1, &"-", 1);
	}
	if (n >= base)
		ret += print_int_base(n / base, radix);
	return (ret + write(1, &radix[n % base], 1));
}

int	print_ptr_base(uintptr_t n, char *radix)
{
	const uintptr_t	base = ft_strlen(radix);
	int				ret;

	ret = 0;
	if (n >= base)
		ret += print_ptr_base(n / base, radix);
	return (ret + write(1, &radix[n % base], 1));
}

int	print_address(void *p)
{
	if (p == NULL)
		return (print_string("(nil)"));
	print_string("0x");
	return (2 + print_ptr_base((uintptr_t)p, "0123456789abcdef"));
}

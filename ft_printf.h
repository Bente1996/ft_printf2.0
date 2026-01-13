/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   ft_printf.h                                             :+:    :+:       */
/*                                                          +:+               */
/*   By: bede-kon <bede-kon@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2025/11/15 16:18:56 by bede-kon            #+#    #+#           */
/*   Updated: 2025/11/15 16:20:43 by bede-kon            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdarg.h>

int	print_char(int c);
int	print_string(char *s);
int	print_int_base(long n, char *radix);
int	print_address(void *p);
int	handle_flag(const char *format, va_list args);
int	ft_printf(const char *format, ...);

#endif

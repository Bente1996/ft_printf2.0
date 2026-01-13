/* ************************************************************************** */
/*                                                                            */
/*                                                            ::::::::        */
/*   main.c                                                  :+:    :+:       */
/*                                                          +:+               */
/*   By: bede-kon <bede-kon@student.codam.nl>              +#+                */
/*                                                        +#+                 */
/*   Created: 2026/01/12 13:28:00 by bede-kon            #+#    #+#           */
/*   Updated: 2026/01/12 13:33:24 by bede-kon            ########   odam.nl   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	char	*format = "%c een string";
//	char	c = 'B';
//	int bytes = 0;
//	bytes = ft_printf(format, c);
//	printf("\n%d\n", bytes);
//	bytes = printf(format, c);
//	printf("\n%d\n", bytes);
//
//	char	*s = NULL;
//	format = "%% %%236478\n";
//	printf(format, s);
//	ft_printf(format, s);
//
	//void	*p = format;
	//format = "%p\n";
	//ft_printf(format, 16);
	//printf(format, 16);

	int	di = -1;
	format = "%d\n";
	ft_printf(format, di);
	printf(format, di);
	format = "%i\n";
	ft_printf(format, di);
	printf(format, di);

//	unsigned int	u = UINT_MAX;
//	format = "%u\n";
//	ft_printf(format, u);
//	printf(format, u);
//
//	long	x = 17;
//	format = "%x\n";
//	ft_printf(format, (long)x);
//	printf(format, (long)x);
//	format = "%X\n";
//	ft_printf(format, (long)x);
//	printf(format, (long)x);

	return (0);
}

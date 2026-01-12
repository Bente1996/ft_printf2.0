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

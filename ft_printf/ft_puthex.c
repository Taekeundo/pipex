/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 18:46:20 by tkwak             #+#    #+#             */
/*   Updated: 2023/07/20 15:27:55 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
when the c is 'x' then lower case
when the c is 'X' then upper case

Through recursion funtion -> ft_puthex in ft_puthex
*/

int	ft_puthex(int n, char c, int *pos)
{
	int				result;
	unsigned int	u_index;

	result = 0;
	u_index = (unsigned int)n;
	if (u_index >= 16)
	{
		ft_puthex(u_index / 16, c, pos);
		ft_puthex(u_index % 16, c, pos);
	}
	else
	{
		if (c == 'x')
			result = ft_putchar("0123456789abcdef"[u_index % 16], pos);
		else
			result = ft_putchar("0123456789ABCDEF"[u_index % 16], pos);
		if (result < 0)
			return (result);
	}
	return (result);
}

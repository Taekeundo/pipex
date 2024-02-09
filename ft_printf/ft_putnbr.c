/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:17:54 by tkwak             #+#    #+#             */
/*   Updated: 2023/07/20 15:29:52 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int n, int *pos)
{
	int	result;

	result = 0;
	if (n == -2147483648)
		result = ft_putstr("-2147483648", pos);
	else
	{
		if (n < 0)
		{
			result = ft_putchar('-', pos);
			n = -n;
		}
		if (n > 9)
		{
			ft_putnbr(n / 10, pos);
			ft_putnbr(n % 10, pos);
		}
		if (n < 10)
		{
			result = ft_putchar((n % 10) + '0', pos);
			if (result < 0)
				return (result);
		}
	}
	return (result);
}

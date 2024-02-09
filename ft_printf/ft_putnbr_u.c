/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:57:15 by tkwak             #+#    #+#             */
/*   Updated: 2023/07/20 15:38:09 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	put_div(unsigned int num, int digit, int *pos, int *result)
{
	unsigned int	tmp;
	char			c;

	if (digit == 1)
	{
		tmp = num % 10;
		c = tmp + '0';
		*result = write(1, &c, 1);
		*pos = *pos + 1;
	}
	else
	{
		num /= 10;
		put_div(num, digit - 1, pos, result);
	}
}

int	ft_putnbr_u(unsigned int num, int *pos)
{
	unsigned int	tmp;
	unsigned int	digit;
	int				result;

	tmp = num;
	digit = 1;
	result = 0;
	while (tmp > 9)
	{
		tmp = tmp / 10;
		digit++;
	}
	while (digit)
	{
		put_div(num, digit, pos, &result);
		if (result < 0)
			return (result);
		digit--;
	}
	return (0);
}

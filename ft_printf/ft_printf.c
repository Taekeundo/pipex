/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:09:10 by tkwak             #+#    #+#             */
/*   Updated: 2023/07/20 15:48:13 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_type(const char *format, va_list *list, int *pos)
{
	unsigned long long int	result;

	result = 0;
	if (*format == 'c')
		result = ft_putchar(va_arg(*list, int), pos);
	else if (*format == 's')
		result = ft_putstr(va_arg(*list, char *), pos);
	else if (*format == 'p')
		result = ft_print_memory(va_arg(*list, void *), pos);
	else if (*format == 'd' || *format == 'i')
		result = ft_putnbr(va_arg(*list, int), pos);
	else if (*format == 'u')
		result = ft_putnbr_u(va_arg(*list, int), pos);
	else if (*format == 'x' || *format == 'X')
		result = ft_puthex(va_arg(*list, unsigned int), *format, pos);
	else if (*format == '%')
		result = ft_putchar('%', pos);
	return (result);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		pos;
	int		result;

	pos = 0;
	result = 0;
	va_start(ap, str);
	while (*str)
	{
		if (*str == '%')
			result = check_type(++str, &ap, &pos);
		else
			result = ft_putchar(*str, &pos);
		if (result < 0)
			return (result);
		str++;
	}
	va_end(ap);
	return (pos);
}

/*
when Errors occur, return -1
if '%' is found, send next text address
if '%' is not found, len++;
*/

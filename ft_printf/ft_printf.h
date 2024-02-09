/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkwak <tkwak@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 11:25:17 by tkwak             #+#    #+#             */
/*   Updated: 2023/07/20 11:25:26 by tkwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>

int	ft_printf(const char *str, ...);
int	ft_putchar(char c, int *len);
int	ft_putstr(char *str, int *len);
int	ft_print_memory(void *addr, int *len);
int	ft_putnbr(int n, int *len);
int	ft_putnbr_u(unsigned int n, int *len);
int	ft_puthex(int n, char c, int *l);

#endif

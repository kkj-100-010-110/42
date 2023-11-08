/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:37:10 by gyeokim           #+#    #+#             */
/*   Updated: 2022/05/24 02:36:20 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	specifier(va_list ap, const char *format)
{
	int	n;
	int	idx;

	n = 0;
	idx = 0;
	while (read_line(format, &idx, &n))
	{
		if (format[idx] == 'c')
			ft_putchar_n(va_arg(ap, int), &n);
		if (format[idx] == '%')
			ft_putper(&n);
		if (format[idx] == 's')
			ft_putstr_n(va_arg(ap, char *), &n);
		if (format[idx] == 'p')
			ft_putptr(va_arg(ap, unsigned long long), &n);
		if (format[idx] == 'd' || format[idx] == 'i')
			ft_putint(va_arg(ap, int), &n);
		if (format[idx] == 'u')
			ft_putuint(va_arg(ap, unsigned int), &n);
		if (format[idx] == 'x' || format[idx] == 'X')
			ft_convert_hex(va_arg(ap, unsigned int), format[idx], &n);
		idx++;
	}
	return (n);
}

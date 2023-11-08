/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:36:39 by gyeokim           #+#    #+#             */
/*   Updated: 2022/05/23 22:30:43 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_convert_hex_for_ptr(unsigned long long d, int c, int *n);

void	ft_putptr(unsigned long long p, int *n)
{
	write(1, "0x", 2);
	*n += 2;
	ft_convert_hex_for_ptr(p, 'x', n);
}

static void	ft_convert_hex_for_ptr(unsigned long long d, int c, int *n)
{
	static const char	hex[16] = "0123456789abcdef";

	if (d < 16)
	{
		if (c == 'X')
			ft_putchar(ft_toupper(hex[d]));
		else
			ft_putchar(hex[d]);
		*n += 1;
	}
	else
	{
		ft_convert_hex_for_ptr(d / 16, c, n);
		ft_convert_hex_for_ptr(d % 16, c, n);
	}
}

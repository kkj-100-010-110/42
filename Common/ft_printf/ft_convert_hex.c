/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:36:02 by gyeokim           #+#    #+#             */
/*   Updated: 2022/05/23 22:28:20 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_hex(unsigned int d, int c, int *n)
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
		ft_convert_hex(d / 16, c, n);
		ft_convert_hex(d % 16, c, n);
	}
}

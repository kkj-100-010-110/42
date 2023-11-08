/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:37:02 by gyeokim           #+#    #+#             */
/*   Updated: 2022/05/24 01:12:13 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	read_line(const char *format, int *idx, int *n)
{
	int	i;

	i = *idx;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			*n += (i - *idx);
			*idx = (i + 1);
			return (1);
		}
		ft_putchar(format[i]);
		i++;
	}
	*n += (i - *idx);
	*idx = i;
	return (0);
}

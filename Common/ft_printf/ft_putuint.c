/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 21:36:50 by gyeokim           #+#    #+#             */
/*   Updated: 2022/05/23 21:36:52 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putuint(unsigned int u, int *n)
{
	if (u < 10)
	{
		ft_putchar(u + '0');
		*n += 1;
	}
	else
	{
		ft_putuint(u / 10, n);
		ft_putuint(u % 10, n);
	}
}

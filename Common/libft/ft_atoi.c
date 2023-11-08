/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 19:01:23 by gyeokim           #+#    #+#             */
/*   Updated: 2021/12/19 16:27:08 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	ft_isspace(int c);
static int	ft_rmspace_sign(const char *str, int *sign);

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	n;
	long	tmp;

	sign = 1;
	n = 0;
	i = ft_rmspace_sign(str, &sign);
	while (ft_isdigit(str[i]))
	{
		tmp = n;
		n = (n * 10) + str[i] - 48;
		if (tmp != n / 10 && sign == -1)
			return ((int)LONG_MIN);
		if (tmp != n / 10 && sign == 1)
			return ((int)LONG_MAX);
		i++;
	}
	return (sign * n);
}

static int	ft_isspace(int c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	else
		return (0);
}

static int	ft_rmspace_sign(const char *str, int *sign)
{
	int	i;

	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == 43 || str[i] == 45)
	{
		if (str[i] == 45)
			*sign *= -1;
		i++;
	}
	return (i);
}

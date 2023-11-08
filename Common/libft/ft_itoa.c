/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:28:04 by gyeokim           #+#    #+#             */
/*   Updated: 2021/12/21 19:07:32 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_find_len(int n);

char	*ft_itoa(int n)
{
	int		digit;
	int		len;
	char	*a;

	len = ft_find_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	a = (char *)malloc(len + 1);
	if (a == NULL)
		return (NULL);
	if (n < 0)
	{
		a[0] = '-';
		n *= -1;
	}
	else if (n == 0)
		a[0] = '0';
	a[len] = '\0';
	while (n)
	{
		digit = n % 10;
		n /= 10;
		a[(len--) - 1] = digit + '0';
	}
	return (a);
}

static int	ft_find_len(int n)
{
	int	count;
	int	num;

	count = 0;
	num = n;
	while (num != 0)
	{
		num /= 10;
		count++;
	}
	if (n <= 0)
		return (count + 1);
	else
		return (count);
}

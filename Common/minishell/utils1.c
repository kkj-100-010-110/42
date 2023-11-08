/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:32:48 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/30 10:53:38 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_digits(int n)
{
	int	n_digits;

	n_digits = 0;
	if (n < 0)
		n = n * -1;
	while (n > 0)
	{
		n = n / 10;
		n_digits++;
	}
	return (n_digits);
}

static int	power(int n_digits)
{
	int	p10;

	p10 = 1;
	while (n_digits > 0)
	{
		p10 = p10 * 10;
		n_digits--;
	}
	return (p10);
}

char	*ft_itoa(int n)
{
	char	*itoa;
	int		p10;
	int		i;

	itoa = (char *)malloc((count_digits(n) + 2) * sizeof(char));
	if (!itoa)
		return (NULL);
	if (n == -2147483648)
		return (ft_substr("-2147483648", 0, 11));
	i = 0;
	if (n < 0)
	{
		itoa[i++] = '-';
		n = n * (-1);
	}
	p10 = power(count_digits(n) - 1);
	while (p10 > 0)
	{
		itoa[i++] = (n / p10 % 10 + 48);
		p10 = p10 / 10;
	}
	itoa[i] = '\0';
	return (itoa);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	size_t	a_len;
	char	*aux;

	aux = b;
	a_len = len;
	i = 0;
	while (a_len > 0)
	{
		if (aux[i] != '\0' || i < len)
			aux[i] = c;
		i++;
		a_len--;
	}
	return (aux);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*string;
	size_t		i;
	size_t		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	i = 0;
	string = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(*string));
	if (string == 0)
		return (0);
	while (s1[i] != '\0')
	{
		string[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		string[i] = s2[j];
		i++;
		j++;
	}
	free((char *)s1);
	string[i] = '\0';
	return (string);
}

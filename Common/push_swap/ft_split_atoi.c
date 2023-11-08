/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_atoi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:43:55 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/30 00:32:34 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(int c);
static int	ft_rmspace_sign(const char *str, int *sign);
static int	ft_isdigit(int c);
static int	ft_atoi(const char *str, int *index, t_list *a, t_list *sorted);

void	ft_check_args(char const *s, t_list *a, t_list *sorted)
{
	int	i;
	int	ok;
	int	empty;

	if (*s == '\0')
		ft_error(sorted, a);
	i = 0;
	empty = 1;
	while (s[i] != '\0')
	{
		if (ft_isspace(s[i]) == 0)
		{
			ok = ft_atoi(s + i, &i, a, sorted);
			if (i < 0)
				ft_error(sorted, a);
			add_head_tail(a, create_node(ok), TAIL);
			if (add_sorted_list(sorted, create_node(ok)))
				ft_error(sorted, a);
			empty = 0;
		}
		else
			i++;
	}
	if (empty)
		ft_error(sorted, a);
}

static int	ft_atoi(const char *str, int *index, t_list *a, t_list *sorted)
{
	int		i;
	int		sign;
	long	n;

	sign = 1;
	i = ft_rmspace_sign(str, &sign);
	n = 0;
	if (ft_isdigit(str[i]) == 0)
		ft_error(sorted, a);
	while (ft_isdigit(str[i]))
	{
		n = (n * 10) + str[i] - 48;
		i++;
	}
	n *= sign;
	if ((ft_isspace(str[i]) || str[i] == '\0') \
			&& (n >= INT_MIN && n <= INT_MAX))
		*index += i;
	else
		*index = -1;
	return (n);
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

static int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

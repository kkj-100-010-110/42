/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 16:16:53 by gyeokim           #+#    #+#             */
/*   Updated: 2021/12/19 19:00:17 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_begin(char const *s1, char const *set);
static int	ft_end(char const *s1, char const *set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	int		begin;
	int		end;

	if (s1 == NULL)
		return (NULL);
	begin = ft_begin(s1, set);
	end = ft_end(s1, set);
	if (begin > end)
		return (ft_strdup(""));
	result = ft_substr(s1, begin, end - begin + 1);
	return (result);
}

int	ft_begin(char const *str, char const *set)
{
	int	begin;
	int	i;

	begin = 0;
	while (str[begin] != '\0')
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (str[begin] == set[i])
				break ;
			i++;
		}
		if (set[i] == '\0')
			return (begin);
		begin++;
	}
	return (begin);
}

int	ft_end(char const *str, char const *set)
{
	int	end;
	int	i;

	end = ft_strlen(str) - 1;
	while (end >= 0)
	{
		i = 0;
		while (set[i] != '\0')
		{
			if (str[end] == set[i])
				break ;
			i++;
		}
		if (set[i] == '\0')
			return (end);
		end--;
	}
	return (end);
}

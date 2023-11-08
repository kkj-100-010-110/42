/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 17:36:18 by gyeokim           #+#    #+#             */
/*   Updated: 2021/12/21 17:02:48 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	number_of_words(char const *s, char c);
static void	words(char const *s, char c, char **result);

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		n;
	int		i;

	if (s == NULL)
		return (NULL);
	n = number_of_words(s, c);
	result = malloc(sizeof(char *) * (n + 1));
	if (result == NULL)
		return (NULL);
	words(s, c, result);
	i = -1;
	while (++i < n)
	{
		if (result[i] == NULL)
		{
			i = -1;
			while (result[++i])
				free(result[i]);
			free(result);
			return (NULL);
		}
	}
	return (result);
}

static int	number_of_words(char const *s, char c)
{
	int	i;
	int	n;
	int	flag;

	i = 0;
	n = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '\0' && s[i] != c)
		{
			if (flag == 0)
			{
				n++;
				flag = 1;
			}
		}
		if (s[i] != '\0' && s[i] == c)
			flag = 0;
		i++;
	}
	return (n);
}

static void	words(char const *s, char c, char **result)
{
	int	i;
	int	start;
	int	idx;

	idx = 0;
	i = 0;
	start = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i] != '\0')
			i++;
		if (s[start] == '\0')
			break ;
		result[idx] = ft_substr(s, start, i - start);
		idx++;
	}
	result[idx] = NULL;
}

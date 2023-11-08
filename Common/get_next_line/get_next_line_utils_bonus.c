/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 15:24:19 by gyeokim           #+#    #+#             */
/*   Updated: 2022/04/13 15:24:33 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*buffer_to_result(char *result, char *buffer, int *check)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			result = cpy_join(result, buffer, i + 1);
			reset_buffer(buffer, i + 1);
			*check = 1;
			return (result);
		}
		i++;
	}
	result = cpy_join(result, buffer, i);
	reset_buffer(buffer, i);
	return (result);
}

char	*str_allocation(char *str, int n)
{
	char	*p;

	str = (char *)malloc(sizeof(char) * n);
	if (!str)
		return (NULL);
	p = str;
	while (p < str + n)
		*p++ = '\0';
	return (str);
}

void	reset_buffer(char *buffer, int n)
{
	int	i;

	i = 0;
	if (buffer[n] == '\0')
	{
		while (i < n)
			buffer[i++] = '\0';
		return ;
	}
	while (n < BUFFER_SIZE)
		buffer[i++] = buffer[n++];
	while (i < BUFFER_SIZE)
		buffer[i++] = '\0';
}

int	ft_strlen(char *str)
{
	char	*p;

	p = str;
	while (*str)
		str++;
	return (str - p);
}

char	*cpy_join(char *result, char *buffer, int n)
{
	char	*new;
	int		i;
	int		j;

	if (result == NULL && buffer == NULL)
		return (NULL);
	new = (char *)malloc(sizeof(char) * (ft_strlen(result) + n + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (result[i] != '\0')
	{
		new[i] = result[i];
		i++;
	}
	j = 0;
	while (j < n)
		new[i++] = buffer[j++];
	new[i] = '\0';
	free(result);
	result = NULL;
	return (new);
}

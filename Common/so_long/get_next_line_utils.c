/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:46:39 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/17 13:47:37 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

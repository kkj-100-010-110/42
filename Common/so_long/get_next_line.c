/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:46:43 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/17 13:51:23 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*get_next_line(int fd)
{
	char		*result;
	static char	*buffer;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (buffer == NULL)
	{
		buffer = str_allocation(buffer, BUFFER_SIZE + 1);
		if (buffer == NULL)
			return (NULL);
	}
	result = NULL;
	result = str_allocation(result, BUFFER_SIZE + 1);
	if (result == NULL)
		return (NULL);
	result = read_buffer(result, buffer, fd);
	if (*result == '\0')
	{
		free(buffer);
		buffer = NULL;
		free(result);
		result = NULL;
	}
	return (result);
}

char	*read_buffer(char *result, char *buffer, int fd)
{
	int			check;

	check = 0;
	if (*buffer != '\0')
	{
		result = buffer_to_result(result, buffer, &check);
		if (check == 1)
			return (result);
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		result = buffer_to_result(result, buffer, &check);
		if (check == 1)
			return (result);
	}
	return (result);
}

char	*buffer_to_result(char *result, char *buffer, int *check)
{
	int	i;

	i = 0;
	while (buffer[i] != '\0')
	{
		if (buffer[i] == '\n')
		{
			result = cpy_join(result, buffer, i);
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

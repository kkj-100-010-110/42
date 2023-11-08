/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map_check.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:47:13 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/17 13:47:33 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	create_map(t_parts *parts)
{
	int	x;
	int	y;

	y = 0;
	while (y < parts->y)
	{
		x = 0;
		while (x < parts->x)
		{
			put_img(parts, x, y);
			x++;
		}
		y++;
	}
}

void	read_map(char *file_name, t_parts *parts)
{
	int		fd;
	char	*line;

	fd = ft_strlen(file_name);
	if (fd < 5 || ft_strncmp(&file_name[fd - 4], ".ber", 4))
		ft_error(2, parts);
	fd = open(file_name, O_RDONLY);
	if (fd <= 0)
		ft_error(2, parts);
	line = NULL;
	line = get_next_line(fd);
	parts->x = ft_strlen(line);
	parts->map_line = ft_strdup(line);
	free(line);
	while (line)
	{
		parts->y++;
		line = get_next_line(fd);
		if (line)
			parts->map_line = ft_strjoin(parts->map_line, line);
	}
	close(fd);
}

void	check_walls(t_parts *parts)
{
	int	i;

	i = 0;
	while (i < ft_strlen(parts->map_line))
	{
		if (i < parts->x)
		{
			if (parts->map_line[i] != '1')
				ft_error(6, parts);
		}
		else if (i % parts->x == 0 || i % parts->x == parts->x - 1)
		{
			if (parts->map_line[i] != '1')
				ft_error(6, parts);
		}
		else if (i > ft_strlen(parts->map_line) - parts->x)
		{
			if (parts->map_line[i] != '1')
				ft_error(6, parts);
		}
		i++;
	}
}

void	check_parts(t_parts *parts)
{
	int	i;
	int	e;
	int	p;

	i = 0;
	e = 0;
	p = 0;
	while (i++ < ft_strlen(parts->map_line))
	{
		if (parts->map_line[i] == 'E')
			e++;
		else if (parts->map_line[i] == 'P')
			p++;
		else if (parts->map_line[i] == 'C')
			parts->collect_num++;
	}
	if (e == 0 || p != 1 || parts->collect_num == 0)
		ft_error(4, parts);
}

void	check_map(t_parts *parts)
{
	if (parts->y * parts-> x != ft_strlen(parts->map_line))
		ft_error(5, parts);
	check_walls(parts);
	check_parts(parts);
}

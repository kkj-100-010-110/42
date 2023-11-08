/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_key.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:47:10 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/17 13:59:30 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	up(t_parts *parts)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(parts->map_line))
	{
		if (parts->map_line[i] == 'P')
			break ;
	}
	if (parts->map_line[i - parts->x] == 'C')
		parts->collect_cnt++;
	if (parts->map_line[i - parts->x] == 'E' && \
		parts->collect_num == parts->collect_cnt)
		complete(parts);
	else if (parts->map_line[i - parts->x] != '1' && \
		parts->map_line[i - parts->x] != 'E')
	{
		parts->map_line[i] = '0';
		parts->map_line[i - parts->x] = 'P';
		parts->step++;
		printf("%d\n", parts->step);
		create_map(parts);
	}
}

void	left(t_parts *parts)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(parts->map_line))
	{
		if (parts->map_line[i] == 'P')
			break ;
	}
	if (parts->map_line[i - 1] == 'C')
		parts->collect_cnt++;
	if (parts->map_line[i - 1] == 'E' && \
		parts->collect_num == parts->collect_cnt)
		complete(parts);
	else if (parts->map_line[i - 1] != '1' && \
		parts->map_line[i - 1] != 'E')
	{
		parts->map_line[i] = '0';
		parts->map_line[i - 1] = 'P';
		parts->step++;
		printf("%d\n", parts->step);
		create_map(parts);
	}
}

void	down(t_parts *parts)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(parts->map_line))
	{
		if (parts->map_line[i] == 'P')
			break ;
	}
	if (parts->map_line[i + parts->x] == 'C')
		parts->collect_cnt++;
	if (parts->map_line[i + parts->x] == 'E' && \
		parts->collect_num == parts->collect_cnt)
		complete(parts);
	else if (parts->map_line[i + parts->x] != '1' && \
		parts->map_line[i + parts->x] != 'E')
	{
		parts->map_line[i] = '0';
		parts->map_line[i + parts->x] = 'P';
		parts->step++;
		printf("%d\n", parts->step);
		create_map(parts);
	}
}

void	right(t_parts *parts)
{
	int	i;

	i = 0;
	while (i++ < ft_strlen(parts->map_line))
	{
		if (parts->map_line[i] == 'P')
			break ;
	}
	if (parts->map_line[i + 1] == 'C')
		parts->collect_cnt++;
	if (parts->map_line[i + 1] == 'E' && \
		parts->collect_num == parts->collect_cnt)
		complete(parts);
	else if (parts->map_line[i + 1] != '1' && \
		parts->map_line[i + 1] != 'E')
	{
		parts->map_line[i] = '0';
		parts->map_line[i + 1] = 'P';
		parts->step++;
		printf("%d\n", parts->step);
		create_map(parts);
	}
}

int	setup_key(int code, t_parts *parts)
{
	if (code == KEY_ESC)
		ft_exit(parts);
	if (code == KEY_W)
		up(parts);
	if (code == KEY_S)
		down(parts);
	if (code == KEY_A)
		left(parts);
	if (code == KEY_D)
		right(parts);
	return (0);
}

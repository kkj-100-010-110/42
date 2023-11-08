/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:47:06 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/17 13:56:45 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	setup_image(t_parts *parts)
{
	int	x;
	int	y;

	parts->img.character = \
		mlx_xpm_file_to_image(parts->mlx, "./images/chicken.xpm", &x, &y);
	parts->img.collect = \
		mlx_xpm_file_to_image(parts->mlx, "./images/collect.xpm", &x, &y);
	parts->img.road = \
		mlx_xpm_file_to_image(parts->mlx, "./images/road.xpm", &x, &y);
	parts->img.wall = \
		mlx_xpm_file_to_image(parts->mlx, "./images/wall.xpm", &x, &y);
	parts->img.gate = \
		mlx_xpm_file_to_image(parts->mlx, "./images/gate.xpm", &x, &y);
	parts->img.gate_open = \
		mlx_xpm_file_to_image(parts->mlx, "./images/open.xpm", &x, &y);
	if (!parts->img.character || !parts->img.collect || !parts->img.road || \
		!parts->img.gate || !parts->img.gate_open)
		ft_error(7, parts);
}

void	put_img(t_parts *parts, int x, int y)
{
	if (parts->map_line[y * parts->x + x] == '1')
		mlx_put_image_to_window(parts->mlx, parts->win, parts->img.wall,
			x * 64, y * 64);
	else if (parts->map_line[y * parts->x + x] == 'C')
		mlx_put_image_to_window(parts->mlx, parts->win, parts->img.collect,
			x * 64, y * 64);
	else if (parts->map_line[y * parts->x + x] == 'P')
		mlx_put_image_to_window(parts->mlx, parts->win, parts->img.character,
			x * 64, y * 64);
	else if (parts->map_line[y * parts->x + x] == 'E' && \
		parts->collect_num == parts->collect_cnt)
		mlx_put_image_to_window(parts->mlx, parts->win, parts->img.gate_open,
			x * 64, y * 64);
	else if (parts->map_line[y * parts->x + x] == 'E')
		mlx_put_image_to_window(parts->mlx, parts->win, parts->img.gate,
			x * 64, y * 64);
	else
		mlx_put_image_to_window(parts->mlx, parts->win, parts->img.road,
			x * 64, y * 64);
}

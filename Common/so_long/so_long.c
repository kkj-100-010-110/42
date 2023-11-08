/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:47:21 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/17 13:53:48 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(int code, t_parts *parts)
{
	write(2, "Error\n", 6);
	if (code == 1)
		write (2, "Wrong argument count.\n", 22);
	else if (code == 2)
		write (2, "Failed to open the file.\n", 25);
	else if (code == 3)
		write (2, "Wrong map.\n", 11);
	else if (code == 4)
		write (2, "Wrong number of parts in the map.\n", 34);
	else if (code == 5)
		write (2, "Wrong shape of the map.\n", 24);
	else if (code == 6)
		write (2, "Map is not surrounded by walls.\n", 32);
	else if (code == 7)
		write (2, "Failed to read images.\n", 23);
	else if (code == 8)
		write (2, "Failed to create to window.\n", 28);
	else if (code == 0)
		write (2, "Malloc failed.\n", 15);
	else
		write (2, "Failed to connect to MLX.\n", 26);
	if (parts->map_line != NULL)
		free(parts->map_line);
	exit(EXIT_FAILURE);
}

void	init_parts(t_parts *parts)
{
	parts->mlx = NULL;
	parts->win = NULL;
	parts->x = 0;
	parts->y = 0;
	parts->step = 0;
	parts->collect_num = 0;
	parts->collect_cnt = 0;
	parts->gate_num = 0;
	parts->map_line = NULL;
	parts->img.character = NULL;
	parts->img.collect = NULL;
	parts->img.road = NULL;
	parts->img.wall = NULL;
	parts->img.gate = NULL;
	parts->img.gate_open = NULL;
}

int	ft_exit(t_parts *parts)
{
	mlx_destroy_window(parts->mlx, parts->win);
	free(parts->map_line);
	exit(EXIT_SUCCESS);
}

int	complete(t_parts *parts)
{
	parts->step++;
	printf("Completed with %d steps.\n", parts->step);
	free(parts->map_line);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv)
{
	t_parts	parts;

	init_parts(&parts);
	if (argc != 2)
		ft_error(1, &parts);
	read_map(argv[1], &parts);
	check_map(&parts);
	parts.mlx = mlx_init();
	if (!parts.mlx)
		ft_error(9, &parts);
	parts.win = \
		mlx_new_window(parts.mlx, parts.x * 64, parts.y * 64, "so_long");
	if (!parts.win)
		ft_error(8, &parts);
	setup_image(&parts);
	create_map(&parts);
	mlx_hook(parts.win, KEY_PRESS, 0, &setup_key, &parts);
	mlx_hook(parts.win, KEY_EXIT, 0, &ft_exit, &parts);
	mlx_loop(parts.mlx);
	return (0);
}

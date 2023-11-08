/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:53:57 by gyeokim           #+#    #+#             */
/*   Updated: 2022/11/24 15:54:48 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minirt.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	if (argc != 2)
		exit_with_error("Wrong number of arguments\n");
	set_mlx(&scene.mlx);
	parse(&scene, argv[1]);
	pixel_put(&scene);
	mlx_put_image_to_window(scene.mlx.mlx, scene.mlx.win, scene.mlx.img, 0, 0);
	mlx_loop(scene.mlx.mlx);
}

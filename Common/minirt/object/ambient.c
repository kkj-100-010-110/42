/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:48:25 by jnam              #+#    #+#             */
/*   Updated: 2022/11/24 15:48:26 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	ambient(t_scene *scene, char **data)
{
	t_ambient	ambient;

	ambient.ambient = a_to_d(data[1]);
	ambient.color = parse_color(data[2]);
	scene->ambient = ambient;
}

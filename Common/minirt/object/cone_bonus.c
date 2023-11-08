/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:48:31 by jnam              #+#    #+#             */
/*   Updated: 2022/11/24 15:48:32 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	cone(t_scene *scene, char **data)
{
	t_cone	*cone;

	cone = wrap_malloc(sizeof(t_cone));
	cone->point = str_to_vec3(data[1]);
	cone->normal = vunit(str_to_vec3(data[2]));
	cone->theta = a_to_d(data[3]) * M_PI / 180;
	cone->height = a_to_d(data[4]);
	cone->color = parse_color(data[5]);
	oadd(&scene->object_list, object(cone, CO));
}

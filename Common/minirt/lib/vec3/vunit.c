/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vunit.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:45:29 by jnam              #+#    #+#             */
/*   Updated: 2022/11/24 15:45:30 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"

t_vec3	vunit(t_vec3 vec)
{
	const double	len = vlength(vec);

	if (len == 0)
	{
		perror("Error\nDevider is 0\n");
		exit(EXIT_FAILURE);
	}
	vec.x /= len;
	vec.y /= len;
	vec.z /= len;
	return (vec);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_check_cnt.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:47:03 by gyeokim           #+#    #+#             */
/*   Updated: 2022/11/24 15:49:23 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	check_cnt_ambient(void)
{
	static int	cnt;

	return (cnt++);
}

int	check_cnt_camera(void)
{
	static int	cnt;

	return (cnt++);
}

int	check_cnt_light(void)
{
	static int	cnt;

	return (cnt++);
}

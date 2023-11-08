/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:47:08 by gyeokim           #+#    #+#             */
/*   Updated: 2022/11/24 15:49:24 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wrap.h"

int	wrap_open(const char *pathname, int flags)
{
	int	fd;

	fd = open(pathname, flags);
	if (fd == -1)
		exit_with_error("file open fail\n");
	return (fd);
}

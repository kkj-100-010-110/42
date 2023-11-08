/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:47:10 by gyeokim           #+#    #+#             */
/*   Updated: 2022/11/24 15:49:25 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wrap.h"

void	*wrap_malloc(size_t size)
{
	void	*ret;

	ret = malloc(size);
	if (ret == NULL)
		exit_with_error("memory allocation failed\n");
	return (ret);
}

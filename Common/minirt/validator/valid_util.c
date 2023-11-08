/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:46:38 by gyeokim           #+#    #+#             */
/*   Updated: 2022/11/24 15:49:19 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	set_filter(int *filter, const char *valid_char)
{
	const int	v_len = ft_strlen(valid_char);
	int			i;

	i = 0;
	while (i < 128)
	{
		filter[i] = 0;
		i++;
	}
	i = 0;
	while (i < v_len)
	{
		filter[(int)valid_char[i]] += 1;
		i++;
	}
}

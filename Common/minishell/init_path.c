/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:56:20 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:15:32 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	init_path(t_items *items)
{
	char	*path_aux;
	int		i;

	path_aux = ft_strdup(find_env(items, "PATH"));
	if (!path_aux)
		return (0);
	items->path = ft_split(path_aux, ':');
	i = 0;
	while (items->path && items->path[i])
	{
		items->path[i] = ft_strjoin(items->path[i], "/");
		i++;
	}
	free(path_aux);
	return (1);
}

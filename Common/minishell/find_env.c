/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:53:56 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:13:49 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_env(t_items *items, char *needle)
{
	int	i;
	int	len;
	int	len_needle;

	i = 0;
	items->env.index = 0;
	len_needle = ft_strlen(needle);
	while (items->env.key[i] && i < items->env.len)
	{
		len = ft_strlen(items->env.key[i]);
		if (!ft_strncmp(items->env.key[i], needle, len_needle)
			&& len == len_needle)
		{
			items->env.index = i;
			return (items->env.content[i]);
		}
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:56:05 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:15:15 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_unset(t_items *items)
{
	int	i;

	i = 1;
	while (items->tokens[i])
	{
		if (find_env(items, items->tokens[i]))
		{
			rm_env(items);
			if (!ft_strncmp(items->tokens[i], "PATH", 4))
			{
				free_char_array(items->path);
				items->path = NULL;
			}
		}
		i++;
	}
	g_ret_number = 0;
}

void	rm_env(t_items *items)
{
	int	i;
	int	j;

	items->env.len--;
	alloc_env_aux(items);
	i = 0;
	j = 0;
	while (i < items->env.len + 1)
	{
		if (i != items->env.index)
		{
			items->env_aux.key[j] = ft_strdup(items->env.key[i]);
			items->env_aux.content[j] = ft_strdup(items->env.content[i]);
			j++;
		}
		i++;
	}
	items->env_aux.key[j] = NULL;
	items->env_aux.content[j] = NULL;
	free_char_array(items->env.key);
	free_char_array(items->env.content);
	items->env.key = items->env_aux.key;
	items->env.content = items->env_aux.content;
}

void	alloc_env_aux(t_items *items)
{
	items->env_aux.key = malloc(sizeof(char *) * (items->env.len + 1));
	if (!items->env_aux.key)
		exit(EXIT_FAILURE);
	items->env_aux.content = malloc(sizeof(char *) * (items->env.len + 1));
	if (!items->env_aux.content)
		exit(EXIT_FAILURE);
}

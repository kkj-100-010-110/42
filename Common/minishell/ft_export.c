/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:55:14 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:14:53 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_export(t_items *items)
{
	int		i;
	char	**env_aux;

	i = 1;
	while (items->tokens[i])
	{
		env_aux = ft_split(items->tokens[i], '=');
		if (env_aux[1])
			verify_if_env_exists(items, env_aux, i);
		else if (items->tokens[i][ft_strlen(items->tokens[1]) - 1] == '=')
		{
			env_aux[1] = ft_strdup("");
			verify_if_env_exists(items, env_aux, i);
		}
		free(env_aux[0]);
		free(env_aux[1]);
		free(env_aux);
		env_aux = NULL;
		i++;
	}
	g_ret_number = 0;
}

void	verify_if_env_exists(t_items *items, char **env_aux, int i)
{
	if (find_env(items, env_aux[0]))
	{
		free(items->env.content[items->env.index]);
		items->env.content[items->env.index] = ft_strdup(env_aux[1]);
	}
	else
		add_env(items, env_aux[0], env_aux[1]);
	if (!ft_strncmp(items->tokens[i], "PATH", 4))
	{
		if (items->path)
			free_char_array(items->path);
		init_path(items);
	}
}

void	add_env(t_items *items, char *new_key, char *new_content)
{
	int	i;

	items->env.len++;
	alloc_env_aux(items);
	i = 0;
	while (i < items->env.len - 1)
	{
		items->env_aux.key[i] = ft_strdup(items->env.key[i]);
		items->env_aux.content[i] = ft_strdup(items->env.content[i]);
		i++;
	}
	items->env_aux.key[i] = ft_strdup(new_key);
	items->env_aux.content[i] = ft_strdup(new_content);
	i++;
	items->env_aux.key[i] = NULL;
	items->env_aux.content[i] = NULL;
	free_char_array(items->env.key);
	free_char_array(items->env.content);
	items->env.key = items->env_aux.key;
	items->env.content = items->env_aux.content;
}

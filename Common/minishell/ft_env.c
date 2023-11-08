/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:54:39 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:14:31 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_env(t_items *items)
{
	int	i;

	i = 0;
	while (i < items->env.len)
	{
		ft_putstr_fd(items->env.key[i], items->out_fd);
		ft_putchar_fd('=', items->out_fd);
		ft_putendl_fd(items->env.content[i], items->out_fd);
		i++;
	}
	g_ret_number = 0;
}

void	create_env(t_items *items, char **my_env)
{
	int		i;
	char	**env_aux;

	items->env.env = my_env;
	len_env(items);
	init_struct_env(items);
	i = 0;
	while (items->env.env[i])
	{
		env_aux = ft_split(items->env.env[i], '=');
		items->env.key[i] = ft_strdup(env_aux[0]);
		if (env_aux[1])
			items->env.content[i] = ft_strdup(env_aux[1]);
		else
			items->env.content[i] = ft_strdup("");
		free_char_array(env_aux);
		env_aux = NULL;
		i++;
	}
	items->env.key[i] = NULL;
	items->env.content[i] = NULL;
}

void	len_env(t_items *items)
{
	int	i;

	i = 0;
	while (items->env.env[i])
		i++;
	items->env.len = i;
}

void	init_struct_env(t_items *items)
{
	items->env.key = malloc(sizeof(char *) * (items->env.len + 1));
	if (!items->env.key)
		exit(EXIT_FAILURE);
	items->env.content = malloc(sizeof(char *) * (items->env.len + 1));
	if (!items->env.content)
		exit(EXIT_FAILURE);
}

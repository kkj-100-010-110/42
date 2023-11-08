/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:57:42 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:20:54 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	split_cmd(t_items *items, char *in, int i)
{
	init_split_struct(items);
	in = clean_spaces(in);
	while (i < (int)ft_strlen(in))
	{
		if (items->split.q == 0 && (in[i] == D_QUOTE || in[i] == QUOTE))
			items->split.q = in[i];
		else
		{
			if (items->split.q == in[i])
				items->split.q = 0;
			else
				i = count_pipe(items, in, i);
		}
		items->split.len++;
		i++;
	}
	if (ft_strlen(in) > 0)
	{
		items->commands[items->split.n_comand]
			= ft_substr(in, items->split.ini, i);
		items->split.n_comand++;
	}
	free(in);
	items->commands[items->split.n_comand] = NULL;
}

void	init_split_struct(t_items *items)
{
	items->split.n_comand = 0;
	items->split.ini = 0;
	items->split.len = 0;
	items->split.qtt_pipe = 0;
	items->split.q = 0;
}

char	*clean_spaces(char *in)
{
	char	*aux;

	aux = ft_strtrim(in, " ");
	in = aux;
	return (in);
}

int	count_pipe(t_items *items, char *in, int i)
{
	if (in[i] == '|' || in[i] == '<' || in[i] == '>')
	{
		if (in[i] == '|' && items->split.q == 0)
			items->split.qtt_pipe++;
		if (items->split.q == 0 && i > 1 && items->split.len > 0)
		{
			items->commands[items->split.n_comand] = ft_substr(in,
					items->split.ini, items->split.len);
			items->split.ini = i;
			items->split.len = 0;
			items->split.n_comand++;
			if (in[i] == in[i + 1])
			{
				i++;
				items->split.len = 1;
			}
		}
	}
	return (i);
}

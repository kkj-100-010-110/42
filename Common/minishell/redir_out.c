/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_out.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:56:54 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:16:09 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	redirect_out(t_items *items, int j)
{
	int		flags;
	char	*file;

	flags = O_WRONLY | O_CREAT;
	j = items->c;
	if (items->commands[j] && items->commands[j][0] == '>')
	{
		if (items->commands[j] && items->commands[j][1] == '>')
		{
			file = ft_strtrim(&items->commands[j][2], " ");
			items->out_fd = open(file, flags | O_APPEND, 0777);
			free (file);
		}
		else
			simple_redir_out(items, j, flags);
		if (items->split.n_comand == 1)
			free(items->line);
	}
}

void	simple_redir_out(t_items *items, int j, int flags)
{
	char	*aux;
	char	*file;

	aux = ft_strtrim(&items->commands[j][1], " ");
	file = ft_substr(aux, 0, find_char(aux, ' '));
	items->out_fd = open(file, flags | O_TRUNC, 0777);
	free (aux);
	free (file);
}

int	find_char(char *string, char needle)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == needle)
			return (i);
		i++;
	}
	return (i);
}

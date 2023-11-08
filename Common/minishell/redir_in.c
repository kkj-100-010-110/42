/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir_in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:56:42 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:16:03 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_print(t_items *items, int j, size_t i)
{
	if (ft_strlen(items->commands[j]) == i)
	{
		printf("undefined behavior\n");
		exit(1);
	}
}

void	redirect_in(t_items *items, int j)
{
	char	**file;

	if (items->commands[j][0] == '<')
	{
		file = NULL;
		if (items->commands[j][1] == '<')
		{
			error_print(items, j, 2);
			file = double_redir(items, file, j);
		}
		else
		{
			error_print(items, j, 1);
			file = ft_split(&items->commands[j][1], ' ');
			items->in_fd = open(file[0], O_RDONLY, 0777);
			if (items->in_fd == -1 && items->error_name_file == NULL)
				items->error_name_file = ft_strdup(file[0]);
		}
		free_char_array(file);
	}
}

char	**double_redir(t_items *items, char **file, int j)
{
	file = ft_split(&items->commands[j][2], ' ');
	read_until (file[0]);
	items->in_fd = open(file[0], O_RDONLY | O_CREAT, 0777);
	items->name_file = ft_strdup(file[0]);
	items->is_append++;
	return (file);
}

void	read_until(char *end)
{
	char	*line;
	int		flags;
	int		fd;

	flags = O_WRONLY | O_CREAT | O_TRUNC;
	line = ft_strdup("");
	fd = open(end, flags, 0777);
	while (ft_strncmp(line, end, ft_strlen(end))
		|| ft_strlen(line) != ft_strlen(end))
	{
		free(line);
		line = readline("> ");
		if (ft_strlen(line) != ft_strlen(end))
			ft_putendl_fd(line, fd);
	}
	close(fd);
	free(line);
}

char	*new_command(int i, char **str)
{
	char	*aux;

	aux = ft_strdup("");
	while (str[i] != NULL)
	{
		if (ft_strlen(aux) > 0)
			aux = ft_strjoin(aux, " ");
		aux = ft_strjoin(aux, str[i]);
		i++;
	}
	return (aux);
}

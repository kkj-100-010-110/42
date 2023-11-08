/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:57:05 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/30 21:50:02 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	run_commands(t_items *items)
{
	int		j;
	int		fd[2];

	j = 0;
	items->c = 0;
	while (j < items->split.qtt_pipe)
	{
		if (pipe(fd) < 0)
		{
			printf("Pipe error\n");
			g_ret_number = 127;
		}
		items->out_fd = fd[1];
		run_commands_aux(items);
		close(items->out_fd);
		if (items->in_fd != 0)
			close(items->in_fd);
		items->in_fd = fd[0];
		j++;
	}
	run_commands_aux(items);
}

void	run_commands_aux(t_items *items)
{
	action(items);
	if (items->commands[0][0] != '>')
	{
		tokenizer(items);
		if (items->tokens[0])
			is_builtin(items->tokens[0], items);
		if (items->in_fd != -1)
		{
			exec_process(items, items->in_fd, items->out_fd);
		}
		free_char_array(items->tokens);
		free(items->token.to_print);
	}
	if (items->name_file)
		unlink(items->name_file);
}

void	action(t_items *items)
{
	items->line = ft_strdup(items->commands[items->c]);
	if (items->split.n_comand > 1)
		items->c++;
	items->error_name_file = NULL;
	while (items->commands[items->c] && items->commands[items->c][0] != '|')
	{
		redirect_out(items, items->c);
		redirect_in(items, items->c);
		items->c++;
	}
	if (items->error_name_file != NULL)
	{
		g_ret_number = 1;
		printf("minishell: %s: %s", items->error_name_file, ERROR_DIR);
		free(items->error_name_file);
	}
}

void	exec_process(t_items *items, int in, int out)
{
	pid_t	pid;

	if (items->is_builtin && items->tokens[0])
		run_builtin(items);
	else
	{
		pid = fork();
		run_signals(2);
		if (pid < 0)
		{
			printf("Fork error\n");
			g_ret_number = 127;
		}
		else if (pid == 0)
		{
			file_descriptor_handler(in, out);
			g_ret_number = 127;
			ft_execve_pipe(items, 0, "");
			exit(g_ret_number);
		}
		else
			waitpid(pid, &g_ret_number, WUNTRACED);
		if (WIFEXITED(g_ret_number))
			g_ret_number = WEXITSTATUS(g_ret_number);
	}
}

void	ft_execve_pipe(t_items *items, int i, char *command)
{
	if (items->tokens[0])
	{	
		g_ret_number = execve(items->tokens[0], &items->tokens[0],
				items->env.env);
		while (items->path && items->path[i] != NULL)
		{
			command = ft_strdup(items->path[i]);
			if (items->tokens[0][0] == '|' && items->tokens[1])
			{
				if (!items->tokens[0][1])
					spaces_in_pipe(items, 2, command);
				else
				{
					items->tokens[0] = &items->tokens[0][1];
					spaces_in_pipe(items, 1, command);
				}
			}
			else
				spaces_in_pipe(items, 1, command);
			i++;
		}
		execve_error(items);
	}
}

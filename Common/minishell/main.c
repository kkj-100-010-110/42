/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:56:30 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:15:48 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	avoid_norm(t_items *items)
{
	free(items->line_read);
	close(3);
	close(4);
}

int	main(int argc, char **argv, char **envp)
{
	t_items	items;

	initialize(&items, argc, argv, envp);
	while (1)
	{
		get_line(&items);
		if (items.line_read)
		{
			if (ft_strlen(items.line_read) != 0)
			{
				split_cmd(&items, items.line_read, 0);
				if (items.split.n_comand > 0 && items.commands[0][0] != '|')
				{
					run_commands(&items);
				}
				if (items.commands[0] && items.commands[0][0] == '|')
					printf(ERROR_PIPE);
				free_char_array2(items.commands);
			}
			avoid_norm(&items);
		}
		else
			run_signals(3);
	}
}

void	initialize(t_items *items, int argc, char **argv, char **envp)
{
	(void)argc;
	(void)argv;
	del_c();
	g_ret_number = 0;
	items->tokens = (char **) NULL;
	create_env(items, envp);
	init_path(items);
	items->home = ft_strdup(find_env(items, "HOME"));
}

void	get_line(t_items *items)
{
	char	*prompt;

	items->out_fd = STDOUT_FILENO;
	items->in_fd = STDIN_FILENO;
	prompt = create_prompt();
	run_signals(1);
	items->line_read = readline(prompt);
	if (items->line_read && *items->line_read)
		add_history(items->line_read);
	free(prompt);
}

char	*create_prompt(void)
{
	char	*buf;
	char	*prompt;

	buf = get_cwd_buf();
	prompt = ft_strjoin(buf, " $ ");
	return (prompt);
}

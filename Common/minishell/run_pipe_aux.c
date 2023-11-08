/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipe_aux.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:57:19 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:18:54 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	file_descriptor_handler(int in, int out)
{
	if (in != 0)
	{
		dup2(in, 0);
		close(in);
	}
	if (out != 1)
	{	
		dup2(out, 1);
		close(out);
	}
	return (0);
}

void	spaces_in_pipe(t_items *items, int i, char *command)
{
	command = ft_strjoin(command, items->tokens[i - 1]);
	g_ret_number = execve(command, &items->tokens[i - 1], items->env.env);
	free(command);
}

void	execve_error(t_items *items)
{
	g_ret_number = 127;
	if (items->tokens[0][0] != '|')
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(items->tokens[0], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(ERROR_CMD, 2);
		ft_putstr_fd("\n", 2);
	}
	else if (items->tokens[1])
	{
		ft_putstr_fd("minishell: ", 2);
		ft_putstr_fd(items->tokens[1], 2);
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(ERROR_CMD, 2);
		ft_putstr_fd("\n", 2);
	}
}

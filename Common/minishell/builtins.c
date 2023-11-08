/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:53:43 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:13:23 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	is_builtin(char *cmd, t_items *items)
{
	if ((!ft_strncmp("echo", cmd, 4) && ft_strlen(cmd) == 4)
		|| (!ft_strncmp("cd", cmd, 2) && ft_strlen(cmd) == 2)
		|| (!ft_strncmp("pwd", cmd, 3) && ft_strlen(cmd) == 3)
		|| (!ft_strncmp("export", cmd, 6) && ft_strlen(cmd) == 6)
		|| (!ft_strncmp("unset", cmd, 5) && ft_strlen(cmd) == 5)
		|| (!ft_strncmp("env", cmd, 3) && ft_strlen(cmd) == 3)
		|| (!ft_strncmp("exit", cmd, 4) && ft_strlen(cmd) == 4))
		items->is_builtin = true;
	else
		items->is_builtin = false;
}

void	run_builtin(t_items *items)
{
	if (!ft_strncmp(items->tokens[0], "exit", 4))
		ft_exit(items);
	if (!ft_strncmp(items->tokens[0], "pwd", 3))
		ft_pwd(items);
	if (!ft_strncmp(items->tokens[0], "echo", 4))
		ft_echo(items);
	if (!ft_strncmp(items->tokens[0], "cd", 2))
		ft_cd(items);
	if (!ft_strncmp(items->tokens[0], "env", 3))
		ft_env(items);
	if (!ft_strncmp(items->tokens[0], "export", 6))
		ft_export(items);
	if (!ft_strncmp(items->tokens[0], "unset", 5))
		ft_unset(items);
}

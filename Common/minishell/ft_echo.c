/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:54:27 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:14:15 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_echo(t_items *items)
{
	int		j;

	j = 0;
	if (items->tokens[1])
	{
		print_echo(items, items->token.to_print);
		if (!items->has_flag)
		{
			ft_putstr_fd("\n", items->out_fd);
		}
	}
	else
	{
		ft_putstr_fd("\n", items->out_fd);
	}
}

void	print_echo(t_items *items, char *mini_tokens_i)
{
	if (!ft_strncmp(mini_tokens_i, "$?", 2))
	{
		ft_putstr_fd(mini_tokens_i, items->out_fd);
	}
	else
	{
		ft_putstr_fd(mini_tokens_i, items->out_fd);
		g_ret_number = 0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:54:10 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:14:04 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	g_num_change(char *token_aux, t_items *items)
{
	g_ret_number = chdir(token_aux);
	if (g_ret_number == -1)
	{
		g_ret_number = 1;
		printf("minishell: cd: %s: %s", items->tokens[1], ERROR_DIR);
	}
}

int	ft_cd(t_items *items)
{
	char	*token_aux;
	bool	home;

	home = there_is_home(items);
	if (items->tokens[1])
		token_aux = ft_strdup(items->token.to_print);
	else
	{
		if (home == true)
			token_aux = ft_strdup(items->home);
		else
		{
			g_ret_number = 1;
			printf(ERROR_HOME);
			return (1);
		}
	}
	g_num_change(token_aux, items);
	free(token_aux);
	return (0);
}

bool	there_is_home(t_items *items)
{
	if (find_env(items, "HOME"))
		return (true);
	else
		return (false);
}

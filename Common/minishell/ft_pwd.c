/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:55:26 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:15:00 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_items *items)
{
	char	*buf;

	if (items->tokens[1] != NULL)
	{
		ft_putendl_fd("pwd: too many arguments", items->out_fd);
		g_ret_number = 1;
	}
	else
	{
		buf = get_cwd_buf();
		ft_putendl_fd(buf, items->out_fd);
		if (buf == NULL)
			g_ret_number = 1;
		else
			g_ret_number = 0;
		free(buf);
	}
}

char	*get_cwd_buf(void)
{
	size_t	size;
	char	*buf;

	size = 2000;
	buf = NULL;
	buf = getcwd(buf, size);
	return (buf);
}

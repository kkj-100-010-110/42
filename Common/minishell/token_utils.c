/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:58:04 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:21:21 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_home_sign(t_items *items, t_token *tk)
{
	char	*extend;

	tk->new = ft_substr(items->line, tk->init, tk->len - 1);
	tk->end = ft_strjoin(tk->end, tk->new);
	free(tk->new);
	extend = items->home;
	tk->end = ft_strjoin(tk->end, extend);
	tk->i++;
	tk->len = 1;
	tk->init = tk->i;
}

void	get_dollar_sign(t_items *items, t_token *tk)
{
	char	*extend;
	char	*n_env;

	tk->new = ft_substr(items->line, tk->init, tk->len - 1);
	tk->end = ft_strjoin(tk->end, tk->new);
	free (tk->new);
	tk->posic = tokenizer_find_char(&items->line[tk->i + 1], ' ');
	n_env = ft_substr(items->line, tk->i + 1, tk->posic);
	if (items->line[tk->i + 1] != '?' && find_env(items, n_env))
		extend = ft_strdup(find_env(items, n_env));
	else if (items->line[tk->i + 1] == '?')
		extend = ft_itoa(g_ret_number);
	else
		extend = NULL;
	if (extend)
		tk->end = ft_strjoin(tk->end, extend);
	free(extend);
	tk->i += ft_strlen(n_env) + 1;
	free (n_env);
	tk->len = 1;
	tk->init = tk->i;
}

t_token	*init_tk(void)
{
	t_token	*tk;

	tk = (t_token *)malloc(sizeof(t_token));
	tk->end = NULL;
	tk->new = NULL;
	tk->to_print = NULL;
	tk->quote = '\0';
	tk->i = 0;
	tk->init = 0;
	tk->len = 1;
	tk->posic = 0;
	return (tk);
}

void	free_tk(t_token *tk)
{
	if (tk->end != NULL)
	{
		free(tk->end);
		tk->end = NULL;
	}
	if (tk->new != NULL)
	{
		free(tk->new);
		tk->new = NULL;
	}
	if (tk->to_print != NULL)
	{
		free(tk->to_print);
		tk->to_print = NULL;
	}
	free(tk);
}

void	finish_tokenizer(t_items *items, t_token *tk)
{
	tk->new = ft_substr(items->line, tk->init, tk->len);
	tk->end = ft_strjoin(tk->end, tk->new);
	tk->posic = tokenizer_find_char(tk->end, ' ');
	items->token.to_print = ft_strtrim(&(tk->end)[tk->posic], " ");
	tokenizer_clean_quotes(items, items->token.to_print, 0, 0);
	items->tokens = ft_split(tk->end, ' ');
	free_tk(tk);
	free (items->line);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysungwon <ysungwon@student.42seoul.kr      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 20:57:52 by ysungwon          #+#    #+#             */
/*   Updated: 2022/09/28 04:21:12 by ysungwon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	tokenizer_find_char(char *string, char needle)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == needle || string[i] == D_QUOTE || string[i] == QUOTE)
			return (i);
		if (string[i] == '?')
			return (i + 1);
		i++;
	}
	return (i);
}

int	fixing_for_norminette(t_items *items, char c, char *aux, int nbr)
{
	if (items->token.quote == 0 && (c == QUOTE || c == D_QUOTE))
		items->token.quote = c;
	else
	{
		if (items->token.quote == c)
			items->token.quote = 0;
		else
		{
			aux[nbr] = c;
			nbr++;
		}
	}
	return (nbr);
}

void	tokenizer_clean_quotes(t_items *items, char *in, int i, int c)
{
	char	*aux;

	items->token.quote = 0;
	aux = ft_strtrim(in, " ");
	items->has_flag = false;
	if (in[0] == '-' && in[1] == 'n')
	{
		items->has_flag = true;
		i += 2;
	}
	while (in[i] == ' ')
		i++;
	while (in[i])
	{
		c = fixing_for_norminette(items, in[i], aux, c);
		i++;
	}
	aux[c] = '\0';
	free(items->token.to_print);
	items->token.to_print = aux;
}

void	tokenizer(t_items *items)
{
	t_token	*tk;

	tk = init_tk();
	items->token.quote = 0;
	tk->end = ft_strdup("");
	if (items->line)
	{
		while ((int)ft_strlen(items->line) > tk->i)
		{
			if (items->token.quote == 0 && (items->line[tk->i] == QUOTE))
				items->token.quote = items->line[tk->i];
			else
			{
				if (items->token.quote == items->line[tk->i])
					items->token.quote = 0;
				if (items->line[tk->i] == '~' && items->token.quote == 0)
					get_home_sign(items, tk);
				else if (items->line[tk->i] == '$' && items->token.quote == 0)
					get_dollar_sign(items, tk);
			}
			tk->len++;
			tk->i++;
		}
		finish_tokenizer(items, tk);
	}
}

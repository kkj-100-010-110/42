/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:43:48 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/30 08:37:58 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error(t_list *a, t_list *b)
{
	clear_list(a);
	clear_list(b);
	write(1, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	ft_error_silence(t_list *a, t_list *b)
{
	clear_list(a);
	clear_list(b);
	exit(EXIT_FAILURE);
}

int	check_lists(t_list *a, t_list *b)
{
	t_list_node	*check1;
	t_list_node	*check2;

	check1 = a->head;
	check2 = b->head;
	while (check1)
	{
		if (check1->data != check2->data)
			break ;
		check1 = check1->next;
		check2 = check2->next;
	}
	if (check1 == NULL)
		return (1);
	else
		return (0);
}

void	check_list(t_list *a, t_list *b)
{
	t_list_node	*check1;
	t_list_node	*check2;

	check1 = a->head;
	check2 = b->head;
	while (check1 && check2)
	{
		if (check1->data != check2->data)
			return ;
		check1 = check1->next;
		check2 = check2->next;
	}
	ft_error_silence(a, b);
}

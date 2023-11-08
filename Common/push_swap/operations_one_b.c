/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:44:19 by gyeokim           #+#    #+#             */
/*   Updated: 2022/07/20 13:44:21 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_np(t_list *stack)
{
	if (stack->count <= 1)
		return ;
	else if (stack->count == 2)
	{
		stack->head->prev = stack->tail;
		stack->tail->next = stack->head;
		stack->head = stack->tail;
		stack->tail = stack->head->next;
		stack->tail->next = NULL;
	}
	else
	{
		stack->head->next->next->prev = stack->head;
		stack->head->prev = stack->head->next;
		stack->head = stack->head->next;
		stack->head->prev->next = stack->head->next;
		stack->head->next = stack->head->prev;
	}
}

void	ss_np(t_list *a, t_list *b)
{
	swap_np(a);
	swap_np(b);
}

void	push_np(t_list *a, t_list *b, int which)
{
	if (which == A)
	{
		if (b->count == 0)
			return ;
		add_head_tail(a, pop(b, HEAD), HEAD);
	}
	else
	{
		if (a->count == 0)
			return ;
		add_head_tail(b, pop(a, HEAD), HEAD);
	}
}

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

void	swap(t_list *stack, int which)
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
	stack->head->prev = NULL;
	if (which == A)
		write (1, "sa\n", 3);
	else if (which == B)
		write (1, "sb\n", 3);
}

void	ss(t_list *a, t_list *b)
{
	swap(a, C);
	swap(b, C);
	write (1, "ss\n", 3);
}

void	push(t_list *a, t_list *b, int which)
{
	if (which == A)
	{
		if (b->count == 0)
			return ;
		add_head_tail(a, pop(b, HEAD), HEAD);
		write (1, "pa\n", 3);
	}
	else
	{
		if (a->count == 0)
			return ;
		add_head_tail(b, pop(a, HEAD), HEAD);
		write (1, "pb\n", 3);
	}
}

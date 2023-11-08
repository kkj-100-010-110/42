/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:44:25 by gyeokim           #+#    #+#             */
/*   Updated: 2022/07/20 13:44:27 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list *stack, int which)
{
	if (stack->count <= 1)
		return ;
	else if (stack->count == 2)
	{
		stack->head->prev = stack->tail;
		stack->tail->next = stack->head;
		stack->head = stack->tail;
		stack->tail = stack->head->next;
		stack->head->prev = NULL;
	}
	else
	{
		stack->head->prev = stack->tail;
		stack->tail->next = stack->head;
		stack->tail = stack->tail->next;
		stack->head = stack->head->next;
		stack->head->prev = NULL;
	}
	stack->tail->next = NULL;
	if (which == A)
		write (1, "ra\n", 3);
	else if (which == B)
		write (1, "rb\n", 3);
}

void	rr(t_list *a, t_list *b)
{
	rotate(a, C);
	rotate(b, C);
	write (1, "rr\n", 3);
}

void	reverse_rotate(t_list *stack, int which)
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
		stack->head->prev = stack->tail;
		stack->tail->next = stack->head;
		stack->tail->prev->next = NULL;
		stack->tail = stack->tail->prev;
		stack->head = stack->head->prev;
	}
	stack->head->prev = NULL;
	if (which == A)
		write (1, "rra\n", 4);
	else if (which == B)
		write (1, "rrb\n", 4);
}

void	rrr(t_list *a, t_list *b)
{
	reverse_rotate(a, C);
	reverse_rotate(b, C);
	write (1, "rrr\n", 4);
}

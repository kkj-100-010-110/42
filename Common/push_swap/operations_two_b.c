/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_two_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:44:25 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/30 11:35:26 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_np(t_list *stack)
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
}

void	rr_np(t_list *a, t_list *b)
{
	rotate_np(a);
	rotate_np(b);
}

void	reverse_rotate_np(t_list *stack)
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
}

void	rrr_np(t_list *a, t_list *b)
{
	reverse_rotate_np(a);
	reverse_rotate_np(b);
}

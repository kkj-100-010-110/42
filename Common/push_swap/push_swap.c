/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:44:40 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/30 04:19:00 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_list *a, t_list *b, t_list *sorted)
{
	struct s_items	item;

	indexing(a, sorted);
	item.pivot = 0;
	item.chunk_size = get_chunk_size(a->count);
	if (a->count <= 5)
	{
		sorting_few(a, b);
		return ;
	}
	stack_a(a, b, item);
	stack_b(a, b);
}

void	stack_a(t_list *a, t_list *b, struct s_items item)
{
	while (a->count)
	{
		if (a->head->index <= item.pivot)
		{
			push(a, b, B);
			item.pivot++;
		}
		else if (a->head->index > item.pivot
			&& a->head->index <= item.pivot + item.chunk_size)
		{
			push(a, b, B);
			rotate(b, B);
			item.pivot++;
		}
		else if (a->head->index > item.pivot + item.chunk_size)
			rotate(a, A);
	}
}

void	stack_b(t_list *a, t_list *b)
{
	int			max_idx;

	while (b->count)
	{
		max_idx = find_max_idx(b);
		while (max_idx != b->head->index)
		{
			if (find_upper_lower(b, max_idx))
				rotate(b, B);
			else
				reverse_rotate(b, B);
		}
		push(a, b, A);
	}
}

int	find_upper_lower(t_list *b, int max)
{
	t_list_node	*p;
	int			marker;

	p = b->head;
	marker = b->count;
	while (p)
	{
		if (p->index == max)
			break ;
		p = p->next;
		marker--;
	}
	if (marker < b->count / 2)
		return (0);
	else
		return (1);
}

int	find_max_idx(t_list *b)
{
	t_list_node	*p;
	int			max_idx;

	p = b->head;
	max_idx = 0;
	while (p)
	{
		if (max_idx < p->index)
			max_idx = p->index;
		p = p->next;
	}
	return (max_idx);
}

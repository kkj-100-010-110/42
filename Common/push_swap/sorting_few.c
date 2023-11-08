/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_few.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:44:55 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/30 04:19:24 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorting_few(t_list *a, t_list *b)
{
	if (a->count == 2)
	{
		if (a->head->data > a->tail->data)
			swap(a, A);
	}
	else if (a->count == 3)
		when_three(a);
	else if (a->count == 4)
		when_four(a, b);
	else if (a->count == 5)
		when_five(a, b);
	return ;
}

void	when_three(t_list *a)
{
	if (a->head->data > a->head->next->data)
	{
		if (a->head->data > a->head->next->next->data)
		{
			if (a->head->next->data > a->head->next->next->data)
			{
				rotate(a, A);
				swap(a, A);
			}
			else
				rotate(a, A);
		}
		else
			swap(a, A);
	}
	else
	{
		if (a->head->data > a->head->next->next->data)
			reverse_rotate(a, A);
		else
		{
			reverse_rotate(a, A);
			swap(a, A);
		}
	}
}

void	when_four(t_list *a, t_list *b)
{
	int	max;

	max = 3;
	while (1)
	{
		if (a->head->index == max)
			break ;
		else
			rotate(a, A);
	}
	push(a, b, B);
	if (a->head->index != 0
		|| a->head->next->index != 1)
		when_three(a);
	push(a, b, A);
	rotate(a, A);
}

void	when_five(t_list *a, t_list *b)
{
	int	max_idx;
	int	min_idx;

	max_idx = 4;
	min_idx = 0;
	while (a->count > 3)
	{
		if (a->head->index == max_idx
			|| a->head->index == min_idx)
			push(a, b, B);
		else
			rotate(a, A);
	}
	if (a->head->index != 1
		|| a->head->next->index != 2)
		when_three(a);
	push(a, b, A);
	if (a->head->index == max_idx)
		rotate(a, A);
	push(a, b, A);
	if (a->head->index == max_idx)
		rotate(a, A);
}

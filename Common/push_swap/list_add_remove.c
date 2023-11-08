/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:44:02 by gyeokim           #+#    #+#             */
/*   Updated: 2022/07/20 14:06:39 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_head_tail(t_list *list, t_list_node *new, int where)
{
	if (!list || !new)
		return ;
	if (list->count == 0)
	{
		list->head = new;
		list->tail = new;
	}
	else if (!where)
	{
		new->next = list->head;
		list->head->prev = new;
		list->head = new;
	}
	else
	{
		new->prev = list->tail;
		list->tail->next = new;
		list->tail = new;
	}
	list->count++;
}

int	add_sorted_list(t_list *list, t_list_node *new)
{
	t_list_node	*target;

	target = list->head;
	if (list->count == 0 || new->data < target->data)
	{
		add_head_tail(list, new, HEAD);
		return (0);
	}
	while (target)
	{
		if (new->data < target->data)
		{
			connect(list, new, target);
			return (0);
		}
		else if (new->data > target->data)
			target = target->next;
		else
		{
			free(new);
			return (1);
		}
	}
	add_head_tail(list, new, TAIL);
	return (0);
}

void	connect(t_list *list, t_list_node *new, t_list_node *target)
{
	new->next = target;
	new->prev = target->prev;
	target->prev->next = new;
	target->prev = new;
	list->count++;
}

void	remove_head_tail(t_list *list, int where)
{
	t_list_node	*target;

	if (!list || list->count == 0)
		return ;
	if (list->count == 1)
	{
		target = list->head;
		list->head = NULL;
		list->tail = NULL;
	}
	else if (!where)
	{
		target = list->head;
		list->head = list->head->next;
		list->head->prev = NULL;
	}
	else
	{
		target = list->tail;
		list->tail = list->tail->prev;
		list->tail->next = NULL;
	}
	free(target);
	list->count--;
}

void	remove_node(t_list *list, int data)
{
	t_list_node	*target;

	target = list->head;
	while (target && (target->data != data))
		target = target->next;
	if (!target)
		return ;
	if (target->prev == NULL)
		remove_head_tail(list, HEAD);
	else if (target->next != NULL)
	{
		target->prev->next = target->next;
		target->next->prev = target->prev;
		free(target);
		list->count--;
	}
	else
		remove_head_tail(list, TAIL);
}

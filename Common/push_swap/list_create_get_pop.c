/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create_get_pop.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:44:07 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/30 00:35:55 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*create_list(void)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		exit(EXIT_FAILURE);
	ft_memset(new, 0, sizeof(t_list));
	return (new);
}

t_list_node	*create_node(int data)
{
	t_list_node	*new;

	new = (t_list_node *)malloc(sizeof(t_list_node));
	if (!new)
		exit(EXIT_FAILURE);
	new->data = data;
	new->index = 0;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

t_list_node	*get_node(t_list *list, int index, int where)
{
	t_list_node	*target;

	if (index >= list->count || index < 0)
		return (NULL);
	if (!where)
	{
		target = list->head;
		while (index--)
			target = target->next;
		return (target);
	}
	else
	{
		target = list->tail;
		while (index--)
			target = target->prev;
		return (target);
	}
}

t_list_node	*pop(t_list *stack, int which)
{
	t_list_node	*target;

	if (stack->count == 1)
	{
		target = stack->head;
		stack->head = NULL;
		stack->tail = NULL;
	}
	else if (which == HEAD)
	{
		target = stack->head;
		stack->head = stack->head->next;
		stack->head->prev = NULL;
		target->next = NULL;
	}
	else
	{
		target = stack->tail;
		stack->tail = stack->tail->prev;
		stack->tail->next = NULL;
		target->prev = NULL;
	}
	stack->count--;
	return (target);
}

void	clear_list(t_list *list)
{
	t_list_node	*target;
	t_list_node	*remove;

	target = list->head;
	while (target)
	{
		remove = target;
		target = target->next;
		free(remove);
		list->count--;
	}
	free(target);
	free(list);
}

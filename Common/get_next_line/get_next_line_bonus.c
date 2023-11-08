/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:36:46 by gyeokim           #+#    #+#             */
/*   Updated: 2022/04/13 15:39:22 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static t_list	*list;
	t_list			*p;
	char			*result;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (get_node(list, fd) == NULL)
		append_node(&list, fd);
	p = get_node(list, fd);
	result = NULL;
	result = str_allocation(result, BUFFER_SIZE + 1);
	if (result == NULL)
		return (NULL);
	result = read_buffer(result, p->buffer, p->fd);
	if (*result == '\0')
	{
		free(result);
		result = NULL;
		remove_node(&list, p->fd);
	}
	return (result);
}

void	append_node(t_list **list, int fd)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return ;
	new->buffer = str_allocation(new->buffer, BUFFER_SIZE + 1);
	if (new->buffer == NULL)
		return ;
	new->fd = fd;
	new->next = NULL;
	while (*list != NULL && (*list)->fd != fd)
		list = &(*list)->next;
	*list = new;
}

t_list	*get_node(t_list *list, int fd)
{
	while (list != NULL && list->fd != fd)
		list = list->next;
	return (list);
}

void	remove_node(t_list **list, int fd)
{
	t_list	*temp;

	while (*list != NULL && (*list)->fd != fd)
		list = &(*list)->next;
	if (*list)
	{
		temp = *list;
		*list = (*list)->next;
		free(temp->buffer);
		free(temp);
	}
}

char	*read_buffer(char *result, char *buffer, int fd)
{
	int			check;

	check = 0;
	if (*result != '\0')
		reset_buffer(result, ft_strlen(result) + 1);
	if (*buffer != '\0')
	{
		result = buffer_to_result(result, buffer, &check);
		if (check == 1)
			return (result);
	}
	while (read(fd, buffer, BUFFER_SIZE) > 0)
	{
		result = buffer_to_result(result, buffer, &check);
		if (check == 1)
			return (result);
	}
	return (result);
}

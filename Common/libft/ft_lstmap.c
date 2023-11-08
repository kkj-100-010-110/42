/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 18:27:45 by gyeokim           #+#    #+#             */
/*   Updated: 2021/12/21 17:07:00 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*temp;

	if (lst == NULL)
		return (NULL);
	result = ft_lstnew((*f)(lst->content));
	if (!result)
		return (NULL);
	lst = lst->next;
	temp = result;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			ft_lstdelone(result, del);
			return (0);
		}
		lst = lst->next;
		ft_lstadd_back(&result, temp);
		temp = temp->next;
	}
	return (result);
}

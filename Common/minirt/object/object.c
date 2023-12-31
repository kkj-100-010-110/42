/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnam <jnam@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 15:49:07 by jnam              #+#    #+#             */
/*   Updated: 2022/11/24 15:49:08 by jnam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	oadd(t_object **list, t_object *new_obj)
{
	t_object	*cur;

	if (*list == NULL)
	{
		*list = new_obj;
		return ;
	}
	cur = *list;
	while (cur->next)
		cur = cur->next;
	cur->next = new_obj;
}

t_object	*object(void *object, int type)
{
	t_object	*obj;

	obj = wrap_malloc(sizeof(t_object));
	obj->element = object;
	obj->type = type;
	obj->next = 0;
	return (obj);
}

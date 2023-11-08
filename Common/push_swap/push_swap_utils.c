/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:44:51 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/30 11:49:37 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*ft_memset(void *dest, int val, size_t len)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)dest;
	while (len-- > 0)
		*ptr++ = val;
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

void	indexing(t_list *a, t_list *sorted)
{
	t_list_node	*p;
	t_list_node	*q;
	int			i;

	p = sorted->head;
	i = 0;
	while (p)
	{
		q = a->head;
		while (q)
		{
			if (p->data == q->data)
			{
				q->index = i;
				break ;
			}
			q = q->next;
		}
		i++;
		p = p->next;
	}
}

long long	get_chunk_size(int count)
{
	long long	result;

	result = 0.000000053 * count * count + 0.03 * count + 14.5;
	return (result);
}

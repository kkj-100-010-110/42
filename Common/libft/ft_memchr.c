/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:45:01 by gyeokim           #+#    #+#             */
/*   Updated: 2021/12/21 19:11:44 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	ch;
	size_t			i;

	ch = c;
	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == ch)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

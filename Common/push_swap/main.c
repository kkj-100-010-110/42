/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:44:13 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/30 08:41:01 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*sorted;
	int		i;

	a = create_list();
	sorted = create_list();
	if (argc < 2)
		ft_error_silence(a, sorted);
	i = 1;
	while (i < argc)
	{
		ft_check_args(argv[i], a, sorted);
		i++;
	}
	check_list(a, sorted);
	b = create_list();
	push_swap(a, b, sorted);
	clear_list(a);
	clear_list(b);
	clear_list(sorted);
	return (0);
}

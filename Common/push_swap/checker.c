/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 04:51:33 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/30 11:24:59 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	clear_lists(t_list *a, t_list *b, t_list *sorted);
static void	command_check(t_list *a, t_list *b, t_list *sorted, char *cmd);
static void	result_check(t_list *a, t_list *b, t_list *sorted);
static int	push_swap_checker(t_list *a, t_list *b, t_list *sorted);

static void	result_check(t_list *a, t_list *b, t_list *sorted)
{
	if (b->count == 0 && check_lists(a, sorted))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

static void	command_check(t_list *a, t_list *b, t_list *sorted, char *cmd)
{
	if (ft_strncmp("pa\n", cmd, 3) == 0)
		push_np(a, b, A);
	else if (ft_strncmp("ra\n", cmd, 3) == 0)
		rotate_np(a);
	else if (ft_strncmp("rra\n", cmd, 4) == 0)
		reverse_rotate_np(a);
	else if (ft_strncmp("sa\n", cmd, 3) == 0)
		swap_np(a);
	else if (ft_strncmp("pb\n", cmd, 3) == 0)
		push_np(a, b, B);
	else if (ft_strncmp("rb\n", cmd, 3) == 0)
		rotate_np(b);
	else if (ft_strncmp("rrb\n", cmd, 4) == 0)
		reverse_rotate_np(b);
	else if (ft_strncmp("sb\n", cmd, 3) == 0)
		swap_np(b);
	else if (ft_strncmp("rr\n", cmd, 3) == 0)
		rr_np(a, b);
	else if (ft_strncmp("rrr\n", cmd, 4) == 0)
		rrr_np(a, b);
	else if (ft_strncmp("ss\n", cmd, 3) == 0)
		ss_np(a, b);
	else
		clear_lists(a, b, sorted);
}

static void	clear_lists(t_list *a, t_list *b, t_list *sorted)
{
	clear_list(a);
	clear_list(b);
	clear_list(sorted);
	write(1, "Error\n", 6);
	exit (EXIT_FAILURE);
}

static int	push_swap_checker(t_list *a, t_list *b, t_list *sorted)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (ft_strlen(str) > 4)
		{
			free(str);
			clear_lists(a, b, sorted);
		}
		command_check(a, b, sorted, str);
		free(str);
		str = NULL;
	}
	result_check(a, b, sorted);
	clear_list(a);
	clear_list(b);
	clear_list(sorted);
	return (0);
}

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
	b = create_list();
	push_swap_checker(a, b, sorted);
	return (0);
}

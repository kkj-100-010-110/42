/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:53:14 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/30 06:24:08 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 1024
# define INT_MIN -2147483648
# define INT_MAX 2147483647
# define HEAD 0
# define TAIL 1
# define A 0
# define B 1
# define C 2

typedef struct s_list_node
{
	int					data;
	int					index;
	struct s_list_node	*next;
	struct s_list_node	*prev;
}	t_list_node;

typedef struct s_list
{
	int			count;
	t_list_node	*head;
	t_list_node	*tail;
}	t_list;

typedef struct s_items
{
	int			pivot;
	long long	chunk_size;
}	t_items;

t_list			*create_list(void);
t_list_node		*create_node(int data);
t_list_node		*get_node(t_list *list, int index, int where);
t_list_node		*pop(t_list *stack, int which);
void			add_head_tail(t_list *list, t_list_node *new, int where);
int				add_sorted_list(t_list *list, t_list_node *new);
void			connect(t_list *list, t_list_node *new, t_list_node *target);
void			remove_head_tail(t_list *list, int where);
void			remove_node(t_list *list, int data);
void			clear_list(t_list *list);
void			ft_check_args(char const *s, t_list *a, t_list *sorted);
void			ft_error(t_list *a, t_list *b);
void			ft_error_silence(t_list *a, t_list *b);
void			check_list(t_list *a, t_list *b);
void			*ft_memset(void *dest, int val, size_t len);
size_t			ft_strlen(const char *s);
void			push(t_list *a, t_list *b, int which);
void			swap(t_list *stack, int which);
void			rotate(t_list *stack, int which);
void			reverse_rotate(t_list *stack, int which);
void			rrr(t_list *a, t_list *b);
void			rr(t_list *a, t_list *b);
void			ss(t_list *a, t_list *b);
void			push_swap(t_list *a, t_list *b, t_list *sorted);
void			stack_a(t_list *a, t_list *b, struct s_items item);
void			stack_b(t_list *a, t_list *b);
void			sorting_few(t_list *a, t_list *b);
void			when_three(t_list *a);
void			when_four(t_list *a, t_list *b);
void			when_five(t_list *a, t_list *b);
void			indexing(t_list *a, t_list *sorted);
long long		get_chunk_size(int count);
int				find_upper_lower(t_list *b, int max);
int				find_max_idx(t_list *b);
int				find_min_idx(t_list *a);
int				check_lists(t_list *a, t_list *b);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			push_np(t_list *a, t_list *b, int which);
void			swap_np(t_list *stack);
void			rotate_np(t_list *stack);
void			reverse_rotate_np(t_list *stack);
void			rrr_np(t_list *a, t_list *b);
void			rr_np(t_list *a, t_list *b);
void			ss_np(t_list *a, t_list *b);

char			*get_next_line(int fd);
char			*str_allocation(char *str, int n);
char			*read_buffer(char *result, char *buffer, int fd);
char			*buffer_to_result(char *result, char *buffer, int *check);
void			reset_buffer(char *buffer, int n);
int				ft_strlen_gnl(char *str);
char			*cpy_join(char *result, char *buffer, int n);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 18:32:31 by gyeokim           #+#    #+#             */
/*   Updated: 2022/04/13 15:32:38 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <stdlib.h>
# include <unistd.h>

typedef struct t_list_type
{
	char				*buffer;
	int					fd;
	struct t_list_type	*next;
}	t_list;

t_list	*get_node(t_list *gnl, int fd);
void	append_node(t_list **gnl, int fd);
void	remove_node(t_list **gnl, int fd);
char	*get_next_line(int fd);
char	*read_buffer(char *result, char *buffer, int fd);
char	*buffer_to_result(char *result, char *buffer, int *check);
char	*str_allocation(char *str, int n);
void	reset_buffer(char *buffer, int n);
int		ft_strlen(char *str);
char	*cpy_join(char *result, char *buffer, int n);

#endif

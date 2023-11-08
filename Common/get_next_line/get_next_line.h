/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:26:28 by gyeokim           #+#    #+#             */
/*   Updated: 2022/03/19 20:49:06 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_buffer(char *result, char *buffer, int fd);
char	*buffer_to_result(char *result, char *buffer, int *check);
char	*str_allocation(char *str, int n);
void	reset_buffer(char *buffer, int n);
int		ft_strlen(char *str);
char	*cpy_join(char *result, char *buffer, int n);

#endif

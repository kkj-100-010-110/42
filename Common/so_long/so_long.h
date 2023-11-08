/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 13:47:25 by gyeokim           #+#    #+#             */
/*   Updated: 2022/08/17 13:51:04 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# define BUFFER_SIZE	1024

# define KEY_ESC	53
# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2

# define KEY_PRESS	2
# define KEY_EXIT	17

typedef struct s_img
{
	void	*character;
	void	*collect;
	void	*road;
	void	*wall;
	void	*gate;
	void	*gate_open;
}	t_img;

typedef struct s_parts
{
	void	*mlx;
	void	*win;
	char	*map_line;
	int		x;
	int		y;
	int		step;
	int		collect_num;
	int		collect_cnt;
	int		gate_num;
	t_img	img;
}	t_parts;

void	init_parts(t_parts *parts);
void	ft_error(int code, t_parts *parts);
void	read_map(char *file_name, t_parts *parts);
void	check_walls(t_parts *parts);
void	check_parts(t_parts *parts);
void	check_map(t_parts *parts);
void	create_map(t_parts *parts);
void	setup_image(t_parts *parts);
void	put_img(t_parts *parts, int x, int y);
int		ft_exit(t_parts *parts);
int		complete(t_parts *parts);
void	up(t_parts *parts);
void	left(t_parts *parts);
void	down(t_parts *parts);
void	right(t_parts *parts);
int		setup_key(int code, t_parts *parts);

char	*get_next_line(int fd);
char	*read_buffer(char *result, char *buffer, int fd);
char	*buffer_to_result(char *result, char *buffer, int *check);
char	*str_allocation(char *str, int n);
void	reset_buffer(char *buffer, int n);
char	*cpy_join(char *result, char *buffer, int n);

int		ft_strlen(char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);

#endif

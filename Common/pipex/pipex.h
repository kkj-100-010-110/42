/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:32:22 by gyeokim           #+#    #+#             */
/*   Updated: 2022/07/01 17:21:42 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define ERR_ARG 1
# define ERR 0
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>

char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *s);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	processing(char *command, char **envp);
char	*find_pathname(char *command, char **envp);
char	**find_env_path(char **envp);
void	process_first_cmd(int fd[2], char **argv, char **envp);
void	process_second_cmd(int fd[2], char **argv, char **envp);
void	ft_error(int n);
void	to_free(char **av);

#endif

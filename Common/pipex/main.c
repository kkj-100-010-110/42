/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:32:13 by gyeokim           #+#    #+#             */
/*   Updated: 2022/07/02 18:58:42 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		ft_error(ERR_ARG);
	if (pipe(fd) == -1)
		ft_error(ERR);
	pid1 = fork();
	if (pid1 == -1)
		ft_error(ERR);
	if (pid1 == 0)
		process_first_cmd(fd, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		ft_error(ERR);
	if (pid2 == 0)
		process_second_cmd(fd, argv, envp);
	if (close(fd[0]) == -1)
		ft_error(ERR);
	if (close(fd[1]) == -1)
		ft_error(ERR);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

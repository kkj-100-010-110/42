/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gyeokim <gyeokim@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:31:39 by gyeokim           #+#    #+#             */
/*   Updated: 2022/07/02 19:45:00 by gyeokim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	processing(char *command, char **envp)
{
	char	**cmd;
	char	*pathname;

	cmd = ft_split(command, ' ');
	if (!cmd)
		ft_error(ERR);
	pathname = find_pathname(cmd[0], envp);
	if (execve(pathname, cmd, envp) == -1)
		ft_error(ERR);
}

char	*find_pathname(char *command, char **envp)
{
	int		i;
	char	**env_path;
	char	*cmd_path;
	char	*pathname;

	if (!access(command, F_OK))
		return (command);
	cmd_path = ft_strjoin("/", command);
	env_path = find_env_path(envp);
	if (!cmd_path || !env_path)
		ft_error(ERR);
	i = 0;
	while (env_path[i])
	{
		pathname = ft_strjoin(env_path[i], cmd_path);
		if (!pathname)
			ft_error(ERR);
		if (!access(pathname, F_OK))
			break ;
		i++;
		free(pathname);
	}
	to_free(env_path);
	free(cmd_path);
	return (pathname);
}

char	**find_env_path(char **envp)
{
	char	*result;

	while (ft_strncmp("PATH=", *envp, 5))
		envp++;
	result = *envp + 5;
	return (ft_split(result, ':'));
}

void	process_first_cmd(int fd[2], char **argv, char **envp)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0744);
	if (infile == -1)
		ft_error(ERR);
	if (dup2(fd[1], STDOUT_FILENO) == -1)
		ft_error(ERR);
	if (dup2(infile, STDIN_FILENO) == -1)
		ft_error(ERR);
	if (close(fd[0]) == -1)
		ft_error(ERR);
	if (close(infile) == -1)
		ft_error(ERR);
	if (close(fd[1]) == -1)
		ft_error(ERR);
	processing(argv[2], envp);
}

void	process_second_cmd(int fd[2], char **argv, char **envp)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0744);
	if (outfile == -1)
		ft_error(ERR);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		ft_error(ERR);
	if (dup2(outfile, STDOUT_FILENO) == -1)
		ft_error(ERR);
	if (close(fd[0]) == -1)
		ft_error(ERR);
	if (close(outfile) == -1)
		ft_error(ERR);
	if (close(fd[1]) == -1)
		ft_error(ERR);
	processing(argv[3], envp);
}

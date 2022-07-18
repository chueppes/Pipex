/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:36:11 by acalvo4           #+#    #+#             */
/*   Updated: 2022/07/18 09:36:12 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, char **envp, int *fd, int *fdpipe)
{
	int		exv;
	char	*path;
	pid_t	pid1;
	char	**cmd;

	pid1 = fork();
	if (pid1 <= -1)
		return ;
	if (pid1 == 0)
	{
		cmd = ft_split(argv[2], ' ');
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] <= -1)
			error(ERROR_INFILE);
		dup2(fd[0], STDIN_FILENO);
		dup2(fdpipe[1], STDOUT_FILENO);
		close(fdpipe[0]);
		path = ft_path(envp, cmd[0]);
		exv = execve(path, cmd, envp);
		if (exv == -1)
			error(ERROR_CMD);
		free(cmd);
	}
}

void	child2(char **argv, char **envp, int *fd, int *fdpipe)
{
	int		exv;
	char	*path;
	pid_t	pid2;
	char	**cmd;

	pid2 = fork();
	if (pid2 <= -1)
		return ;
	if (pid2 == 0)
	{
		cmd = ft_split(argv[3], ' ');
		fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (fd[1] <= -1)
			error(ERROR_OUTFILE);
		dup2(fd[1], STDOUT_FILENO);
		dup2(fdpipe[0], STDIN_FILENO);
		close(fdpipe[1]);
		path = ft_path(envp, cmd[0]);
		exv = execve(path, cmd, envp);
		if (exv == -1)
			error(ERROR_CMD);
		free(cmd);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	fdpipe[2];
	int	status;

	if (argc == 5)
	{
		if (pipe(fdpipe) <= -1)
			error(ERROR_PIPE);
		child(argv, envp, fd, fdpipe);
		child2(argv, envp, fd, fdpipe);
		close(fdpipe[0]);
		close(fdpipe[1]);
		wait(&status);
		wait(&status);
	}
	else
		ft_putchar(ERROR_INPUT);
}

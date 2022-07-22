/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:36:11 by acalvo4           #+#    #+#             */
/*   Updated: 2022/07/22 14:32:09 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, char **envp, int *fd, int *fdpipe)
{
	pid_t	pid1;
	char	**cmd;
	char	*path;

	pid1 = fork();
	if (pid1 <= -1)
		error("fork");
	if (pid1 == 0)
	{
		cmd = ft_split(argv[2], ' ');
		cmd = ft_trim(cmd);
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] <= -1)
			error(argv[1]);
		dup2(fd[0], STDIN_FILENO);
		dup2(fdpipe[1], STDOUT_FILENO);
		close(fdpipe[0]);
		path = ft_path(envp, cmd[0]);
		execve(path, cmd, envp);
		write (2, cmd, check_null(cmd, 0));
		write (2, ": command not found\n", 20);
		exit(127);
	}
}

void	exec (char *cmd, char **anv)
{
	char **args -------------------
}

void	child2(char **argv, char **envp, int *fd, int *fdpipe)
{
	pid_t	pid2;
	char	**cmd;
	char	*path;

	pid2 = fork();
	if (pid2 <= -1)
		error("fork");
	if (pid2 == 0)
	{
		cmd = ft_split(argv[3], ' ');
		cmd = ft_trim(cmd);
		fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
		if (fd[1] <= -1)
			error(argv[4]);
		dup2(fd[1], STDOUT_FILENO);
		dup2(fdpipe[0], STDIN_FILENO);
		close(fdpipe[1]);
		path = ft_path(envp, cmd[0]);
		execve(path, cmd, envp);
		write (2, cmd, check_null(cmd, 0));
		write (2, ": command not found\n", 20);
		exit(127);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	fdpipe[2];
	int	status;

	errno = 0;
	if (argc == 5)
	{
		if (pipe(fdpipe) <= -1)
			error(NULL);
		child(argv, envp, fd, fdpipe);
		child2(argv, envp, fd, fdpipe);
		close(fdpipe[0]);
		close(fdpipe[1]);
		waitpid(-1, &status, 0);
		waitpid(-1, &status, 0);
	}
	else
	{
		write(2, "Invalid arguments\n", 18);
		exit(EXIT_FAILURE);
	}
}

char	**ft_trim(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		cmd[i] = ft_strtrim(cmd[i], "'\"");
		i++;
	}
	return (cmd);
}

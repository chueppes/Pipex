/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:36:11 by acalvo4           #+#    #+#             */
/*   Updated: 2022/07/18 21:00:10 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	child(char **argv, char **envp, int *fd, int *fdpipe)
{
	char	*path;
	pid_t	pid1;
	char	**cmd;
	int		i;

	i = 0;
	pid1 = fork();
	if (pid1 <= -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	if (pid1 == 0)
	{
		cmd = ft_split(argv[2], ' ');
		while (cmd[i])
		{
			cmd[i] = ft_strtrim(cmd[i], "'\"");
			i++;
		}
		
		fd[0] = open(argv[1], O_RDONLY);
			if (fd[0] <= -1)
			{
				perror("");
				exit(EXIT_FAILURE);
			}
		dup2(fd[0], STDIN_FILENO);
		dup2(fdpipe[1], STDOUT_FILENO);
		close(fdpipe[0]);
		
		path = ft_path(envp, cmd[0]);
		if(execve(path, cmd, envp) < 0)
		{
			perror("");
			exit(EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

int	child2(char **argv, char **envp, int *fd, int *fdpipe)
{
	char	*path;
	pid_t	pid2;
	char	**cmd;
	int		i;

	i = 0;
	pid2 = fork();
	if (pid2 <= -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	
	cmd = ft_split(argv[3], ' ');
	while (cmd[i])
	{
		cmd[i] = ft_strtrim(cmd[i], "'\"");
		i++;
	}
	
	fd[1] = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd[1] <= -1)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(fdpipe[0], STDIN_FILENO);
	close(fdpipe[1]);
	
	path = ft_path(envp, cmd[0]);
	if(execve(path, cmd, envp) < 0)
	{
		perror("");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	fdpipe[2];
	int	status;

	if (argc == 5)
	{
		if (pipe(fdpipe) <= -1)
			{
				perror("");
				exit(EXIT_FAILURE);
			}
		child(argv, envp, fd, fdpipe);
		child2(argv, envp, fd, fdpipe);
		close(fdpipe[0]);
		close(fdpipe[1]);
		wait(&status);
		wait(&status);
	}
	else
		error_return("Erros nos argumentos.", 1);
}

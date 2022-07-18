/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:36:22 by acalvo4           #+#    #+#             */
/*   Updated: 2022/07/18 09:36:23 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <errno.h>

# define ERROR_INFILE "Infile"
# define ERROR_OUTFILE "Outfile"
# define ERROR_INPUT "Invalid number of arguments\n"
# define ERROR_PIPE "Error: Pipe"
# define ERROR_CMD "Command not found\n"

void	child(char **argv, char **envp, int *fd, int *fdpipe);
void	child2(char **argv, char **envp, int *fd, int *fdpipe);
void	error(char *msg);
int		ft_putchar(char *c);
char	*ft_put(char *c);
char	*ft_path(char **envp, char *cmd);
char	*test_path(char **path, char *cmd);

#endif

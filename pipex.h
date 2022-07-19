/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:36:22 by acalvo4           #+#    #+#             */
/*   Updated: 2022/07/18 20:15:28 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <errno.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

int		child(char **argv, char **envp, int *fd, int *fdpipe);
int		child2(char **argv, char **envp, int *fd, int *fdpipe);

void	errorm(char *msg, int code);
int		error_return(char *msg, int code);
int		ft_putchar(char *c);

char	*ft_path(char **envp, char *cmd);
char	*test_path(char **path, char *cmd);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:36:22 by acalvo4           #+#    #+#             */
/*   Updated: 2022/07/22 14:26:38 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <sys/wait.h>

void	child(char **argv, char **envp, int *fd, int *fdpipe);
void	child2(char **argv, char **envp, int *fd, int *fdpipe);
int		ft_putchar(char *c);
void	error_cmd(char **cmd);
void	error(char *message);
char	*ft_path(char **envp, char *cmd);
char	*test_path(char **path, char *cmd);
char	**ft_trim(char **cmd);
int		check_null(char **str, char	c);

#endif

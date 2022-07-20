/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:35:50 by acalvo4           #+#    #+#             */
/*   Updated: 2022/07/20 16:38:03 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *message)
{
	if (errno == 0)
		write(2, "Error\n", 6);
	else
		perror(message);
	exit(EXIT_FAILURE);
}

void	error_cmd(char **cmd)
{
	write(2, cmd[0], ft_strlen(cmd[0]));
	write(2, ": command not found\n", 20);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:35:50 by acalvo4           #+#    #+#             */
/*   Updated: 2022/07/22 14:27:23 by acalvo4          ###   ########.fr       */
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
	perror("");
	exit(127);
}

int		check_null(char **str, char	c)
{
	int	i;

	i = 0;
	while (str[i] && *str[i] != c)
		i++;
	if (*str[i] == c)
		return (c);
	return (-1);
}
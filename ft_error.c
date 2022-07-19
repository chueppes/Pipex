/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:35:50 by acalvo4           #+#    #+#             */
/*   Updated: 2022/07/18 20:23:39 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	errorm(char *msg, int code)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	exit(code);
}

int	ft_putchar(char *c)
{
	write(2, c, ft_strlen(c));
	exit(EXIT_FAILURE);
}

int	error_return(char *msg, int code)
{
	ft_putendl_fd(msg, STDERR_FILENO);
	return (code);
}

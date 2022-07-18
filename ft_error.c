/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 09:35:50 by acalvo4           #+#    #+#             */
/*   Updated: 2022/07/18 09:35:53 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

int	ft_putchar(char *c)
{
	write(2, c, ft_strlen(c));
	exit(EXIT_FAILURE);
}

char	*ft_put(char *c)
{
	write(2, c, ft_strlen(c));
	exit(EXIT_FAILURE);
}

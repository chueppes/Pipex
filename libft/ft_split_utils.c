/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 12:18:40 by acalvo4           #+#    #+#             */
/*   Updated: 2022/07/20 12:38:17 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

const char	*check_quotation(const char *s)
{
	if (*s == '"')
	{
		s++;
		while (*s != '"')
			s++;
	}
	if (*s == 39)
	{
		s++;
		while (*s != 39)
			s++;
	}
	return (s);
}
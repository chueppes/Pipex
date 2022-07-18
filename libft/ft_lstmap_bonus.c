/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalvo4 <acalvo4@student.42.rio>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 11:32:29 by acalvo4           #+#    #+#             */
/*   Updated: 2022/06/01 09:44:56 by acalvo4          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list1;
	t_list	*list2;

	if (!lst || !f)
		return (NULL);
	list1 = ft_lstnew(f(lst->content));
	list2 = list1;
	while (lst->next)
	{
		lst = lst->next;
		list2->next = ft_lstnew(f(lst->content));
		if (!(list2->next))
		{
			ft_lstclear(&list1, del);
			return (NULL);
		}
		list2 = list2->next;
	}
	return (list1);
}

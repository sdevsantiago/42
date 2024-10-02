/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:10:51 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/02 10:15:06 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates the list LST and applies the function F to the
   content of each node. Applies the function DEL if needed.
   The result is returned in a new list.  */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*c;

	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		c = ft_lstnew(f(lst->content));
		if (!c)
		{
			ft_lstclear(&c, del);
			return (NULL);
		}
		ft_lstadd_back(&c, c);
		lst = lst->next;
	}
	return (c);
}

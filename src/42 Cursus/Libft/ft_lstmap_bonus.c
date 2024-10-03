/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 10:10:51 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/03 19:00:01 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Iterates the list LST and applies the function F to the
   content of each node. Applies the function DEL if needed.
   The result is returned in a new list.  */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*l;
	t_list	*n;

	n = NULL;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		n = ft_lstnew(f(lst->content));
		if (!n)
		{
			ft_lstclear(&n, del);
			return (NULL);
		}
		ft_lstadd_back(&l, n);
		lst = lst->next;
	}
	return (l);
}

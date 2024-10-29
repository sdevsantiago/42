/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:51:59 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/08 14:33:45 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Deletes from the node LST onwards.  */
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		node = *lst;
		*lst = (*lst)->next;
		del(node->content);
		free(node);
	}
	*lst = NULL;
}

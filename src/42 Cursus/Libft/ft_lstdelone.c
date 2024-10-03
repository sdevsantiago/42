/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/02 09:29:02 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/02 10:00:16 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Frees the node LST content using the function DEL.  */
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	t_list	*n;

	if (!lst || !del)
		return ;
	n = lst;
	lst = lst->next;
	del(n->content);
}

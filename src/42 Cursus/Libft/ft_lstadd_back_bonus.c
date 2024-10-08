/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:57:46 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/08 14:32:20 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Adds the node NEW to the last position of the list LST.  */
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*aux_lst;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		aux_lst = ft_lstlast(*lst);
		aux_lst->next = new;
	}
	new->next = NULL;
}

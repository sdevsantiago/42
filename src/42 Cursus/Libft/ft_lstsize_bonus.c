/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 21:20:44 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/02 10:19:31 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Measures a list.  */
int	ft_lstsize(t_list *lst)
{
	int	s;

	if (!lst)
		return (0);
	s = 0;
	while (lst)
	{
		s++;
		lst = lst->next;
	}
	return (s);
}

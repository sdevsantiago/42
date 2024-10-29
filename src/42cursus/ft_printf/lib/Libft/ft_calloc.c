/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:17:43 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/07 20:40:00 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory for an array of NMEMB elements of SIZE bytes each.
   Each byte is set to 0.  */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*new_addr;

	new_addr = (void *)malloc(nmemb * size);
	if (!new_addr)
		return (NULL);
	ft_bzero(new_addr, nmemb * size);
	return (new_addr);
}

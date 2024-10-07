/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:17:43 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/07 20:39:05 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory for an array of NMEMB elements of SIZE bytes each.
   Each byte is set to 0.  */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;

	c = (void *)malloc(nmemb * size);
	if (!c)
		return (NULL);
	ft_bzero(c, nmemb * size);
	return (c);
}

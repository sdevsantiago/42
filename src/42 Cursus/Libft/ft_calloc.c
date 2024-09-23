/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:17:43 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/23 15:30:50 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Allocates memory for an array of NMEMB elements of SIZE bytes each.
   Each byte is set to 0.  */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*c;

	if (!nmemb || !size)
		return (NULL);
	c = (void *)malloc(nmemb * size);
	ft_bzero(c, size);
	return (c);
}

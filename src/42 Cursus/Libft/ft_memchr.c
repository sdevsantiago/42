/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:52:33 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/26 21:30:10 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Scans the initial N bytes of the memory area pointed to by S for the first
   instance of C.  */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*d = (unsigned char *)s;

	while (n--)
	{
		if (*d == (unsigned char)c)
			return ((void *)d);
		d++;
	}
	return (NULL);
}

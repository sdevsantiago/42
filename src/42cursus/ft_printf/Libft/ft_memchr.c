/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:52:33 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/08 14:45:51 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Scans the initial N bytes of the memory area pointed to by S for the first
   instance of C.  */
void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr = (unsigned char *)s;

	while (n--)
	{
		if (*ptr == (unsigned char)c)
			return ((void *)ptr);
		ptr++;
	}
	return (NULL);
}

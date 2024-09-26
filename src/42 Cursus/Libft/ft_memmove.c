/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:35:31 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/26 18:12:34 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies N bytes from memory area SRC to memory area DEST.
   This function is protected against overlapping.  */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*s = (unsigned char *)src + n - 1;
	unsigned char		*d;

	if (!(dest > src && dest < src + n))
		return (ft_memcpy(dest, src, n));
	d = (unsigned char *)dest + n - 1;
	while (n--)
		*d-- = *s--;
	return (dest);
}

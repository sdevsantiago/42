/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 14:35:31 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/08 14:48:54 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies N bytes from memory area SRC to memory area DEST.
   This function is protected against overlapping.  */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_ptr = (unsigned char *)src + n - 1;
	unsigned char		*dest_ptr;

	if (!(dest > src && dest < src + n))
		return (ft_memcpy(dest, src, n));
	dest_ptr = (unsigned char *)dest + n - 1;
	while (n--)
		*dest_ptr-- = *src_ptr--;
	return (dest);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 01:56:30 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/08 20:25:34 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies N bytes from memory area SRC to memory area DEST.  */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_ptr = (unsigned char *)src;
	unsigned char		*dest_ptr;

	if (!dest && !src)
		return (NULL);
	dest_ptr = (unsigned char *)dest;
	while (n--)
		*dest_ptr++ = *src_ptr++;
	return (dest);
}

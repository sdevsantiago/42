/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:59:02 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/27 19:34:40 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Appends the NUL-terminated string SRC to the end of DST.  */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	d;
	size_t	s;

	d = 0;
	while (dst && dst[d] && d < size)
		d++;
	s = ft_strlen(src);
	if (size <= d)
		return (size + s);
	size -= d;
	dst += d;
	while (size-- > 1 && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (d + s);
}

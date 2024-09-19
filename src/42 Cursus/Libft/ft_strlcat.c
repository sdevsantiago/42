/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:59:02 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/19 14:05:08 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Concatenates a size-bounded string.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	i = ft_strlen(dst);
	s = ft_strlen(src);
	if (size <= i)
		return (size + s);
	size -= i;
	dst += i;
	while (size-- > 1)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (i + s);
}

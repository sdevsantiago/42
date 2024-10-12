/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 13:42:36 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/29 14:32:51 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Copies N characters of SRC in DEST. If N is bigger than SRC's length, the
   remaining N positions of DEST are filled with NULL.  */
char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (*src && n > 0)
	{
		dest[i++] = *src++;
		n--;
	}
	while (n > 0)
	{
		dest[i++] = '\0';
		n--;
	}
	return (dest);
}

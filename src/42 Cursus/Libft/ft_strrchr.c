/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:34:38 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/26 21:01:18 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Finds the last ocurrence of C in the string S.  */
char	*ft_strrchr(const char *s, int c)
{
	short	l;

	l = ft_strlen(s);
	s += l;
	if (*s == '\0' && c == '\0')
		return ((char *)s);
	while (l-- >= 0)
	{
		if (*s == c)
			return ((char *)s);
		s--;
	}
	return (NULL);
}

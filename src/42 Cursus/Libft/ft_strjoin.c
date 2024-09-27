/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:16:44 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/27 20:19:57 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Appends the NULL-terminated string S1 and the NULL-terminated string S2
   in a new string.  */
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*j;
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	j = (char *)malloc(sizeof (*j) * (l1 + l2 + 1));
	if ((j == NULL) || (!s1 || !s2))
		return (NULL);
	ft_strlcpy(j, s1, l1 + 1);
	ft_strlcpy(&j[l1], s2, l2 + 1);
	return (j);
}

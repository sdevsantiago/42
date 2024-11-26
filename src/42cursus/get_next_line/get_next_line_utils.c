/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:54 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/19 18:07:10 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Measures a string's length.  */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/* Copies a size-bounded string.  */
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return (ft_strlen(src));
	i = 0;
	while (src[i] && i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}

/* Appends the NULL-terminated string S1 and the NULL-terminated string S2
   in a new string.  */
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = (char *)malloc(sizeof (*joined) * (s1_len + s2_len + 1));
	if (!joined)
		return (NULL);
	ft_strlcpy(joined, s1, s1_len + 1);
	ft_strlcpy(&joined[s1_len], s2, s2_len + 1);
	return (joined);
}

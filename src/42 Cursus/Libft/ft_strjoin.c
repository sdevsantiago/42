/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:16:44 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/08 19:41:42 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

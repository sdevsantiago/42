/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:27:39 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/29 16:06:24 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Erases any character from SET to the right and to the left of the
   string S1.  */
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	f;
	size_t	l;

	if (!s1 || !set)
		return (NULL);
	f = 0;
	l = ft_strlen(s1) - 1;
	while (s1[f] && ft_strchr(set, s1[f]))
		f++;
	while (s1[l] && ft_strchr(set, s1[l]))
		l--;
	return (ft_substr(s1, f, l - f + 1));
}

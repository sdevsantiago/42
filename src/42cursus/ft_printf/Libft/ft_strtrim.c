/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:27:39 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/08 20:52:18 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Erases any character from SET to the right and to the left of the
   string S1.  */
char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	first;
	size_t	last;

	if (!s1 || !set)
		return (NULL);
	first = 0;
	last = ft_strlen(s1) - 1;
	while (s1[first] && ft_strchr(set, s1[first]))
		first++;
	while (s1[last] && ft_strchr(set, s1[last]))
		last--;
	return (ft_substr(s1, first, last - first + 1));
}

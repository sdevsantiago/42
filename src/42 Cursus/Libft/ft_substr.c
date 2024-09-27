/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:19:18 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/27 10:33:41 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Creates a copy of the string S from the index START of LEN characters.  */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*c;
	size_t	i;

	c = malloc(sizeof (*c) * len + 1);
	if (c == NULL)
		return (NULL);
	s += start;
	i = 0;
	while (len-- && *s)
		c[i++] = *s++;
	c[i] = '\0';
	return (c);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:19:18 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/08 15:09:46 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Creates a copy of the string S from the index START of LEN characters.  */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (!s)
		return (NULL);
	substr = malloc(sizeof (*substr) * len);
	if (substr == NULL)
		return (NULL);
	s += start;
	i = 0;
	while (len-- && *s)
		substr[i++] = *s++;
	substr[i] = '\0';
	return (substr);
}

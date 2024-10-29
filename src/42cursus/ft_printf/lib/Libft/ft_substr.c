/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 09:19:18 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/11 19:19:02 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Creates a NULL-terminating copy of the string S from the index START
   of LEN characters.  */
char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start > s_len)
	{
		start = s_len;
		len = 0;
	}
	if (len > s_len - start)
		len = s_len - start;
	substr = malloc((sizeof (*substr) * len) + 1);
	if (!substr)
		return (NULL);
	s += start;
	i = 0;
	while (len-- && *s && i < s_len)
		substr[i++] = *s++;
	substr[i] = '\0';
	return (substr);
}

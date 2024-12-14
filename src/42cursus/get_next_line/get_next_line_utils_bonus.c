/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:54 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/14 14:30:54 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Measures a string's length.  */
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

/*	Duplicates a string.  */
char	*ft_strdup(const char *s)
{
	char	*s_dup;
	int		i;

	s_dup = (char *)malloc(ft_strlen(s) + 1);
	if (!s_dup)
		return (NULL);
	i = 0;
	while (s[i])
	{
		s_dup[i] = s[i];
		i++;
	}
	s_dup[i] = '\0';
	return (s_dup);
}

/* Appends the NULL-terminated string S1 and the NULL-terminated string S2
   in a new string.  */
char	*ft_strjoin(char *s1, const char *s2)
{
	char	*joined;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	joined = (char *)malloc(sizeof (*joined) * (s1_len + s2_len + 1));
	if (!joined)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		joined[j++] = s1[i++];
	i = 0;
	while (s2[i])
		joined[j++] = s2[i++];
	joined[j] = '\0';
	free((void *)s1);
	return (joined);
}

/* Finds the first ocurrence of C in the string S.  */
char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}

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

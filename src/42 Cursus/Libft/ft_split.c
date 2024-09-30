/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:57:37 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/30 19:17:04 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the words in the string S using C as separator.  */
static size_t	count_words(const char *s, char c)
{
	size_t	w;

	if (!s || !c)
		return ((size_t) NULL);
	w = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		w++;
		while (*s != c && *s)
			s++;
	}
	return (w);
}

/* Frees the last R rows, from the M matrix.  */
static void	free_matrix(void **m, size_t r)
{
	if (m && r)
	{
		while (r--)
			free(m[r]);
		free(m);
	}
}

/* Allocates memory for the next row.  */
static char	*calloc_row(char *s, char c)
{
	char	*r;

	if (!ft_strchr(s, c))
		r = ft_calloc(ft_strlen(s) + 1, sizeof(*r));
	else
		r = ft_calloc((ft_strchr(s, c) - s) + 1, sizeof(*r));
	return (r);
}

char	**ft_split(const char *s, char c)
{
	char	**m;
	size_t	r;

	m = ft_calloc(count_words(s, c) + 1, sizeof(*m));
	if (!s || !c || !m)
		return (NULL);
	while (*s && *s == c)
		s++;
	r = 0;
	if (!*s)
		*m = NULL;
	while (*s)
	{
		m[r] = calloc_row((char *)s, c);
		if (!m[r])
			return (free_matrix((void **)m, r), NULL);
		ft_strlcpy(m[r], s, ft_strchr(s, c) - s + 1);
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		r++;
	}
	return (m);
}

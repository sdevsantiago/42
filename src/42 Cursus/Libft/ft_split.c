/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:57:37 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/29 22:37:14 by sede-san         ###   ########.fr       */
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

char	**ft_split(const char *s, char c)
{
	char	**m;
	size_t	r;

	m = ft_calloc(count_words(s, c), sizeof(*m));
	if (!s || !c || !m)
		return (NULL);
	while (*s && *s == c)
		s++;
	r = 0;
	while (*s)
	{
		if (!ft_strchr(s, c))
			m[r] = ft_calloc(ft_strlen(s) + 1, sizeof(**m));
		else
			m[r] = ft_calloc((ft_strchr(s, c) - s) + 1, sizeof(**m));
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

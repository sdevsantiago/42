/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:57:37 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/08 14:58:57 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the words in the string S using C as separator.  */
static size_t	count_words(const char *s, char c)
{
	size_t	words;

	if (!s || !c)
		return ((size_t) NULL);
	words = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		words++;
		while (*s != c && *s)
			s++;
	}
	return (words);
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
	char	*row;

	if (!ft_strchr(s, c))
		row = ft_calloc(ft_strlen(s) + 1, sizeof(*row));
	else
		row = ft_calloc((ft_strchr(s, c) - s) + 1, sizeof(*row));
	return (row);
}

/* Splits the string S using C as separator.  */
char	**ft_split(const char *s, char c)
{
	char	**s_split;
	size_t	row;

	s_split = ft_calloc(count_words(s, c) + 1, sizeof(*s_split));
	if (!s || !c || !s_split)
		return (NULL);
	s += (long)ft_strchr(s, c);
	row = 0;
	if (!*s)
		*s_split = NULL;
	while (*s)
	{
		s_split[row] = calloc_row((char *)s, c);
		if (!s_split[row])
			return (free_matrix((void **)s_split, row), NULL);
		ft_strlcpy(s_split[row], s, ft_strchr(s, c) - s + 1);
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		row++;
	}
	return (s_split);
}

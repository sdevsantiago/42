/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:57:37 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/11 20:34:20 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the words in the string S using C as separator.  */
static size_t	count_words(const char *s, char c)
{
	size_t	words;

	if (!s)
		return ((size_t) NULL);
	words = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
			words++;
		while (*s != c && *s)
			s++;
	}
	return (words);
}

/* Frees an allocated matrix.  */
static void	free_matrix(void **matrix)
{
	size_t	row;

	row = 0;
	while (matrix[row])
	{
		free(matrix[row]);
		row++;
	}
	free(matrix);
}

/* Splits the string S using C as separator.  */
char	**ft_split(const char *s, char c)
{
	char	**s_split;
	size_t	row;
	size_t	len;

	if (!s)
		return (NULL);
	s_split = (char **)malloc((count_words(s, c) + 1) * sizeof(*s_split));
	if (!s_split)
		return (NULL);
	row = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		len = 0;
		while (s[len] != c && s[len])
			len++;
		if (len)
			s_split[row] = ft_substr(s, 0, len);
		if (len && !s_split[row++])
			return (free_matrix((void **)s_split), NULL);
		s += len;
	}
	s_split[row] = NULL;
	return (s_split);
}

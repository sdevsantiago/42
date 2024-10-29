/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:33:49 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/08 14:59:44 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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

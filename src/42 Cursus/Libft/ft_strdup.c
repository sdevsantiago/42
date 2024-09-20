/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 20:33:49 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/20 19:39:29 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*	Duplicates a string.  */
char	*ft_strdup(const char *s)
{
	int		i;
	char	*d;

	d = (char *)malloc(ft_strlen(s) + 1);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	return (d);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 07:39:01 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/16 11:31:51 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
	Duplicates a string.
	- #### Parameters
	-	char *src: The string to duplicate
*/
char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	str = malloc(sizeof(src));
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

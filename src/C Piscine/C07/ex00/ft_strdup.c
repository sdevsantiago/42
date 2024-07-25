/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 07:39:01 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/25 12:07:50 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
	Measures a strings length.
	- #### Parameter
	-	char *str: The string to measure.
	- #### Return
	-	Returns the length of the passed string.
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
	Duplicates a string.
	- #### Parameters
	-	char *src: The string to duplicate
*/
char	*ft_strdup(char *src)
{
	char	*str;
	int		i;

	str = (char *)malloc(ft_strlen(src) + 1);
	i = 0;
	while (src[i] != '\0')
	{
		str[i] = src[i];
		i++;
	}
	return (str);
}

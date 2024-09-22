/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:23:12 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/22 21:12:21 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Finds the substring LITTLE in LEN characters of the string BIG.  */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!(*little))
		return ((char *)big);
	while (big[i] != '\0' && len--)
	{
		while ((big[i] == little[j]) && (big[i] || little[j]))
		{
			i++;
			j++;
		}
		if (!(little[j]))
			return ((char *)big);
		big++;
		i = 0;
		j = 0;
	}
	return (0);
}

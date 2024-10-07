/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:23:12 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/07 19:42:25 by sede-san         ###   ########.fr       */
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
	while (big[i] && len-- + 1)
	{
		while ((big[i] == little[j]) && (big[i] || little[j]) && len-- + 1)
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
	return (NULL);
}

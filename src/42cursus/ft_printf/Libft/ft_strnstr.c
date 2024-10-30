/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 18:23:12 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/09 20:25:54 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!(*little))
		return ((char *)big);
	while (*big && len)
	{
		i = 0;
		j = 0;
		while (big[i] == little[j] && big[i] && little[j] && len)
		{
			i++;
			j++;
			len--;
		}
		len += j;
		if (!little[j])
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}

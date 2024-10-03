/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:22:42 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/03 21:32:25 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Compares the first n bytes of the memory areas s1 and s2.  */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*d1 = s1;
	const unsigned char	*d2 = s2;
	size_t				i;

	if (!s1 || !s2 || n == 0)
		return (0);
	i = 0;
	while (i < n && d1[i] == d2[i] && (d1[i] && d2[i]))
		i++;
	if (i == n || !d1[i] || !d2[i])
		i--;
	return (d1[i] - d2[i]);
}

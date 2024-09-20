/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:34:03 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/20 19:39:22 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Fills the first n bytes of s with c.  */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*d;
	size_t	i;

	d = s;
	i = 0;
	while (i < n)
	{
		d[i] = c;
		i++;
	}
	s = d;
}

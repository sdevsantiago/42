/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 19:34:03 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/08 14:49:58 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Fills the first N bytes of S with C.  */
void	*ft_memset(void *s, int c, size_t n)
{
	char	*s_ptr;
	size_t	i;

	s_ptr = s;
	i = 0;
	while (i < n)
	{
		s_ptr[i] = c;
		i++;
	}
	return (s);
}

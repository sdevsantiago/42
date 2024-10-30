/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:44:16 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/08 15:07:09 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Applies the function F to each character of the string S.
   The passed string is not modified, all changes are applied to a copy.  */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str_mapped;
	size_t	i;

	str_mapped = ft_strdup(s);
	if (!s || !f || !str_mapped)
		return (NULL);
	i = 0;
	while (str_mapped[i])
	{
		str_mapped[i] = f(i, str_mapped[i]);
		i++;
	}
	return (str_mapped);
}

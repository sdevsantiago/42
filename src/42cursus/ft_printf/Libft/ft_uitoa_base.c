/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:31:15 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/14 19:38:43 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of digits in the unsigned integer N with the base.  */
static size_t	count_digits(unsigned int n, size_t base_len)
{
	size_t	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n != 0)
	{
		n /= base_len;
		digits++;
	}
	return (digits);
}

/* Converts an unsigned integer into a specific base in form of a string.  */
char	*ft_uitoa_base(unsigned int n, const char *base)
{
	const size_t	base_len = ft_strlen(base);
	char			*num_str;
	size_t			digits;

	digits = count_digits(n, base_len);
	num_str = (char *)malloc((digits + 1) * sizeof(char));
	if (!num_str)
		return (NULL);
	num_str[digits] = '\0';
	while (digits-- > 0)
	{
		num_str[digits] = base[n % base_len];
		n /= base_len;
	}
	return (num_str);
}

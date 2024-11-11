/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 18:13:02 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/11 19:58:38 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of digits in the integer N with the base.  */
static size_t	count_digits(int n, int base_len)
{
	size_t	digits;

	if (n == 0)
		return (1);
	else if (n == INT_MIN)
		n = -n;
	digits = 0;
	while (n != 0)
	{
		n /= base_len;
		digits++;
	}
	return (digits);
}

/* Converts an integer into a specific base in form of a string.  */
char	*ft_itoa_base(int n, const char *base)
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

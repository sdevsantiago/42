/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:42:59 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/05 16:55:45 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of digits in the unsigned integer N.  */
static size_t	count_digits(unsigned int n)
{
	size_t	digits;

	if (n == 0)
		return (1);
	digits = 0;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

/* Converts an unsigned integer into a string.  */
char	*ft_uitoa(unsigned int n)
{
	char	*num_str;
	size_t	digits;

	digits = count_digits(n);
	num_str = (char *)malloc((digits + 1) * sizeof(*num_str));
	if (!num_str)
		return (NULL);
	num_str[digits] = '\0';
	while (digits-- > 0)
	{
		num_str[digits] = (n % 10) + '0';
		n /= 10;
	}
	return (num_str);
}

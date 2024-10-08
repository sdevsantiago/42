/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:09:37 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/08 14:52:01 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of digits in the integer N.  */
static size_t	count_digits(int n)
{
	size_t	digits;

	digits = 0;
	if (n == INT_MIN)
		return (10);
	else if (n == 0)
		return (1);
	else if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		digits++;
	}
	return (digits);
}

/* Converts an integer into a string.  */
char	*ft_itoa(int n)
{
	char	*num_str;
	size_t	digits;

	digits = count_digits(n);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	else if (n < 0)
		return (ft_strjoin("-", ft_itoa(-n)));
	num_str = ft_calloc(digits + 1, sizeof(*num_str));
	if (!num_str)
		return (NULL);
	while (digits-- > 0)
	{
		num_str[digits] = (n % 10) + '0';
		n /= 10;
	}
	return (num_str);
}

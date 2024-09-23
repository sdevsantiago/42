/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 09:09:37 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/23 19:43:07 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Counts the number of digits in the integer N.  */
size_t	count_digits(int n)
{
	size_t	d;

	d = 0;
	if (n == INT_MIN)
		return (10);
	else if (n == 0)
		return (1);
	else if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= 10;
		d++;
	}
	return (d);
}

/* Converts an integer into a string.  */
char	*ft_itoa(int n)
{
	char	*s;
	size_t	d;

	d = count_digits(n);
	s = ft_calloc(d, sizeof(*s));
	if (n == INT_MIN)
		return ("-2147483648");
	else if (n == 0)
		return ("0");
	else if (n < 0)
	{
		n = -n;
		s[0] = '-';
	}
	while (d-- > 0)
	{
		s[d] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}

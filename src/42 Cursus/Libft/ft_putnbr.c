/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/30 20:07:17 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/30 20:14:26 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Prints the number N.  */
void	ft_putnbr(int n)
{
	char	d;

	if (n == INT_MIN)
		write(STDOUT_FILENO, "-2147483648", 11);
	else if (n == 0)
		write(STDOUT_FILENO, "0", 1);
	else if (n < 0)
	{
		ft_putchar('-');
		ft_putnbr(-n);
	}
	else
	{
		d = n % 10 + '0';
		n /= 10;
		if (n > 0)
			ft_putnbr(n);
		ft_putchar(d);
	}
}

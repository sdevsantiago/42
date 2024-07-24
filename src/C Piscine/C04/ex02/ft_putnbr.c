/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:09:23 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/24 02:44:31 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	Prints a character.
	- #### Parameters
	-	char c: The character to print
*/
void	ft_putchar(char c)
{
	write(STDOUT_FILENO, &c, 1);
}

/*
	Prints a number.
	- #### Parameters
	-	int nb: The number to print
*/
void	ft_putnbr(int nb)
{
	int	n;

	if (nb == -2147483648)
		write(STDOUT_FILENO, "-2147483648", 11);
	else if (nb == 0)
		write(STDOUT_FILENO, "0", 1);
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		n = nb % 10 + '0';
		nb /= 10;
		if (nb > 0)
			ft_putnbr(nb);
		ft_putchar(n);
	}
}

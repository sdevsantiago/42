/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:30:57 by sede-sant         #+#    #+#             */
/*   Updated: 2024/07/07 16:43:13 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*	
	Prints a character.
	- ### Parameters ###
	-	 char c: The character to print
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

/*
	Prints the numbers from ft_print_comb2 in the specified format.
	### Parameters ###
	- int a: The first number
	- int b: The second number
*/
void	ft_printnum(int a, int b)
{
	ft_putchar(a / 10 + '0');
	ft_putchar(a % 10 + '0');
	ft_putchar(' ');
	ft_putchar(b / 10 + '0');
	ft_putchar(b % 10 + '0');
	if (a != 98)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

/*
	Prints the sequence of numbers from 00 01 to 98 99, ensuring no number is
	ever repeated, no matter the position.
*/
void	ft_print_comb2(void)
{
	int	a;
	int	b;

	a = 0;
	while (a <= 98)
	{
		b = a + 1;
		while (b <= 99)
		{
			ft_printnum(a, b);
			b++;
		}
		a++;
	}
}

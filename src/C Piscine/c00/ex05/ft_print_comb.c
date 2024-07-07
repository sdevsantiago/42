/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:34:52 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/07 16:42:50 by sede-san         ###   ########.fr       */
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
	write(1, &c, 1);
}

/*
	
*/
void	ft_printnum(char digit1, char digit2, char digit3)
{
	ft_putchar(digit1 + '0');
	ft_putchar(digit2 + '0');
	ft_putchar(digit3 + '0');
	if (digit1 != 7)
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

/*
	Prints from 012 to 789 ensuring no number is repeated even though it's in
	any other position.
*/
void	ft_print_comb(void)
{
	int	digit1;
	int	digit2;
	int	digit3;

	digit1 = 0;
	while (digit1 <= 7)
	{
		digit2 = digit1 + 1;
		while (digit2 <= 8)
		{
			digit3 = digit2 + 1;
			while (digit3 <= 9)
			{
				ft_printnum(digit1, digit2, digit3);
				digit3++;
			}
			digit2++;
		}
		digit1++;
	}
}

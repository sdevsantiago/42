/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:34:52 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/03 22:32:48 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	print_num(char digit1, char digit2, char digit3)
{
	put_char(digit1 + '0');
	put_char(digit2 + '0');
	put_char(digit3 + '0');
	if (digit1 != 7)
	{
		putChar(',');
		putChar(' ');
	}
}

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
				print_num(digit1, digit2, digit3);
				digit3++;
			}
			digit2++;
		}
		digit1++;
	}
}

// int main(void)
// {
// 	ft_print_comb();
// 	return 0;
// }

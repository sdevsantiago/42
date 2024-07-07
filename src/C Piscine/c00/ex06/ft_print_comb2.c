/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:30:57 by sede-sant         #+#    #+#             */
/*   Updated: 2024/07/07 12:11:26 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	put_char(char c)
{
	write(1, &c, 1);
}

void	print_num(int a, int b)
{
	put_char(a / 10 + '0');
	put_char(a % 10 + '0');
	put_char(' ');
	put_char(b / 10 + '0');
	put_char(b % 10 + '0');
	if (a != 98)
	{
		put_char(',');
		put_char(' ');
	}
}

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
			print_num(a, b);
			b++;
		}
		a++;
	}
}

// int	main(void)
// {
// 	ft_print_comb2();
// 	return (0);
// }

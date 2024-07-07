/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 22:45:00 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/07 16:18:40 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//TODO Solucionar caso de prueba -2147483648

#include <unistd.h>
#include <stdlib.h>

void	ft_putchar(char a)
{
	write(1, &a, 1);
}

void	ft_putnbr(int nb)
{
	int	num[10];
	int	i;

	i = 0;
	if (nb < 0)
	{
		ft_putchar('-');
		nb = nb * -1;
	}
	else if (nb == 0)
		ft_putchar('0');
	else if (nb == -2147483648)
		write(1, "-2147483648", 11);
	while (nb > 0)
	{
		num[i] = nb % 10;
		nb /= 10;
		i++;
	}
	while (--i >= 0)
		ft_putchar(num[i] + '0');
}

int	main(int argc, char const *argv[])
{
	char	newline = '\n';
	
	for (int i = 0; i < argc; i++)
	{
		ft_putnbr(atoi(argv[i]));
		write(1, &newline, 1);
	}
	return (0);
}

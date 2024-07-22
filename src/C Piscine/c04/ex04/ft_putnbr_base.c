/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/21 21:43:32 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/22 18:06:52 by sede-san         ###   ########.fr       */
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
	Measures a strings length.
	- #### Parameter
	-	char *str: The string to measure.
	- #### Return
	-	Returns the length of the passed string.
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

/*
	Checks if the base passed in ft_putnbr_base is valid or not.
	- #### Parameters
	-	char *base: The base to check
	- #### Return
	-	Returns 0 if the base is valid.
	-	Returns 1 if the base is empty or it's size is 1.
	-	Returns 2 if the base contains '+' and/or '-'.
	-	Returns 3 if the base contains the same character at least twice
*/
unsigned int	ft_check_putnbr_base(char *base)
{
	unsigned int	i;
	unsigned int	j;

	if (ft_strlen(base) <= 1)
		return (1);
	i = 0;
	while (base[i++])
	{
		if (base[i] == '+' || base[i] == '-')
			return (2);
		j = 0;
		while (j < i)
		{
			if (base[i] == base[j])
				return (3);
			j++;
		}
	}
	return (0);
}

/*
	Prints a number converted into the passed base.
	- #### Special cases
	-	If the base is empty or it's size is 1, contains the same character at
		least twice or contains '+' and/or '-', nothing will be printed.
	- #### Parameters
	-	int nbr: The number to be converted
	-	char *base: The base to convert the number to
*/

void	ft_putnbr_base(int nbr, char *base)
{
	int	base_characters;
	int	n;
	
	if (ft_check_putnbr_base(base))
		return ;
	base_characters = ft_strlen(base);
	if (nbr < 0)
		ft_putchar('-');
	n = nbr % base_characters;
	nbr /= base_characters;
	if (nbr > 0)
		ft_putnbr_base(nbr, base);
	ft_putchar(base[n]);
}

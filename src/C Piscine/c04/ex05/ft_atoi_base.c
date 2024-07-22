/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 20:04:53 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/22 22:34:13 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
unsigned int	ft_check_atoi_base(char *base)
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
	Checks if the character is a white-space.
	- #### Parameters
	-	char c: The character to check
	- #### Return
	-	Returns 1 if the character is a white-space, else returns 0.
*/
int	ft_isspace(char c)
{
	const char	horizontal_tab = '\t';
	const char	carriage_return = '\r';
	const char	space = ' ';

	if ((c >= horizontal_tab && c <= carriage_return) || c == space)
		return (1);
	return (0);
}

/*
	Checks if the character read is a valid character contained in 'base'.
	- #### Parameters
	-	char c: The character to evaluate
	-	char *base: The base to read from
	- #### Return
	-	Returns the total length of base if the character is not in the list,
		else returns the index where found.
*/
int	ft_is_char_base(char c, char *base)
{
	int	i;

	i = 0;
	while (c != *base++)
		i++;
	return (i);
}

/*
	Converts a base into an integer. The string can start with an undefined
	number of spaces and can be followed by an arbitrary number of plus (+) and
	minus (-) signs. The minus sign will turn the integer into negative.
	- #### Parameters
	-	char *str: The value to convert
	-	char *base: The base
	- #### Return
	-	r
*/
int	ft_atoi_base(char *str, char *base)
{
	int	minus;
	int	n;
	int	base_characters;

	while (ft_isspace(*str))
		str++;
	minus = 1;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	n = 0;
	base_characters = ft_strlen(base);
	while (ft_is_char_base(*str, base))
	{
		n = 
		str++;
	}
	return (n * minus);
}

//! TEST TEST TEST

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
		nb = -nb;
	}
	n = nb % 10 + '0';
	nb /= 10;
	if (nb > 0)
		ft_putnbr(nb);
	ft_putchar(n);
}

#include <stdio.h>
int main(void)
{
	printf("%d\n", ft_atoi_base("-1101", "01"));
	return 0;
}

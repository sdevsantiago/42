/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 21:15:32 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/15 21:17:08 by sede-san         ###   ########.fr       */
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
	Gets the length of a string.
	- #### Parameters
	-	char *str: The string to measure.
	- #### Return
	-	Returns the length of the string up to the first NULL (\0) terminator.
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
	Prints a string.
	- #### Parameters
	-	char *str: The string to print
*/
void	ft_putstr(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}

/*
	Prints the parameters used in reverse.
*/
int	main(int argc, char *argv[])
{
	const char	newline = '\n';
	int			i;

	i = argc - 1;
	while (i > 0)
	{
		ft_putstr(argv[i]);
		ft_putchar(newline);
		i--;
	}
	return (0);
}

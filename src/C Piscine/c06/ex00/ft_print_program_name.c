/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 17:05:44 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/15 20:19:44 by sede-san         ###   ########.fr       */
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
	Prints the program name.
*/
int	main(int argc, char *argv[])
{
	const char	newline = '\n';
	int			nargs = argc - 1;

	ft_putstr(argv[argc - nargs - 1]);
	ft_putchar(newline);
	return (0);
}

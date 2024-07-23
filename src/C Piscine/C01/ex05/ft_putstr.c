/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 13:01:25 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/18 20:48:05 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

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

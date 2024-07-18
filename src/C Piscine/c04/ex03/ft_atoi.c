/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:29:21 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/17 17:03:49 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	Converts a string into an integer. The string can start with an undefined
	number of spaces and can be followed by an arbitrary number of plus (+) and
	minus (-) signs. The minus sign will turn the integer into negative.
	- #### Parameters
	-	char *str: The string containing the number
	- #### Return
	-	Returns the integer value of the number found.
*/
int	ft_atoi(char *str)
{
	int				minus;
	int				n;

	minus = 1;
	n = 0;
	while (ft_isspace(*str))
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			minus = -minus;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		n = n * 10 + (*str - '0');
		str++;
	}
	return (n * minus);
}

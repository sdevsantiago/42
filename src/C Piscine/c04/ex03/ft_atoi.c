/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 19:29:21 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/10 20:04:09 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Converts the beggining of a string into an integer type. The string can
	start with an undefined number of spaces and can be followed by an 
	arbitrary number of plus (+) and minus (-) signs. The minus sign will turn
	the integer into negative.
	- #### Parameters
	-	char *str: The string containing the number
	- #### Return
	-	Returns the integer value of the number found.
*/
int	ft_atoi(char *str)
{
	unsigned int	i;
	int				minus;
	int				n;

	i = 0;
	minus = 1;
	n = 0;
	while (str[i] < '0')
	{
		if (str[i] == '-')
			minus = -minus;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n * minus);
}

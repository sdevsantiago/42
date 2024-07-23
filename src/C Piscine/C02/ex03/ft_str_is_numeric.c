/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:16:45 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/08 17:24:32 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Checks if a string contains only numeric characters.
	- #### Parameters
	-	char *str: The string to check
	- #### Return
	-	Returns 1 if the string contains only numeric characters of if the
		string passed is empty, if not, returns 0.
*/
int	ft_str_is_numeric(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

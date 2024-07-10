/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 16:59:26 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/10 17:04:36 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Counts the number of characters of a string.
	- #### Parameters
	-	char *str: The string to count the characters from
	- #### Return
	-	The number of characters of the string passed.
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

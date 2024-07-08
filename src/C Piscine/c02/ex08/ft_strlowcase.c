/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:35:50 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/09 00:00:51 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	Turns any uppercase character from a string into an lowercase character.
	- #### Parameters
	-	char *str: The string to transform
	- #### Return
	- The string passed.
*/
char	*ft_strlowcase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		i++;
	}
	return (str);
}

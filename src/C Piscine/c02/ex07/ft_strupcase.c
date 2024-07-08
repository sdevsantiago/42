/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 19:29:00 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/08 19:37:35 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	Turns any lowercase character from a string into an uppercase character.
	- #### Parameters
	-	char *str: The string to transform
	- #### Return
	- The string passed.
*/
char	*ft_strupcase(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
	return (str);
}

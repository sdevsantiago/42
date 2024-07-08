/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:48:45 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/08 17:11:46 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Checks if the string passed contains only alphabetic characters.
	- #### Parameters
	-	char *str: The string to evaluate
	- #### Return
	-	Returns 1 if the string contains only alphabetic characters or if the
		string passed is empty, if not, returns 0.
*/
int	ft_str_is_alpha(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 'A' || str[i] > 'Z' && str[i] < 'a' || str[i] > 'z')
			return (0);
		i++;
	}
	return (1);
}

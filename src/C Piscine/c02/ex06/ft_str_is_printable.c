/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:47:33 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/08 19:26:36 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
	Checks if the string passed contains only printable characters.
	- #### Parameters
	-	char *str: The string to evaluate
	- #### Return
	-	Returns 1 if the string contains only printable characters or if the
		string passed is empty, if not, returns 0.
*/
int	ft_str_is_printable(char *str)
{
	const char		space = 32;
	const char		tilde = 126;
	unsigned int	i;

	i = 0;
	while (str[i] < space || str[i] > tilde)
	{
		if (str[i] < space || str[i] > tilde)
			return (0);
		i++;
	}
	return (1);
}

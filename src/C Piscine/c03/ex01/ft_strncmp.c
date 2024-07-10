/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:21:30 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/10 08:49:40 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Compares two strings up to the n character.
	- #### Parameters
	-	char *s1: The first string
	-	char *s2: The other string
	-	unsigned int n: The character up to where compare
	- #### Return
	-	Returns 0 if both strings are equal, a negative value if the first
		string is bigger than the second and a char
*/
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && n > 0)
	{
		i++;
		n--;
	}
	return (s2[i] - s1[i]);
}

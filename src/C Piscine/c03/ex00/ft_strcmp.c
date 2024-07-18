/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 03:18:42 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/17 16:55:03 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Compares two strings.
	- #### Parameters
	-	char *s1: The first string
	-	char *s2: The other string
	- #### Return
	-	Returns 0 if both strings are equal, a positive value if the first
		string is bigger than the second and a negative value if the second
		string is bigger than the first.
*/
int	ft_strcmp(char *s1, char *s2)
{
	unsigned int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
		i++;
	return (s1[i] - s2[i]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:21:30 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/16 07:21:20 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Compares two strings up to the n character.
	- #### Parameters
	-	char *s1: The first string
	-	char *s2: The other string
	-	unsigned int n: The character up to where compare
	- #### Return
	-	Returns 0 if both strings are equal or if n equals 0, a positive value
		if the first string is bigger than the second and a negative value if
		the second string is bigger than the first.
*/
int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && (s1[i] != '\0' && s2[i] != '\0') && n > 0)
	{
		i++;
		n--;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	*s1 = "\201";
	char	*s2 = "\101";
	printf("Original strncmp:\t%d\n", strncmp(s1, s2, 2));
	printf("My strncmp:\t\t%d\n", ft_strncmp(s1, s2, 2));
	return (0);
}

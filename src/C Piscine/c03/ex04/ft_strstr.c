/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:43:43 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/10 13:19:01 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Measures a strings length.
	- #### Parameter
	-	char *str: The string to measure.
	- #### Return
	-	Returns the length of the passed string.
*/
int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

/*
	Locates a subtring in a string.
	-	char *str: The string in where to search
	-	char *to_find: The substring to search in 'str'
	- #### Return
	-	If found, returns the substring, if not, returns NULL.
*/
char	*ft_strstr(char *str, char *to_find)
{
	char		*null = "\0";
	unsigned int	i;
	unsigned int	j;
	unsigned int	tofind_len;

	i = 0;
	tofind_len = ft_strlen(to_find);
	while (str[i] != '\0')
	{
		while (str[i] == to_find[j])
		{
			i++;
			j++;
			if (j == tofind_len)
				return (to_find);
		}
		j = 0;
		i++;
	}
	return (null);
}

#include <unistd.h>
int main(void)
{
	char	*str = "Hola ";
	char	*to_find = " ";	
	ft_strstr(str, to_find);
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:43:43 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/18 16:29:57 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Locates a subtring in a string.
	- #### Special cases
	-	If an empty string is passed as 'to_find', the return value will be the
		passed string
	- #### Parameters
	-	char *str: The string in where to search
	-	char *to_find: The substring to search in 'str'
	- #### Return
	-	If found, returns the string starting from the first ocurrence of
		'to_find', else returns NULL.
*/
char	*ft_strstr(char *str, char *to_find)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!(*to_find))
		return (str);
	while (str[i] != '\0')
	{
		while (str[i] == to_find[j] && (str[i] || to_find[j]))
		{
			i++;
			j++;
		}
		if (!(to_find[j]))
			return (str);
		str++;
		i = 0;
		j = 0;
	}
	return (0);
}

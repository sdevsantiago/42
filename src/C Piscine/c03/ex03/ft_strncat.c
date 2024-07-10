/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 09:14:33 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/10 09:41:13 by sede-san         ###   ########.fr       */
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
	Concatenate two strings, appending 'dest' to 'src', up to the character 'nb'.
	- #### Parameters
	-	char *dest: String to concatenate to
	-	char *src: String to concatenate from
	-	unsigned int nb: The caracter up to where concatenate in 'src'
	- #### Return
	-	Returns the concatenated string.
*/
char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	i;
	unsigned int	j;

	i = ft_strlen(dest);
	j = 0;
	while (src[j] != '\0' && nb > 0)
	{
		dest[i] = src[j];
		i++;
		j++;
		nb--;
	}
	dest[i] = '\0';
	return (dest);
}

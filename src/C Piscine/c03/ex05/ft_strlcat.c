/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:41:32 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/18 20:52:38 by sede-san         ###   ########.fr       */
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
	Appends the first 'nb' characters of 'src' to 'dest'.
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

/*
	Copies a size-bounded string.
	- #### Parameters
	-	char *dest: The string where to copy
	-	char *src: The string to copy
	- #### Return
	-	Returns the total length of the string created.
*/
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	ft_strncat(dest, src, size);
	return (ft_strlen(dest) + ft_strlen(src) - 1);
}

#include <bsd/string.h>
#include <stdio.h>
// TODO TEST TEST TEST
int	main(void)
{
	char			src1[] = "Adios";
	char			dest1[] = "Hola";
	char			src2[] = "Adios";
	char			dest2[] = "Hola";
	unsigned int	size = 3;
	printf("Original strlcat:\t%s\t%zu\t%s\t%s\n", dest1, strlcat(dest1, src1, size), dest1, src1);
	printf("My strlcat:\t\t%s\t%u\t%s\t%s\n", dest2, ft_strlcat(dest2, src2, size), dest2, src2);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:41:32 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/19 14:54:11 by sede-san         ###   ########.fr       */
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
	// unsigned int	i;
	//! Return value
	unsigned int	i;
	
	i = ft_strlen(dest);
	if (size <= i)
		return (size + ft_strlen(src));
	size -= i;
	dest += i;
	while (size-- > 1)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (i + size + ft_strlen(src));
}

#include <bsd/string.h>
#include <stdio.h>
#include <stdlib.h>
// TODO TEST TEST TEST
int	main(void)
{
	char dest1[] = "prueba123";
	char src1[] = "prueba3";
	char dest2[] = "prueba123";
	char src2[] = "prueba3";
	int size = 11;
	
	printf("Original strlcat:\n- Original dest:\t%s\n- Function result:\t%zu\n- New dest:\t\t%s\n- New src:\t\t%s\n", dest1, strlcat(dest1, src1, size), dest1, src1);
	printf("My strlcat:\n- Original dest:\t%s\n- Function result:\t%u\n- New dest:\t\t%s\n- New src:\t\t%s\n", dest2, ft_strlcat(dest2, src2, size), dest2, src2);
	return (0);
}

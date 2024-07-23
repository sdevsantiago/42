/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:41:32 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/21 21:15:00 by sede-san         ###   ########.fr       */
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
	Copies a size-bounded string.
	- #### Parameters
	-	char *dest: The string where to copy
	-	char *src: The string to copy
	- #### Return
	-	Returns the total length of the string created.
*/
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	s;

	i = ft_strlen(dest);
	s = ft_strlen(src);
	if (size <= i)
		return (size + s);
	size -= i;
	dest += i;
	while (size-- > 1)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (i + s);
}

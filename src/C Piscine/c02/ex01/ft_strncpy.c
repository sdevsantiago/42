/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:08:15 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/08 16:43:02 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Copies n characters of a string. If dest is bigger than src, all remaining
	are filled with '\0'.
	- #### Parameters
	-	char *dest: String to copy char
	-	char *src: String where copy
	-	unsigned int n: Number of characters to copy
	- #### Return
	-	The copied string.
*/
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 17:07:00 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/07 17:46:46 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Copies a string.
	- #### Parameters
	-	char *dest: String to copy char
	-	char *src: String where copy
*/
char	*ft_strcpy(char *dest, char *src)
{
	unsigned int	i;
	
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}

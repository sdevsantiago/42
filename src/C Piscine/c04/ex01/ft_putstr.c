/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 17:06:00 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/10 17:08:58 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	Prints each character from a string one by one.
	- #### Parameters
	-	char *str: The string to print
*/
void	ft_putstr(char *str)
{
	while(*str)
    	write (1, str++, 1);
}

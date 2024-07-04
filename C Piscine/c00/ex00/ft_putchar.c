/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:32:02 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/04 16:25:08 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*	Prints a character.
	### Parameters
	char c: The character to print
	*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

// int	main()
// {
// 	ft_putchar('A');
// 	return (0);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:18:54 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/03 21:30:08 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*	Prints 'P' if n is positive or null and 'N' if is negative.
	#### Parameters
	- int n: The number to evaluate.
*/
void	ft_is_negative(int n)
{
	if (n < 0)
		write(1, "N", 1);
	else
		write(1, "P", 1);
}

// int	main(void)
// {
	// ft_is_negative(8);
	// return (0);
// }

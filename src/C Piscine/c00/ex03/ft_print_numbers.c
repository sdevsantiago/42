/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_numbers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:10:07 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/07 16:31:37 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	Prints digits from 0 to 9.
*/
void	ft_print_numbers(void)
{
	char	*numbers;

	numbers = "0123456789";
	write(1, numbers, 10);
}

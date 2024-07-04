/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:45:19 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/03 20:51:29 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/* Prints the entire alphabet in undercase letters. */
void	ft_print_alphabet(void)
{
	char	*alphabet;

	alphabet = "abcdefghijklmnopqrstuvwxyz";
	write(1, alphabet, 26);
}

// int main()
// {
	// ft_print_alphabet();
	// return 0;
// }
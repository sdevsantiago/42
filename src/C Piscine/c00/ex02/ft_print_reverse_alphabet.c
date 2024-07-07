/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 18:45:19 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/07 16:31:30 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
	Prints the entire alphabet in reverse in undercase letters.
*/
void	ft_print_reverse_alphabet(void)
{
	char	*rev_alphabet;

	rev_alphabet = "zyxwvutsrqponmlkjihgfedcba";
	write(1, rev_alphabet, 26);
}

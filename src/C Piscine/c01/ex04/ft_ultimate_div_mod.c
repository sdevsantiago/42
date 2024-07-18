/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:19:59 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/18 20:39:31 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Calculates the quotient and the remainder of the division of two integers.
	- #### Parameters
	-	int a: The dividend and where to store the quotient of the division
	-	int b: The divisor and where to store the remainder of the division
*/
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a /= *b;
	*b = aux % *b;
}

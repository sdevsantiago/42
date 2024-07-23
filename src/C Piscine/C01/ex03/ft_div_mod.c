/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:15:14 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/18 20:37:57 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Calculates the quotient and the remainder of the division of two integers.
	- #### Parameters
	-	int a: The dividend
	-	int b: The divisor
	-	int *div: Where to store the quotient of the division
	-	int *mod: Where to store the remainder of the division
*/
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

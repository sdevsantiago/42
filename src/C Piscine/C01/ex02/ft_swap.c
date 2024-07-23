/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 10:52:08 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/18 20:49:10 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Swaps the values of two variables.
	- #### Parameters
	-	int *a: One variable to swap
	-	int *b: The other variable to swap
*/
void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

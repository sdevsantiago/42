/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:16:34 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/10 21:43:29 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Obtains the factorial of a positive or null integer.
	- #### Parameters
	-	int nb: The number to obtain the factorial
	- #### Return
	-	The factorial of the number passed, if negative, returns 0.
*/
int	ft_iterative_factorial(int nb)
{
	int	res;
	
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	res = nb;
	while (nb > 1)
	{
		res *= nb - 1;
		nb--;
	}
	return (res);
}

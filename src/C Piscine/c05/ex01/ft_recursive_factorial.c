/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:27:19 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/10 21:41:47 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Obtains the factorial of a positive or null integer.
	- #### Parameters
	-	int nb: The number to obtain the factorial
	- #### Return
	-	The factorial of the number passed, if negative, returns 0.
*/
int	ft_recursive_factorial(int nb)
{
	int	res;
	
	if (nb == 0)
		return (1);
	else if (nb < 0)
		return (0);
	res = nb;
	return (nb * ft_recursive_factorial(nb - 1));
}

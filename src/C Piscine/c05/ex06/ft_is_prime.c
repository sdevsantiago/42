/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 15:39:06 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/15 16:25:10 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Evaluates if the number passed is prime or not.
	- #### Parameters
	-	int	nb:	The number to evaluate
	- #### Return
	-	Returns 0 if the number is not prime or if it's lower or equal to 1,
		else, returns 1.
*/
int	ft_is_prime(int nb)
{
	int	i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i < nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

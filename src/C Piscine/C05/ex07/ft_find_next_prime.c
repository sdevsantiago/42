/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 16:23:32 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/25 08:25:45 by sede-san         ###   ########.fr       */
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

	if (nb <= 1)
		return (0);
	i = 2;
	while (i <= nb / 2)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
	Finds the next prime to 'nb'.
	- #### Parameters
	-	int nb: The number passed
	- #### Return
	-	Returns the next prime number, unless it's bigger than the integer
		range, in which case returns the number passed.
*/
int	ft_find_next_prime(int nb)
{
	while (!ft_is_prime(nb))
		nb++;
	return (nb);
}

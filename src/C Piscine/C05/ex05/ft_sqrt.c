/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 02:06:30 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/25 08:14:23 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Calculates a nb elevated to power.
	- #### Parameters
	-	int nb: Base number
	-	int	power: Power to elevate
	- #### Return
	-	The number elevated to power.
*/
int	ft_recursive_power(int nb, int power)
{
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	return (nb * ft_recursive_power(nb, power - 1));
}

/*
	Calculates the integer square root of the number passed.
	- #### Parameters
	-	int nb: The number to calculate it's square root
	- #### Return
	-	Returns 0 if the square root is not an integer, else, returns its
		square root.
*/
int	ft_sqrt(int nb)
{
	int	i;

	if (nb <= 0)
		return (0);
	i = 1;
	while (ft_recursive_power(i, 2) < nb)
		i++;
	if (i * i == nb)
		return (i);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 23:45:31 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/11 00:08:37 by sede-san         ###   ########.fr       */
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
int	ft_iterative_power(int nb, int power)
{
	int	n;

	n = nb;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power > 1)
	{
		nb = nb * n;
		power--;
	}
	return (nb);
}

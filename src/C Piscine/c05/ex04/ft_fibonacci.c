/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 01:41:05 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/15 01:41:05 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	Calculates the value in the index passed position in the fibonacci sequence.
	- #### Parameters
	-	int index: The position to get the value from
	- #### Return
	-	Returns -1 if the index passed is negative, the index if it's lower or
		equal to 1 and value in the index-th position in each other case.
*/
int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index <= 1)
		return (index);	
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

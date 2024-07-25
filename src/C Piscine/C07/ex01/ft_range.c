/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:31:17 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/25 15:06:41 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
	Creates an array with the values between 'min' and 'max', this last one
	excluded.
	- #### Special cases
	-	If 'min' is higher or equal than 'max', an empty pointer is returned.
	- #### Parameters
	-	int min: The minimum number
	-	int max: The maximum number excluded
	- #### Returns
	-	Returns an integer array with the values from 'min' to 'max'.
*/
int	*ft_range(int min, int max)
{
	const int	range = max - min;
	int			*arr;
	int			i;

	if (!range)
		return (0);
	arr = malloc(sizeof(int) * range);
	i = 0;
	while (i < range)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

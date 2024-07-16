/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 11:31:17 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/16 11:53:04 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*
	Creates an array with the values between 'min' and 'max', this last one
	excluded.
	- #### Special cases
	-	If 'min' is higher than 'max', an empty pointer is returned.
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

	arr = malloc(sizeof(range));
	i = 0;
	while (i < range)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}
#include <stdio.h>
int	main(void)
{
	int	*arr = ft_range(0, 10);
	for (int i = 0; i < 10; i++)
		printf("%d\n", arr[i]);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 05:57:47 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/25 06:07:31 by sede-san         ###   ########.fr       */
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

/*
	Sorts an integer array using the bubble sort algorithm.
	- #### Parameters
	-	int *tab: The array to sort
	-	int size: 'tab' size
*/
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
		else
			i++;
	}
}

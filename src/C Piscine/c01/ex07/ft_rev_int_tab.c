/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:14:53 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/07 16:02:35 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size / 2)
	{
		ft_swap(&tab[i], &tab[size - i - 1]);
		i++;
	}
}

// int main(void)
// {
// 	int	nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
// 	ft_rev_int_tab(nums, 10);
// 	int		i = 0;
// 	char	numero;
// 	while (i < 10)
// 	{
// 		printf("%d", nums[i]);
// 		numero = nums[i] + '0';
// 		write(1, &numero, 1);
// 		i++;
// 	}
// 	return 0;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:14:53 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/07 10:07:07 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	aux;

	i = 0;
	while (i <= (size / 2) - 1)
	{
		aux = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = aux;
		i++;
	}
}

int main(void)
{
	int	nums[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
	ft_rev_int_tab(nums, 10);
	int		i = 0;
	char	numero;
	while (nums[i] != '\0')
	{
		numero = nums[i] + '0';
		write(1, &numero, 1);
		i++;
	}
	return 0;
}

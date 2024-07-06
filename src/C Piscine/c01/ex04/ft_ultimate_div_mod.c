/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:19:59 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/04 20:11:19 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_ultimate_div_mod(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a /= *b;
	*b = aux % *b;
}

// int main(void)
// {
// 	int	a;
// 	int	b;

// 	a = 6;
// 	b = 3;
// 	ft_ultimate_div_mod(&a, &b);
// 	return 0;
// }

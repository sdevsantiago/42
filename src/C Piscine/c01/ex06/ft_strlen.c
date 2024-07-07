/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:13:56 by sede-san          #+#    #+#             */
/*   Updated: 2024/07/07 12:36:52 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
		i++;
	return (i);
}

// int main(void)
// {
// 	int length = ft_strlen("¡Hola mundo!");
// 	return 0;
// }

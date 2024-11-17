/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:25:18 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/15 09:53:09 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_putstr(char const *str)
{
	int	len;

	if (!str)
		return (0);
	len = 0;
	while (*str)
	{
		len += ft_printf_putchar(*str);
		str++;
	}
	return (len);
}

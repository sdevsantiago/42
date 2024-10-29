/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:23:51 by sede-san          #+#    #+#             */
/*   Updated: 2024/10/29 19:50:16 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		len;
	
	len = 0;
	while (*str)
	{
		if (*str == '%')
		{
			
		}
			ft_putchar(*str);
			len++;
	}
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:11:28 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/15 09:53:00 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_putptr(intptr_t const ptr)
{
	int		len;
	char	*ptr_str;

	if (!ptr)
		return (ft_printf_putstr("(nil)"));
	ptr_str = ft_ultoa_base((unsigned long int)ptr, "0123456789abcdef");
	len = ft_printf_putstr("0x");
	len += ft_printf_putstr(ptr_str);
	free(ptr_str);
	return (len);
}

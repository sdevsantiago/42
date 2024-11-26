/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:23:51 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/26 16:38:16 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_specifier(int const specifier, va_list args)
{
	int	len;

	if (specifier == 'c')
		len = ft_printf_putchar(va_arg(args, int));
	else if (specifier == 's')
		len = ft_printf_putstr(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		len = ft_printf_putint(va_arg(args, int));
	else if (specifier == 'u')
		len = ft_printf_putuint(va_arg(args, unsigned int));
	else if (specifier == 'p')
		len = ft_printf_putptr(va_arg(args, uintptr_t));
	else if (specifier == 'o')
		len = ft_printf_putuint_oct(va_arg(args, unsigned int));
	else if (specifier == 'x' || specifier == 'X')
		len = ft_printf_putuint_hex(va_arg(args, unsigned int), specifier);
	else if (specifier == '%')
		len = ft_printf_putchar('%');
	else
	{
		len = ft_printf_putchar('%');
		len += ft_printf_putchar(specifier);
	}
	return (len);
}

/* Formats a text and writes it in the standard output.  */
int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		len;

	va_start(args, format);
	len = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (!*format)
				return (-1);
			len += print_specifier(*format, args);
		}
		else
			len += ft_printf_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}

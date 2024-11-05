/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 17:23:51 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/05 21:11:20 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_printf_putchar(char const c)
{
	ft_putchar(c);
	return (1);
}

static int	ft_printf_putstr(char const *str)
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

static int	ft_printf_putnbr(int const n)
{
	int		len;
	char	*nb;

	nb = ft_itoa(n);
	if (!nb)
		return (0);
	len = ft_printf_putstr(nb);
	free(nb);
	return (len);
}

static int	ft_printf_putnbr_unsigned(unsigned int const n)
{
	int		len;
	char	*nb;

	nb = ft_uitoa(n);
	if (!nb)
		return (0);
	len = ft_printf_putstr(nb);
	free(nb);
	return (len);
}

// static int ft_printf_putptr(uintptr_t const ptr)
// {
// 	int		len;
// 	char	*ptr_hex;

// 	ptr_hex = //pasar ptr a hexadecimal	
// 	return (len);
// }

// static int	ft_printf_putnbr_hex(int n, char const *base)
// {

// }

/*
-	%p El puntero void * dado como argumento se imprime en formato hexadecimal.
-	%x Imprime un número hexadecimal (base 16) en minúsculas.
-	%X Imprime un número hexadecimal (base 16) en mayúsculas.
*/
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
			if (*format == 'c')
				len += ft_printf_putchar(va_arg(args, int));
			else if (*format == 's')
				len += ft_printf_putstr(va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
				len += ft_printf_putnbr(va_arg(args, int));
			else if (*format == 'u')
				len += ft_printf_putnbr_unsigned(va_arg(args, unsigned int));
			else if (*format == '%')
				len += ft_printf_putchar('%');
			else
				return (-1);
		}
		else
			len += ft_printf_putchar(*format);
		format++;
	}
	va_end(args);
	return (len);
}

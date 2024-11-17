/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 21:20:32 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/15 10:21:59 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf_putint(int const n)
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

int	ft_printf_putuint(unsigned int const n)
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

int	ft_printf_putuint_oct(unsigned int const n)
{
	int		len;
	char	*nb;

	nb = ft_uitoa_base(n, "01234567");
	if (!nb)
		return (0);
	len = ft_printf_putstr(nb);
	free(nb);
	return (len);
}


int	ft_printf_putuint_hex(unsigned int const n, int const specifier)
{
	int		len;
	char	*nb;

	if (ft_isupper(specifier))
		nb = ft_uitoa_base(n, "0123456789ABCDEF");
	else
		nb = ft_uitoa_base(n, "0123456789abcdef");
	if (!nb)
		return (0);
	len = ft_printf_putstr(nb);
	free(nb);
	return (len);
}

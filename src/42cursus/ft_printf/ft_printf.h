/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:21:23 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/26 14:27:48 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "Libft/libft.h"
# include <stdarg.h>
# include <stdint.h>

int	ft_printf(char const *format, ...);

/* Character/String types */
int	ft_printf_putchar(int const c);
int	ft_printf_putstr(char const *str);

/* Integer types */
int	ft_printf_putint(int const n);
int	ft_printf_putuint(unsigned int const n);
int	ft_printf_putuint_oct(unsigned int const n);
int	ft_printf_putuint_hex(unsigned int const n, int const specifier);

/* Memdir types */
int	ft_printf_putptr(uintptr_t const ptr);

#endif
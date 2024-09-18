/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 18:38:00 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/17 21:37:11 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	Erases the data in the n bytes of the memory location pointed to by s.
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:45:54 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/17 16:53:42 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Checks if the passed character is a control character.  */
int	ft_iscntrl(int c)
{
	return ((c >= 0 && c <= 31) || c == 127);
}

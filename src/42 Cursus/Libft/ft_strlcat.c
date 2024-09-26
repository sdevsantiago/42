/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 12:59:02 by sede-san          #+#    #+#             */
/*   Updated: 2024/09/26 20:01:36 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* Appends the NUL-terminated string SRC to the end of DST.  */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s;

	i = ft_strlen(dst);
	s = ft_strlen(src);
	if (size <= i)
		return (size + s);
	size -= i;
	dst += i;
	while (size-- > 1)
	{
		*dst = *src;
		dst++;
		src++;
	}
	*dst = '\0';
	return (i + s);
}

// #include <stdlib.h>
// #include <unistd.h>
// #include <bsd/string.h>

// void	ft_print_result(int n)
// {
// 	char c;

// 	if (n >= 10)
// 		ft_print_result(n / 10);
// 	c = n % 10 + '0';
// 	write (1, &c, 1);
// }

// int		main(int argc, const char *argv[])
// {
// 	char	*dest;
// 	int		arg;

// 	alarm(5);
// 	if (!(dest = (char *)malloc(sizeof(*dest) * 15)) || argc == 1)
// 		return (0);
// 	memset(dest, 0, 15);
// 	memset(dest, 'r', 6);
// 	if ((arg = atoi(argv[1])) == 1)
// 	{
// 		dest[11] = 'a';
// 		ft_print_result(ft_strlcat(dest, "lorem", 15));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 	}
// 	else if (arg == 2)
// 	{
// 		ft_print_result(ft_strlcat(dest, "", 15));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 	}
// 	else if (arg == 3)
// 	{
// 		dest[0] = '\0';
// 		dest[11] = 'a';
// 		ft_print_result(ft_strlcat(dest, "lorem ipsum", 15));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 	}
// 	else if (arg == 4)
// 	{
// 		dest[14] = 'a';
// 		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 	}
// 	else if (arg == 5)
// 	{
// 		dest[10] = 'a';
// 		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 0));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 	}
// 	else if (arg == 6)
// 	{
// 		dest[10] = 'a';
// 		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 1));
// 		write(1, "\n", 1);
// 		write(1, dest, 20);
// 	}
// 	else if (arg == 7)
// 	{
// 		char *src = "lorem ipsum dolor sit amet";
// 		memset(dest, 'r', 15);
// 		write(1, src, 27);
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 		write(1, "\n", 1);
// 		ft_print_result(ft_strlcat(dest, src, 5));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 	}
// 	else if (arg == 8)
// 	{
// 		dest[10] = 'a';
// 		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 6));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 	}
// 	else if (arg == 9)
// 	{
// 		memset(dest, 'r', 14);
// 		ft_print_result(ft_strlcat(dest, "lorem ipsum dolor sit amet", 15));
// 		write(1, "\n", 1);
// 		write(1, dest, 15);
// 	}
// 	return (0);
// }

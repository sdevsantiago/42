/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_get_next_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:34:41 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/14 10:44:51 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


int main(int argc, char **argv)
{
	int		f;
	char*	line;

	if (argc != 2)
	{
		printf("ERROR. Invalid number of arguments");
		return (1);
	}
	f = open(argv[1], O_RDONLY);
 	while ((line = get_next_line(f)))
	{
		printf("%s", line);
		free(line);
	}

	close(f);
	return (0);
}
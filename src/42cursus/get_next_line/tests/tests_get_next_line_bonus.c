/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_get_next_line_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:34:41 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/14 10:44:50 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>


int main(int argc, char **argv)
{
	int		f1;
	int		f2;
	int		f3;
	unsigned int c;
	char*	line;

	if (argc != 4)
	{
		printf("ERROR. Invalid number of arguments (must include 3 files)");
		return (1);
	}
	
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[2], O_RDONLY);
	f3 = open(argv[3], O_RDONLY);
 	
	c = 0;
	while (c < 10)
	{
		line = get_next_line(f1);
		if (!line)
			break;
		printf("%s", line);
		free(line);
		c++;
	}
	printf("\n");
	
	c = 0;
	while (c < 10)
	{
		line = get_next_line(f2);
		if (!line)
			break;
		printf("%s", line);
		free(line);
		c++;
	}
	printf("\n");
	c = 0;
	while (c < 10)
	{
		line = get_next_line(f3);
		if (!line)
			break;
		printf("%s", line);
		free(line);
		c++;
	}
	printf("\n");
	
	close(f1);
	close(f2);
	close(f3);
	return (0);
}


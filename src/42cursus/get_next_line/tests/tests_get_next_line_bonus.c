/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_get_next_line_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:34:41 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/14 11:25:00 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN_TEXT "\033[32m"

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
	printf(BOLD GREEN_TEXT"FILE 1\n"RESET);
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
	printf(BOLD GREEN_TEXT"FILE 2\n"RESET);
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
	printf(BOLD GREEN_TEXT"FILE 3\n"RESET);
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


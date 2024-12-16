/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_get_next_line_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 12:34:41 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/16 23:11:11 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define GREEN_TEXT "\033[32m"
#define RED_TEXT "\033[31m"

int main(int argc, char **argv)
{
	int		f1;
	int		f2;
	int		f3;
	unsigned int c1;
	unsigned int c2;
	unsigned int c3;
	char*	line;

	if (argc != 4)
	{
		printf("ERROR. Invalid number of arguments (must include 3 files)");
		return (1);
	}

	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[2], O_RDONLY);
	f3 = open(argv[3], O_RDONLY);

	c1 = 0;
	printf(BOLD GREEN_TEXT"FILE 1\n"RESET);
	while (c1 < 10)
	{
		line = get_next_line(f1);
		if (!line)
		{
			printf(BOLD RED_TEXT"NO LINE RETURNED"RESET"\n");
			break;
		}
		printf("[%i]:\t%s", ++c1, line);
		free(line);
	}
	printf("\n");

	c2 = 0;
	printf(BOLD GREEN_TEXT"FILE 2\n"RESET);
	while (c2 < 10)
	{
		line = get_next_line(f2);
		if (!line)
		{
			printf(BOLD RED_TEXT"NO LINE RETURNED"RESET"\n");
			break;
		}
		printf("[%i]:\t%s", ++c2, line);
		if (!ft_strchr(line, EOL))
			printf("\n");
		free(line);
	}
	printf("\n");

	c3 = 0;
	printf(BOLD GREEN_TEXT"FILE 3\n"RESET);
	while (c3 < 10)
	{
		line = get_next_line(f3);
		if (!line)
		{
			printf(BOLD RED_TEXT"NO LINE RETURNED"RESET"\n");
			break;
		}
		printf("[%i]:\t%s", ++c3, line);
		if (!ft_strchr(line, EOL))
			printf("\n");
		free(line);
	}
	printf("\n");

	printf(BOLD GREEN_TEXT"FILE 1 (AGAIN)\n"RESET);
	while (c1 < 20)
	{
		line = get_next_line(f1);
		if (!line)
		{
			printf(BOLD RED_TEXT"NO LINE RETURNED"RESET"\n");
			break;
		}
		printf("[%i]:\t%s", ++c1, line);
		if (!ft_strchr(line, EOL))
			printf("\n");
		free(line);
	}
	printf("\n");

	printf(BOLD GREEN_TEXT"FILE 2 (AGAIN)\n"RESET);
	while (c2 < 20)
	{
		line = get_next_line(f2);
		if (!line)
		{
			printf(BOLD RED_TEXT"NO LINE RETURNED"RESET"\n");
			break;
		}
		printf("[%i]:\t%s", ++c2, line);
		if (!ft_strchr(line, EOL))
			printf("\n");
		free(line);
	}
	printf("\n");

	printf(BOLD GREEN_TEXT"FILE 3 (AGAIN)\n"RESET);
	while (c3 < 20)
	{
		line = get_next_line(f3);
		if (!line)
		{
			printf(BOLD RED_TEXT"NO LINE RETURNED"RESET"\n");
			break;
		}
		printf("[%i]:\t%s", ++c3, line);
		if (!ft_strchr(line, EOL))
			printf("\n");
		free(line);
	}
	printf("\n");

	printf(BOLD GREEN_TEXT"FILE 1 (REST OF FILE)\n"RESET);
	while ((line = get_next_line(f1)))
	{
		printf("[%i]:\t%s", ++c1, line);
		if (!ft_strchr(line, EOL))
			printf("\n");
		free(line);
	}
	if (!line)
		printf(BOLD RED_TEXT"NO LINE RETURNED"RESET"\n");
	printf("\n");

	printf(BOLD GREEN_TEXT"FILE 2 (REST OF FILE)\n"RESET);
	while ((line = get_next_line(f2)))
	{
		printf("[%i]:\t%s", ++c2, line);
		if (!ft_strchr(line, EOL))
			printf("\n");
		free(line);
	}
	if (!line)
		printf(BOLD RED_TEXT"NO LINE RETURNED"RESET"\n");
	printf("\n");

	printf(BOLD GREEN_TEXT"FILE 3 (REST OF FILE)\n"RESET);
	while ((line = get_next_line(f3)))
	{
		printf("[%i]:\t%s", ++c3, line);
		if (!ft_strchr(line, EOL))
			printf("\n");
		free(line);
	}
	if (!line)
		printf(BOLD RED_TEXT"NO LINE RETURNED"RESET"\n");
	printf("\n");

	close(f1);
	close(f2);
	close(f3);
	return (0);
}


	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:57 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/21 08:18:50 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//! DELETE AFTER TESTING
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define RESET "\033[0m"

#include "get_next_line.h"

// char *_fill_line()

/* Reads the next line from the file pointed by FD. */
//TODO	Reuse *remaining when BUFFER_SIZE is too big
char	*get_next_line(int fd)
{
	char				*line;
	static char			*remaining;
	char				*buffer;
	ssize_t				len;
	ssize_t				i;

	if (fd < STDIN_FILENO)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	len = read(fd, buffer, BUFFER_SIZE);
	if (len <= 0)
		return (NULL);
	buffer[len] = '\0';
	if (remaining)
		buffer = ft_strjoin(remaining, buffer);
	i = 0;
	while (buffer[i] && buffer[i] != EOL)
		i++;
	if (i >= len && buffer[i] != EOL && buffer[i])
	{
		remaining = (char *)malloc((len + 1) * sizeof(char));
		ft_strlcpy(remaining, buffer, i + 1);
		return (get_next_line(fd));
	}
	if (i > len)
	{
		remaining = (char *)malloc((i - len + 1) * sizeof(char));
		ft_strlcpy(remaining, &buffer[i + 1], len - i + 1);
	}
	else
	{
		remaining = (char *)malloc((len - i + 1) * sizeof(char));
		ft_strlcpy(remaining, &buffer[i + 1], i - len + 1);
	}
	line = (char *)malloc((i + 1) * sizeof(char));
	ft_strlcpy(line, buffer, i + 2);
	return (line);
}

#include <fcntl.h>
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
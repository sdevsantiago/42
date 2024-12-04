/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:57 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/04 21:51:09 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*  */
//!FIX	malloc(): corrupted top size
char	*_realloc_remaining(char *remaining, ssize_t start)
{
	char	*res_remaining;
	size_t	len;

	len = ft_strlen(&remaining[start]);
	res_remaining = (char *)malloc(len * sizeof(char));
	if (!res_remaining)
		return (NULL);
	ft_strlcpy(res_remaining, &remaining[start], len + 1);
	free(remaining);
	return (res_remaining);
}

//TODO char *_fill_line()

/* Reads the next line from the file pointed by FD. */
char	*get_next_line(int fd)
{
	char				*line;
	static char			*remaining;
	char				*buffer;
	ssize_t				len;
	ssize_t				i;

 	if (fd < STDIN_FILENO)
		return (NULL);
	if (remaining)		// check if remaining contains a newline
	{
		i = 0;
		while (remaining[i] && remaining[i] != EOL)
			i++;
		if (remaining[i] == EOL)
		{
			line = (char *)malloc((i + 1) * sizeof(char));
			if (!line)
				return (NULL);
			ft_strlcpy(line, remaining, i + 2);
			remaining = _realloc_remaining(remaining, i + 1);
			return (line);
		}
	}
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
		return (free(buffer), get_next_line(fd));
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
	return (free(buffer), line);
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
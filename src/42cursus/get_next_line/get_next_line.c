/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:57 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/10 18:17:19 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* */
static char	*_realloc_remaining(char *remaining, ssize_t start)
{
	char	*res_remaining;
	size_t	len;

	len = ft_strlen(&remaining[start]);
	res_remaining = ft_substr(remaining, start, len);
	if (!res_remaining)
		return (NULL);
	free(remaining);
	return (res_remaining);
}

// static char	*_realloc_line(char *line, size_t len)
// {
// 	char	*res_line;

// 	res_line = ft_substr(line, 0, len);
// 	if (!res_line)
// 		return (NULL);
// 	free(line);
// 	return (res_line);
// }

//TODO char *_fill_line()

/* Reads the next line from the file pointed by FD. */
char	*get_next_line(int fd)
{
	char				*line;
	static char			*remaining;
	char				*buffer;
	ssize_t				len;

	if (fd < STDIN_FILENO)
		return (NULL);
	if (remaining && ft_strchr(remaining, EOL))
	{
		len = (uintptr_t)ft_strchr(remaining, EOL) - (uintptr_t)remaining;
		line = ft_substr(remaining, 0, len + 1);
		remaining = _realloc_remaining(remaining, len + 1);
		return (line);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	len = read(fd, buffer, BUFFER_SIZE);
	if (len <= 0 && !remaining)
		return (free(buffer), NULL);
	else if (len == 0 && remaining)
	{
		line = ft_substr(remaining, 0, ft_strlen(remaining));
		free(remaining);
		remaining = NULL;
		return (free(buffer), line);
	}
	buffer[len] = '\0';
	if (!remaining)
	{
		remaining = (char *)malloc(1 * sizeof(char));
		*remaining = '\0';
	}
	remaining = ft_strjoin(remaining, buffer);
	free(buffer);
	if (!(ft_strchr(remaining, EOL)))
		return (get_next_line(fd));
	len = (uintptr_t)ft_strchr(remaining, EOL) - (uintptr_t)remaining;
	line = ft_substr(remaining, 0, len + 1);
	remaining = _realloc_remaining(remaining, len + 1);
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
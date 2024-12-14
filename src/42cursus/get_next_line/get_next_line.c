/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:57 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/14 13:31:53 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Resizes the buffer removing the line contained. If emptied, the buffer is
   freed and its node is deleted from the list FILES. */
static char	*_realloc_buffer(char *buffer)
{
	char		*new_buffer;
	size_t		len;
	uintptr_t	i;

	i = (uintptr_t)ft_strchr(buffer, EOL);
	if (i)
	{
		i -= (uintptr_t)buffer;
		len = ft_strlen(&buffer[i + 1]);
	}
	else
		len = ft_strlen(buffer);
	if ((i || buffer[i] == EOL) && buffer[i + 1])
		new_buffer = ft_substr(buffer, i + 1, len + 1);
	else
		new_buffer = NULL;
	free(buffer);
	return (new_buffer);
}

/* Fills the buffer until it contains a full line. A complete line is
   understood to be one that contains an EOL. */
static char	*_fill_buffer(int fd, char *buffer)
{
	char	*buf;
	ssize_t	len;

	buf = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (free(buffer), NULL);
	len = read(fd, buf, BUFFER_SIZE);
	if (len <= 0)
	{
		if (buffer)
			return (free(buf), buffer);
		return (free(buf), free(buffer), NULL);
	}
	buf[len] = '\0';
	if (!ft_strchr(buf, EOL) && len == BUFFER_SIZE)
	{
		buffer = ft_strjoin(buffer, buf);
		return (free(buf), _fill_buffer(fd, buffer));
	}
	buffer = ft_strjoin(buffer, buf);
	if (!buffer)
		return (free(buffer), NULL);
	return (free(buf), buffer);
}

/* Reads the next line from the file pointed by FD. If no lines have been read
   previously, reads the first one. */
char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer;
	size_t		len;

	if (fd < STDIN_FILENO || BUFFER_SIZE < 1)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	len = (uintptr_t)ft_strchr(buffer, EOL);
	if (len)
	{
		len -= (uintptr_t)buffer;
		line = ft_substr(buffer, 0, len + 1);
		buffer = _realloc_buffer(buffer);
		return (line);
	}
	buffer = _fill_buffer(fd, buffer);
	if (!buffer || !*buffer)
		return (free(buffer), NULL);
	len = (uintptr_t)ft_strchr(buffer, EOL) - (uintptr_t)buffer;
	line = ft_substr(buffer, 0, len + 1);
	buffer = _realloc_buffer(buffer);
	return (line);
}

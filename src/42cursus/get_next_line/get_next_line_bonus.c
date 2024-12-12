/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:57 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/12 12:33:07 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* */
static char	*_realloc_buffer(char *buffer)
{
	char		*new_buffer;
	size_t		len;
	uintptr_t	i;

	i = (uintptr_t)ft_strchr(buffer, EOL);
	if (i)
		i -= (uintptr_t)buffer;
	len = ft_strlen(&buffer[i]);
	if (i || buffer[i] == EOL)
		new_buffer = ft_substr(buffer, i + 1, len + 1);
	else
		new_buffer = NULL;
	free(buffer);
	return (new_buffer);
}

/* */
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
	return (free(buf), buffer);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[MAX_FD];
	size_t		len;

	if (fd < STDIN_FILENO || BUFFER_SIZE < 1)
		return (NULL);
	if (!buffer[fd])
		buffer[fd] = ft_strdup("");
	if (ft_strchr(buffer[fd], EOL))
	{
		len = (uintptr_t)ft_strchr(buffer[fd], EOL) - (uintptr_t)buffer[fd];
		line = ft_substr(buffer[fd], 0, len + 1);
		buffer[fd] = _realloc_buffer(buffer[fd]);
		return (line);
	}
	buffer[fd] = _fill_buffer(fd, buffer[fd]);
	if (!buffer[fd] || !*buffer[fd])
		return (free(buffer[fd]), NULL);
	len = (uintptr_t)ft_strchr(buffer[fd], EOL) - (uintptr_t)buffer;
	line = ft_substr(buffer[fd], 0, len + 1);
	buffer[fd] = _realloc_buffer(buffer[fd]);
	return (line);
}
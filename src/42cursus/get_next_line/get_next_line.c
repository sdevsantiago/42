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

#include "get_next_line.h"

/* Reads the next line from the file pointed by FD. */
char	*get_next_line(int fd)
{
	char				*line;
	static char			*remaining;
	char				*buffer;
	ssize_t				len;
	ssize_t				i;

	if (fd < STDIN_FILENO || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + ft_strlen(remaining) + 1) * sizeof(char));
	len = read(fd, buffer, BUFFER_SIZE);
	if (len <= 0)
		return (free(buffer), NULL);
	if (ft_strlen(remaining))
		buffer = ft_strjoin(remaining, buffer);
	i = 0;
	while (i < len && (buffer[i] != EOL && buffer[i] != EOF))
		i++;
	if (i < len)
	{
		remaining = (char *)malloc((ft_strlen(&buffer[i]) + 1) * sizeof(char));
		ft_strlcpy(remaining, &buffer[i], ft_strlen(&buffer[i]));
	}
	if (i == len)
		line = ft_strjoin(buffer, get_next_line(fd));
	return (free(buffer), line);
}

#include <fcntl.h>
int main(void)
{
	int		f = open("file.txt", O_RDONLY);
	char*	line;

	while ((line = get_next_line(f)))
	{
		printf("%s", line);
	}
		free(line);
	
	close(f);
	
	
	return (0);
}
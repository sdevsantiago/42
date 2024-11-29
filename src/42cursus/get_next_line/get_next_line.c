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
	if (i >= len && buffer[i] != EOL)
	{
		remaining = (char *)malloc((len + 1) * sizeof(char));
		ft_strlcpy(remaining, buffer, i + 1);
		return (ft_strjoin(remaining, get_next_line(fd)));
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

	// if (i < len)	// Buffer contains character
	// {
	// 	line = (char *)malloc((i + 1) * sizeof(char));
	// 	ft_strlcpy(line, buffer, i + 2);	// (i+2) => Newline must be returned
	// 	if (buffer[i])
	// 	return (line);
	// }
	// remaining = calloc(len + 1, sizeof(char));
	// if (!remaining)
	// 	return (NULL);
	// ft_strlcpy(remaining, buffer, len + 1);

// 	if (!buffer)
// 		return (NULL);
// 	len = read(fd, buffer, BUFFER_SIZE);
// 	if (len <= 0)
// 		return (free(buffer), NULL);
// 	if (ft_strlen(remaining))
// 		buffer = ft_strjoin(remaining, buffer);
// 	i = 0;
// 	while (i < len && (buffer[i] != EOL && buffer[i] != EOF))
// 		i++;
// 	if (i < len)
// 	{
// 		remaining = (char *)malloc((ft_strlen(&buffer[i]) + 1) * sizeof(char));
// 		ft_strlcpy(remaining, &buffer[i], ft_strlen(&buffer[i]));
// 	}
// 	line = ft_strjoin(buffer, get_next_line(fd));
// 	return (free(buffer), line);
// }

#include <fcntl.h>
int main(void)
{
	int		f = open("tests/file.txt", O_RDONLY);
	char*	line;

	while ((line = get_next_line(f)))
	{
		printf("%s", line);
	}
		free(line);
	
	close(f);
	
	
	return (0);
}
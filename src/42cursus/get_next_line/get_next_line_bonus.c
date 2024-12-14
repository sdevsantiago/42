/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:57 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/14 14:59:38 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Deletes the node from the list FILES containing the passed FD. */
static void	_del_file(t_list **files, int fd)
{
	t_list	*lst;
	t_list	*prev_file;

	lst = *files;
	prev_file = NULL;
	while (lst && ((t_file_data *)lst->content)->fd != fd)
	{
		prev_file = lst;
		lst = lst->next;
	}
	if (!lst)
		return ;
	if (prev_file)
		prev_file->next = lst->next;
	else
		*files = lst->next;
	free(((t_file_data *)lst->content)->buffer);
	free(lst->content);
	free(lst);
}

/* Returns the node of the list FILES that contains the FD passed. If it
   doesn't exitst, creates a new node for that FD. */
static t_file_data	*_get_file_data(t_list **files, int fd)
{
	t_list	*file;
	t_list	*new_file;

	file = *files;
	while (file)
	{
		if (((t_file_data *)file->content)->fd == fd)
			return ((t_file_data *)file->content);
		file = file->next;
	}
	new_file = (t_list *)malloc(sizeof(t_list));
	if (!new_file)
		return (NULL);
	new_file->content = (t_file_data *)malloc(sizeof(t_file_data));
	if (!new_file->content)
		return (free(new_file), NULL);
	((t_file_data *)new_file->content)->fd = fd;
	((t_file_data *)new_file->content)->buffer = ft_strdup("");					// TODO: test functionality with NULL string, if it works, remove ft_strdup
	new_file->next = NULL;
	if (*files)
		file->next = new_file;
	else
		*files = new_file;
	return (new_file->content);
}

/* Resizes the buffer removing the line contained. */
static char	*_realloc_buffer(char *buffer, int fd, t_list *files)
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
	if (i || buffer[i] == EOL)
		new_buffer = ft_substr(buffer, i + 1, len + 1);
	else
	{
		new_buffer = NULL;
		_del_file(&files, fd);
	}
	return (new_buffer);
}

/* Fills the buffer until it contains a full line. A complete line is
   understood to be one that contains an EOL. */
static char	*_fill_buffer(int fd, char *buffer)
{
	char	*buf;																//TODO: test leaks with buf in stack
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
	char			*line;
	static t_list	*files;
	t_file_data		*file;
	size_t			len;

	if (fd < STDIN_FILENO || BUFFER_SIZE < 1)
		return (NULL);
	file = _get_file_data(&files, fd);
	len = (size_t)ft_strchr(file->buffer, EOL);
	if (len)
	{
		len -= (size_t)file->buffer;
		line = ft_substr(file->buffer, 0, len + 1);
		file->buffer = _realloc_buffer(file->buffer, fd, files);
		return (line);
	}
	file->buffer = _fill_buffer(fd, file->buffer);
	if (!file->buffer || !*file->buffer)
		return (NULL);
	len = ft_strchr(file->buffer, EOL) - file->buffer;
	line = ft_substr(file->buffer, 0, len + 1);
	file->buffer = _realloc_buffer(file->buffer, fd, files);
	return (line);
}

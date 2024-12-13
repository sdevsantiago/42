/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:57 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/13 23:56:59 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* Deletes the node from the list FILES containing the passed FD with the
   function DEL. */
static void	_del_file_buffer(t_gnl_file **files, int fd, void (*del)(void *))
{
    t_gnl_file	*lst;
    t_gnl_file	*prev_file;

    lst = *files;
	prev_file = NULL;
    while (lst && lst->fd != fd)
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
    if (lst->buffer)
        del(lst->buffer);
    free(lst);
}


/* Returns the buffer of a previously read file. If it hasn't been read,
   creates a new node. */
static t_gnl_file	*_get_file_buffer(t_gnl_file **files, int fd)
{
	t_gnl_file	*file;
	t_gnl_file	*new_file;

	file = *files;
	while (file)
	{
		if (file->fd == fd)
			return (file);
		if (!file->next)
			break ;
		file = file->next;
	}
	new_file = (t_gnl_file *)malloc(1 * sizeof(t_gnl_file));
	if (!new_file)
		return (NULL);
	new_file->fd = fd;
	new_file->buffer = ft_strdup("");
	new_file->next = NULL;
	if (file)
		file->next = new_file;
	else
		*files = new_file;
	return (new_file);
}

/* Resizes the buffer removing the line contained. If emptied, the buffer is
   freed and its node is deleted from the list FILES. */
static char	*_realloc_buffer(char *buffer, int fd, t_gnl_file *files)
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
		_del_file_buffer(&files, fd, free);
	}
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
	return (free(buf), buffer);
}

/* Reads the next line from the file pointed by FD. If no lines have been read
   previously, reads the first one. */
char	*get_next_line(int fd)
{
    char				*line;
    static t_gnl_file	*files;
    t_gnl_file			*file;
    size_t				len;

    if (fd < STDIN_FILENO || BUFFER_SIZE < 1)
        return (NULL);
    file = _get_file_buffer(&files, fd);
	len = (uintptr_t)ft_strchr(file->buffer, EOL);
    if (len)
    {
        len -= (uintptr_t)file->buffer;
        line = ft_substr(file->buffer, 0, len + 1);
        file->buffer = _realloc_buffer(file->buffer, fd, files);
        return (line);
    }
    file->buffer = _fill_buffer(fd, file->buffer);
    if (!file->buffer || !*file->buffer)
        return (NULL);
    len = (uintptr_t)ft_strchr(file->buffer, EOL) - (uintptr_t)file->buffer;
    line = ft_substr(file->buffer, 0, len + 1);
    file->buffer = _realloc_buffer(file->buffer, fd, files);
    return (line);
}

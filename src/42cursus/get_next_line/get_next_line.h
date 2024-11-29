/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:59 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/29 17:14:44 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Default buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// Check if BUFFER_SIZE is valid
# if BUFFER_SIZE <= 0
#  error "BUFFER_SIZE must be greater than 0"
# endif

# define EOL '\n'

# include <unistd.h>	// read
# include <stdlib.h>	// malloc, free
# include <stdio.h>

char	*get_next_line(int fd);

/*********************************** Utils ************************************/

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
char	*ft_strjoin(const char *s1, const char *s2);

#endif
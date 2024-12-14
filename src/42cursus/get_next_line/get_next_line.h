/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:59 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/14 10:43:45 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

// Default buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define EOL '\n'

# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

char	*get_next_line(int fd);

/*********************************** Utils ************************************/

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);

#endif
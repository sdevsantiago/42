/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:59 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/13 09:35:38 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

// Default buffer size
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# define EOL '\n'

# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <unistd.h>

char	*get_next_line(int fd);

/*********************************** Utils ************************************/

size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_substr(const char *s, unsigned int start, size_t len);

/*********************************** Bonus ************************************/

typedef struct s_gnl_file
{
	int					fd;
	char				*buffer;
	struct s_gnl_file	*next;
}						t_gnl_file;

#endif
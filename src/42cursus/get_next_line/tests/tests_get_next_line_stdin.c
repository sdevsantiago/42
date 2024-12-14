/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_get_next_line_stdin.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:40:18 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/14 10:44:43 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include <stdio.h>
#include <signal.h>

int main(void)
{
	char 			*line;
	unsigned int	count = 0;

    while (count++ < 5)
    {
		line = get_next_line(STDIN_FILENO);
        write(STDOUT_FILENO, line, ft_strlen(line));
        free(line);
        line = NULL;
    }

    return (0);
}
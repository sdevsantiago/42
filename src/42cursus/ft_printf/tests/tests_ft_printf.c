/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:43:19 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/05 21:41:04 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftprintf.h"

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define UNDERLINE "\033[4m"
#define	NO_UNDERLINE "\033[24m"
#define INVERTED "\033[7m"

#define BLACK_TEXT "\033[30m"
#define RED_TEXT "\033[31m"
#define GREEN_TEXT "\033[32m"
#define YELLOW_TEXT "\033[33m"
#define BLUE_TEXT "\033[34m"
#define MAGENTA_TEXT "\033[35m"
#define CYAN_TEXT "\033[36m"
#define WHITE_TEXT "\033[37m"

#define BLACK_BG "\033[40m"
#define RED_BG "\033[41m"
#define GREEN_BG "\033[42m"
#define YELLOW_BG "\033[43m"
#define BLUE_BG "\033[44m"
#define MAGENTA_BG "\033[45m"
#define CYAN_BG "\033[46m"
#define WHITE_BG "\033[47m"

#define CHECK_MARK GREEN_TEXT"✔"RESET
#define CROSS_MARK RED_TEXT"✘"RESET

int	main(void)
{
	int	len_o;
	int len_ft;
	
	printf("%s%2c%s%2c%s%2c%s%10c%sft_printf tester by sede-san%s%10c%s%2c%s%2c%s%2c%s\n\n", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ', BLACK_BG, ' ', UNDERLINE, NO_UNDERLINE, ' ', BLUE_BG, ' ', GREEN_BG, ' ', RED_BG, ' ', RESET);

	printf("%-55s", ">> Invalid format ==> % <==");
	len_ft = ft_printf("%");
	if (len_ft == -1)
		printf(CHECK_MARK);
	else
		printf(CROSS_MARK);
	printf("\n");
	for (int i = 0; i < 10; i++)
		printf("%s%2c%s%2c%s%2c", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ');
	printf(RESET"\n");
	return (0);
}
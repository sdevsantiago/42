/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:43:19 by sede-san          #+#    #+#             */
/*   Updated: 2024/11/26 17:53:13 by sede-san         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

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

int	print_result(int len_o, int len_ft)
{
	int	err;
	if (len_o == len_ft)
	{
		printf("Test OK "CHECK_MARK" (%d - %d)\n", len_o, len_ft);
		err = 0;
	}
	else
	{
		printf("Test KO "CROSS_MARK" (%d - %d)\n", len_o, len_ft);
		err = 1;
	}
	return (err);
}

int	main(void)
{
	int	len_o;
	int len_ft;
	int	err = 0;

	printf("%s%2c%s%2c%s%2c%s%10c%sft_printf tester by sede-san%s%10c%s%2c%s%2c%s%2c%s\n\n", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ', BLACK_BG, ' ', UNDERLINE, NO_UNDERLINE, ' ', BLUE_BG, ' ', GREEN_BG, ' ', RED_BG, ' ', RESET);
	fflush(stdout);

	printf("Test: no args\n");
	fflush(stdout);
	for (int i = 0; i < 10; i++)
		printf("%s%2c%s%2c%s%2c", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ');
	printf(RESET"\n");

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("Test string");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("Test string");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("abcdefghijklmnopqrstuvwxyz");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("abcdefghijklmnopqrstuvwxyz");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("ñÑçÇ");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("ñÑçÇ");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("ºª!|\"@·#$~<%%%&¬/=?\\^½");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("ºª!|\"@·#$~<%%%&¬/=?\\^½");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("test%%%www");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\twww");
	fflush(stdout);
	len_ft = ft_printf("test%%%ttt");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Test: char\n");
	fflush(stdout);
	for (int i = 0; i < 10; i++)
		printf("%s%2c%s%2c%s%2c", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ');
	printf(RESET"\n");

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%c", 'a');
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%c", 'a');
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%c", '$');
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%c", '$');
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Test: NULL pointer string\n");
	fflush(stdout);
	for (int i = 0; i < 10; i++)
		printf("%s%2c%s%2c%s%2c", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ');
	printf(RESET"\n");

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%s", NULL);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%s", NULL);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	if (err)
		printf(RED_TEXT"Detected errors in %d tests"RESET, err);
	else
		printf(GREEN_TEXT"Congrats!🎉 Your ft_printf seems to behave exactly as the original prinft. Beware of memory leaks!"RESET);
	printf("\n\n");
	fflush(stdout);

	for (int i = 0; i < 10; i++)
		printf("%s%2c%s%2c%s%2c", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ');
	printf(RESET"\n");
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests_ft_printf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sede-san <sede-san@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:43:19 by sede-san          #+#    #+#             */
/*   Updated: 2024/12/03 14:59:51 by sede-san         ###   ########.fr       */
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
		printf(GREEN_TEXT"Test OK "CHECK_MARK" (%d - %d)\n", len_o, len_ft);
		err = 0;
	}
	else
	{
		printf(RED_BG"Test KO "CROSS_MARK" (%d - %d)\n", len_o, len_ft);
		err = 1;
	}
	printf(RESET);
	return (err);
}

int	main(void)
{
	int	len_o;
	int len_ft;
	int	err = 0;

	for (int i = 0; i < 10; i++)
		printf("%s%2c%s%2c%s%2c", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ');
	printf(RESET"\n");

	printf("%s%2c%s%2c%s%2c%s%10c%sft_printf tester by sede-san%s%10c%s%2c%s%2c%s%2c%s\n", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ', BLACK_BG, ' ', UNDERLINE, NO_UNDERLINE, ' ', RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ', RESET);
	fflush(stdout);

	for (int i = 0; i < 10; i++)
		printf("%s%2c%s%2c%s%2c", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ');
	printf(RESET"\n");
	printf("Test: no args\n");
	fflush(stdout);

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
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("test%%%www");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%s", "");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%s", "");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	for (int i = 0; i < 10; i++)
		printf("%s%2c%s%2c%s%2c", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ');
	printf(RESET"\n");
	printf("Test: char\n");
	fflush(stdout);

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

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%%");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%%");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%%%");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%%%");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%%%&");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%%%&");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	for (int i = 0; i < 10; i++)
		printf("%s%2c%s%2c%s%2c", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ');
	printf(RESET"\n");
	printf("Test: NULL pointer string\n");
	fflush(stdout);

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

	for (int i = 0; i < 10; i++)
		printf("%s%2c%s%2c%s%2c", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ');
	printf(RESET"\n");
	printf("Test: strings\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%s", "This is a test string");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%s", "This is a test string");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%s", "This string contains rare characters: !#~?'¿¡ñÑÇ*");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%s", "This string contains rare characters: !#~?'¿¡ñÑÇ*");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("This test contains a null pointers and newlines\n%s\n%s", NULL, "this should be printed");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("This test contains a null pointers and newlines\n%s\n%s", NULL, "this should be printed");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	char *str = ft_strdup("Hello world, I come from a variable!");
	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%s", str);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%s", str);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	free(str);
	str = NULL;
	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("Now the variable has been freed here's the result => %s", str);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("Now the variable has been freed here's the result => %s", str);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("ÁÉÍÓÚáéíóúÑñ\n中文字符测试\n日本語のテスト\n한국어 테스트\nПривет мир");
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("ÁÉÍÓÚáéíóúÑñ\n中文字符测试\n日本語のテスト\n한국어 테스트\nПривет мир");
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);


	for (int i = 0; i < 10; i++)
		printf("%s%2c%s%2c%s%2c", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ');
	printf(RESET"\n");
	printf("Test: integers\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%d", 1234567);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%d", 1234567);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%d", -1234567);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%d", -1234567);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%i", 28423);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%i", 28423);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%d", INT_MAX);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%d", INT_MAX);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%i", INT_MIN);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%i", INT_MIN);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%d", 0);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%d", 0);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%x", INT_MAX);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%x", INT_MAX);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%X", UINT_MAX);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%X", UINT_MAX);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("(not required in subject) %o", INT_MIN);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("(not required in subject) %o", INT_MIN);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%u", INT_MAX);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%u", INT_MAX);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%u", INT_MIN);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%u", INT_MIN);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%u", UINT_MAX);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%u", UINT_MAX);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	for (int i = 0; i < 10; i++)
		printf("%s%2c%s%2c%s%2c", RED_BG, ' ', GREEN_BG, ' ', BLUE_BG, ' ');
	printf(RESET"\n");
	printf("Test: pointers\n");
	fflush(stdout);

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%p", NULL);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%p", NULL);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	int	n;
	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%p", &n);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%p", &n);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	char *str2 = (char *)malloc(1 * sizeof(char));
	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%p", str2);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%p", str2);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);
	free(str2);
	str2 = NULL;

	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%p", 1);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%p", 1);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);

	char *str3 = ft_strdup("Hello");
	t_list *list = ft_lstnew(str3);
	printf("Original printf:\t");
	fflush(stdout);
	len_o = printf("%p", list);
	fflush(stdout);
	printf("\n");
	fflush(stdout);
	printf("ft_printf:\t\t");
	fflush(stdout);
	len_ft = ft_printf("%p", list);
	printf("\n");
	fflush(stdout);
	err += print_result(len_o, len_ft);
	printf("\n");
	fflush(stdout);
	ft_lstclear(&list, free);
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